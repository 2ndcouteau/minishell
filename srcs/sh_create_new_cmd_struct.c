/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_create_new_cmd_struct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:42:38 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/04 04:11:54 by kaosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

void		create_new_cmd_struct(t_env **e, char *command_line)
{
	if (command_line != NULL)
	{
		if (!((*e)->current_cmd = (t_cmd *)malloc(sizeof(t_cmd))))
			exit(EXIT_FAILURE);
		(*e)->current_cmd->line = ft_strdup(command_line);
		(*e)->current_cmd->size_line = ft_strlen(command_line);
		(*e)->current_cmd->split_line = ft_strsplit(command_line, ' ');
		(*e)->current_cmd->size_split_line =
	ft_tablen((*e)->current_cmd->split_line);
		(*e)->current_cmd->error_nbr = 0;
		(*e)->current_cmd->error_name = NULL;
		(*e)->current_cmd->env_mark = 0;
	}
}
