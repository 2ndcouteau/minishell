/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_system_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:54:54 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/04 04:33:17 by kaosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	exec_fork(t_env **e)
{
	pid_t	father;
	int		status;
	char	*path;

	if ((father = fork()) == -1)
		exit(EXIT_FAILURE);
	if (father > 0)
	{
		D_PUTENDL("FATHER");
		signal(SIGINT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		waitpid(father, &status, 0);
	}
	if (father == 0)
	{
		D_PUTENDL("FILS");
		path = ft_memalloc(PATH_MAX);
		exec_check_path(e, &path);
		execve(path, (*e)->current_cmd->split_line, (*e)->env);
		path = ft_free_line(&path);
		path = NULL;
		env_free_all_env(e);
		kill(getpid(), SIGTERM);
	}
}

void		exec_system_cmd(t_env **e, char **av)
{
	if (e != NULL && av)
		exec_fork(e);
}
