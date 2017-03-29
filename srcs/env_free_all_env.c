/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free_all_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 00:25:11 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/04 04:20:01 by kaosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	env_free_cmd(t_cmd *command)
{
	if (command->line != NULL)
		free(command->line);
	command->line = NULL;
	command->split_line -= command->env_mark;
	ft_free_tab(command->split_line);
	command->error_name = NULL;
}

static void	env_free_historical(t_hist *tmp)
{
	if (tmp != NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		if (tmp->cmd != NULL)
		{
			env_free_cmd(tmp->cmd);
			free(tmp->cmd);
			tmp->cmd = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
}

void		env_free_all_env(t_env **e)
{
	t_hist	*tmp;

	if (*e != NULL)
	{
		while ((*e)->historical->next != NULL)
		{
			tmp = (*e)->historical->next;
			env_free_historical((*e)->historical);
			(*e)->historical = tmp;
		}
		env_free_historical((*e)->historical);
		(*e)->current_cmd = NULL;
		ft_free_tab((*e)->env);
		(*e)->env = NULL;
		ft_free_tab((*e)->original_env);
		(*e)->original_env = NULL;
		free(*e);
		*e = NULL;
	}
}
