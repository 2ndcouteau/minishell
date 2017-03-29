/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:54:18 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/04 04:29:49 by kaosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	exec_without_env(t_env **e)
{
	D_PUTENDL("exec_without_env");
	(*e)->current_cmd->split_line += 2;
	(*e)->current_cmd->size_split_line -= 2;
	(*e)->current_cmd->env_mark = 2;
	ft_free_tab((*e)->env);
	if (!((*e)->env = (char**)malloc(sizeof(char*))))
		exit(EXIT_FAILURE);
	(*e)->env[0] = NULL;
	sh_exec_command(e, (*e)->current_cmd->split_line);
	if (envreset_builtin(e))
		exit(EXIT_FAILURE);
	(*e)->current_cmd->env_mark = 0;
	(*e)->current_cmd->size_split_line += 2;
	(*e)->current_cmd->split_line -= 2;
}

static void	env_execve(t_env **e)
{
	if ((*e)->current_cmd->split_line[1][0] == '-')
	{
		if (!(ft_strncmp((*e)->current_cmd->split_line[1], "-i", 3)))
		{
			D_PUTENDL("ARG1 == -i");
			if ((*e)->current_cmd->split_line[2] != NULL)
				exec_without_env(e);
		}
		else
			sh_print_error(2, NULL);
	}
	else
	{
		D_PUTENDL("Same Environnement");
		(*e)->current_cmd->split_line += 1;
		(*e)->current_cmd->size_split_line -= 1;
		(*e)->current_cmd->env_mark = 1;
		sh_exec_command(e, (*e)->current_cmd->split_line);
		(*e)->current_cmd->env_mark = 0;
		(*e)->current_cmd->size_split_line += 1;
		(*e)->current_cmd->split_line -= 1;
	}
}

bool		env_builtin(t_env **e)
{
	int	cpt;

	cpt = 0;
	if ((*e)->env != NULL)
	{
		if ((*e)->current_cmd->split_line[1] != NULL)
			env_execve(e);
		else
		{
			while ((*e)->env[cpt] != NULL)
				ft_putendl((*e)->env[cpt++]);
		}
	}
	return (SUCCESS);
}
