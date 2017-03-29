/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:28:36 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/03 00:20:43 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static int	check_return_value(t_env **e)
{
	int		ret;

	ret = 0;
	if ((*e)->current_cmd->size_split_line > 1)
	{
		if (!(ft_isnumber((*e)->current_cmd->split_line[1])))
			ret = ft_atoi((*e)->current_cmd->split_line[1]);
		else
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd((*e)->current_cmd->split_line[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			ret = -1;
		}
	}
	return (ret);
}

bool		exit_builtin(t_env **e)
{
	int		ret_value;

	ret_value = check_return_value(e);
	free_all_env(e);
	exit(ret_value);
}
