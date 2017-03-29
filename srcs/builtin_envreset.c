/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_envreset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:52:27 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/03 17:59:04 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

bool	envreset_builtin(t_env **e)
{
	int	len;

	ft_free_tab((*e)->env);
	len = ft_tablen((*e)->original_env);
	if (!((*e)->env = (char**)malloc(sizeof(char*) * (len + 1))))
		return (ERROR);
	len = 0;
	while ((*e)->original_env[len] != NULL)
	{
		(*e)->env[len] = ft_strdup((*e)->original_env[len]);
		len++;
	}
	(*e)->env[len] = NULL;
	return (SUCCESS);
}
