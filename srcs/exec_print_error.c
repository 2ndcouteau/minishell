/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_print_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:50:27 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 20:56:16 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static const char *const g_exec_error_message[3] = {
	"",
	"Minishell: Command not found: ",
	"Minishell: Access Denied: ",
};

void		exec_print_error(int error, char *name)
{
	ft_putstr_fd(g_exec_error_message[error], 2);
	ft_putendl_fd(name, 2);
}
