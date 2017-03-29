/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_position_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 22:58:58 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:10:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

int		env_position_line(t_env **e, char *var_e, int len)
{
	int		cpt;

	cpt = 0;
	if ((*e)->env != NULL)
	{
		while ((*e)->env[cpt] != NULL)
		{
			if (ft_strncmp((*e)->env[cpt], var_e, len) == 0)
				return (cpt);
			cpt++;
		}
	}
	return (-1);
}
