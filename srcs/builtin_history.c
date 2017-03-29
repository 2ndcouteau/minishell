/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 22:05:35 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:00:06 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	history_print_index(unsigned int index)
{
	unsigned int	padding;

	padding = ft_nbrlen(HISTORICAL_LIMIT) - ft_nbrlen(index);
	while (padding > 0)
	{
		ft_putchar(' ');
		padding--;
	}
	ft_putnbr(index);
}

static void	history_print_list(t_hist *tmp, int cpt)
{
	while (tmp != NULL && cpt != 0)
	{
		history_print_index(tmp->index);
		ft_putchar(' ');
		ft_putendl(tmp->cmd->line);
		tmp = tmp->prev;
		cpt--;
	}
}

static void	history_set_print_position(t_hist **tmp, int cpt)
{
	int				pos;

	pos = 0;
	while ((*tmp)->next != NULL && pos != cpt)
	{
		*tmp = (*tmp)->next;
		pos++;
	}
}

static int	history_set_print_len(t_env **e, int cpt)
{
	if ((*e)->current_cmd->size_split_line > 1)
	{
		if (!(ft_isnumber((*e)->current_cmd->split_line[1])))
			cpt = ft_atoi((*e)->current_cmd->split_line[1]);
	}
	return (cpt);
}

bool		history_builtin(t_env **e)
{
	t_hist			*tmp;
	int				cpt;

	cpt = 10;
	tmp = (*e)->historical;
	cpt = history_set_print_len(e, cpt);
	history_set_print_position(&tmp, cpt);
	history_print_list(tmp, cpt);
	return (SUCCESS);
}
