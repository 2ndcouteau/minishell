/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_set_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:53:00 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:09:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

void		cd_set_error(t_env **e, char *name, int nbr)
{
	D_PUTENDL("cd SET ERROR");
	(*e)->current_cmd->error_name = name;
	(*e)->current_cmd->error_nbr = nbr;
}
