/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 00:08:39 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:13:50 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

bool		sh_get_input(char **command_line)
{
	int		ret;

	ret = 1;
	ret = get_next_line(0, command_line);
	if (ret == -1 || *command_line == NULL)
		return (1);
	return (0);
}
