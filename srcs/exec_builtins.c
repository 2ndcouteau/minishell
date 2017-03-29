/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:20:25 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 20:56:50 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

bool						(*g_builtins[NB_BUILTIN])(t_env **e) =
{
	cd_builtin,
	env_builtin,
	setenv_builtin,
	unsetenv_builtin,
	exit_builtin,
	envreset_builtin,
	history_builtin
};

static const char *const	g_builtins_name[NB_BUILTIN] = {
	"cd",
	"env",
	"setenv",
	"unsetenv",
	"exit",
	"envreset",
	"history"
};

static int					is_builtins(char *cmd_search, char const *full_name)
{
	if (cmd_search[0] == full_name[0])
		return (ft_strcmp(full_name, cmd_search));
	return (ERROR);
}

bool						exec_builtins(t_env **e)
{
	int		cpt;

	cpt = 0;
	while (cpt < NB_BUILTIN)
	{
		if (is_builtins((*e)->current_cmd->split_line[0],\
	g_builtins_name[cpt]) == 0)
		{
			if (g_builtins[cpt](e))
				return (ERROR);
			return (SUCCESS);
		}
		cpt++;
	}
	return (ERROR);
}
