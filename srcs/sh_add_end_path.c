/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_add_end_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:50:05 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:12:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

void		sh_add_end_path(char **current_pwd, char *add_elem, int pwd_len)
{
	int		cpt;

	cpt = 0;
	(*current_pwd)[pwd_len++] = '/';
	while (add_elem[cpt] != '\0')
	{
		(*current_pwd)[pwd_len] = add_elem[cpt];
		pwd_len++;
		cpt++;
	}
	(*current_pwd)[pwd_len] = '\0';
}
