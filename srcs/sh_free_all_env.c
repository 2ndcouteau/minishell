/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_free_all_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:40:20 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/04 00:25:34 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	ft_free_cmd(t_cmd *command)
{
	if (command->line != NULL)
		free(command->line);
	command->line = NULL;
	ft_free_tab(command->split_line);
	command->error_name = NULL;
}

void		free_historical(t_hist *tmp)
{
	if (tmp != NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		if (tmp->cmd != NULL)
		{
			ft_free_cmd(tmp->cmd);
			free(tmp->cmd);
			tmp->cmd = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
}

void		free_all_env(t_env **e)
{
	t_hist	*tmp;

	if (*e != NULL)
	{
		while ((*e)->historical->next != NULL)
		{
			tmp = (*e)->historical->next;
			free_historical((*e)->historical);
			(*e)->historical = tmp;
		}
		free_historical((*e)->historical);
		(*e)->current_cmd = NULL;
		ft_free_tab((*e)->env);
		(*e)->env = NULL;
		ft_free_tab((*e)->original_env);
		(*e)->original_env = NULL;
		free(*e);
		*e = NULL;
	}
}
