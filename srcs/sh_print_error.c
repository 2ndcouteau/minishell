/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:26:36 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/03 21:30:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static const char *const	g_error_message[NB_ERROR] = {
	"\"minishell\" takes no arguments\n  --  Just use : ./minishell",
	"The shell has quit.\n -- Please restart the Shell -- ",
	"usage: env [-i] [utility [argument...]",
	"setenv: Variable name must begin with a letter.",
	"setenv: Variable name must contain alphanumeric characters."
};

void						sh_print_error(int error, char *name)
{
	D_PUTENDL("SH_PRINT_ERROR");
	if (error > 0 && error < NB_ERROR)
		ft_putendl_fd(g_error_message[error], 2);
	else if (error == -1)
	{
		ft_putstr_fd("Minishell: Command not found: ", 2);
		ft_putendl_fd(name, 2);
	}
}
