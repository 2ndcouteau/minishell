/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_list_push_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:40:12 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:12:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void		free_hist_last_elem(t_hist *hist)
{
	hist->prev->next = NULL;
	hist->prev = NULL;
	free_cmd_struct(hist->cmd);
	free(hist);
	hist = NULL;
}

static	void	free_last_elem(t_hist *hist)
{
	while (hist->index != 0)
	{
		hist->index -= 1;
		hist = hist->next;
	}
	free_hist_last_elem(hist);
}

void			list_push_front_hist_max(t_env **e)
{
	list_push_front_hist_struct(e);
	free_last_elem((*e)->historical);
}

void			list_push_front_hist_struct(t_env **e)
{
	t_hist	*tmp;

	if ((*e)->historical != NULL)
	{
		if (!(tmp = (t_hist *)malloc(sizeof(t_hist))))
			exit(EXIT_FAILURE);
		tmp->cmd = (*e)->current_cmd;
		tmp->index = (*e)->historical->index + 1;
		tmp->next = (*e)->historical;
		(*e)->historical->prev = tmp;
		(*e)->historical = tmp;
		(*e)->historical->prev = NULL;
		tmp = NULL;
	}
}
