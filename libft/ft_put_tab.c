/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:44:09 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:37:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_tab(char **tab)
{
	int		cpt;

	cpt = 0;
	while (tab[cpt] != NULL)
		ft_putendl(tab[cpt++]);
}