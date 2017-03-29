/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:16:48 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:10:21 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

void	free_cmd_struct(t_cmd *cmd_struct)
{
	int		cpt;

	cpt = 0;
	free(cmd_struct->line);
	while (cmd_struct->split_line[cpt] != NULL)
	{
		free(cmd_struct->split_line[cpt]);
		cmd_struct->split_line[cpt] = NULL;
		cpt++;
	}
	free(cmd_struct->split_line);
	cmd_struct->split_line = NULL;
	free(cmd_struct);
	cmd_struct = NULL;
}
