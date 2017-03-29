/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prepare_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:33:46 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:14:15 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	add_new_command(t_env **e, char *command_line)
{
	create_new_cmd_struct(e, command_line);
	if ((*e)->historical->index < HISTORICAL_LIMIT - 1)
		list_push_front_hist_struct(e);
	else
		list_push_front_hist_max(e);
}

void		prepare_cmd_line(t_env **e, char *command_line, char **env)
{
	if (*e == NULL)
	{
		if (create_new_env(e, command_line, env))
			exit(EXIT_FAILURE);
	}
	else
		add_new_command(e, command_line);
}
