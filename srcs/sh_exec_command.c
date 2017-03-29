/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:10:04 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:55:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

bool		sh_exec_command(t_env **e, char **av)
{
	if (exec_builtins(e) == 0)
		return (SUCCESS);
	else
		exec_system_cmd(e, av);
	return (SUCCESS);
}
