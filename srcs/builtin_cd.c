/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:47:44 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 17:49:28 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static char	**cd_init_define(void)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * 7)))
		return (NULL);
	tab[0] = ft_strdup("cd");
	tab[1] = ft_strdup("-LP");
	tab[2] = ft_strdup("");
	tab[3] = ft_strdup(" [-L|-P]");
	tab[4] = ft_strdup("");
	tab[5] = ft_strdup("[dir]");
	tab[6] = NULL;
	return (tab);
}

void		exec_cd(t_env **e, t_opt **cd_opt)
{
	char	*current_pwd;

	current_pwd = ft_memalloc(PATH_MAX);
	getcwd(current_pwd, PATH_MAX);
	D_PUTENDL("Create new path for chdir Start");
	cd_create_path_name(e, cd_opt, &current_pwd);
	D_PUTENDL("Chdir Start");
	if ((*e)->current_cmd->error_nbr != 0)
	{
		D_PUTENDL("ERROR WESH");
		cd_print_error((*e)->current_cmd->error_nbr,
	(*e)->current_cmd->error_name);
	}
	else
	{
		D_PUTENDL(current_pwd);
		chdir(current_pwd);
		cd_swap_pwd_env(e, &current_pwd, cd_opt);
	}
	current_pwd = ft_free_line(&current_pwd);
}

bool		cd_builtin(t_env **e)
{
	char	**cd_init;
	t_opt	*cd_opt;

	cd_init = cd_init_define();
	cd_opt = opt_parse_arguments((*e)->current_cmd->size_split_line,\
	(*e)->current_cmd->split_line, cd_init);
	if (cd_opt->mark != 2)
		exec_cd(e, &cd_opt);
	else
		opt_print_error((*e)->current_cmd->split_line, &cd_opt);
	opt_free(&cd_opt);
	return (SUCCESS);
}
