/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clean_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 05:38:29 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:08:56 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static int		cd_check_double_dote(char **tab, int cpt, int valid)
{
	tab[cpt] = ft_free_line(&tab[cpt]);
	tab[cpt] = NULL;
	while (tab[valid] == NULL && valid > 0)
		valid--;
	if (tab[valid] != NULL)
		tab[valid] = ft_free_line(&tab[valid]);
	return (valid);
}

static char		**cd_epure_line(char **current_pwd, int *len_tab)
{
	int		valid;
	int		cpt;
	char	**tab;

	valid = 0;
	cpt = 0;
	tab = ft_strsplit(*current_pwd, '/');
	while (tab[cpt] != NULL)
	{
		if (ft_strncmp(tab[cpt], "..", 3) == 0)
			valid = cd_check_double_dote(tab, cpt, valid);
		else if (ft_strncmp(tab[cpt], ".", 2) == 0)
			tab[cpt] = ft_free_line(&tab[cpt]);
		else
			valid = cpt;
		cpt++;
	}
	*len_tab = cpt;
	return (tab);
}

static void		cd_join_path(char **tab, char **current_pwd, int len_tab)
{
	int		cpt;
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	while (pos < len_tab)
	{
		cpt = 0;
		if (tab[pos] != NULL)
		{
			(*current_pwd)[line++] = '/';
			while ((tab[pos])[cpt] != '\0')
			{
				(*current_pwd)[line] = (tab[pos])[cpt];
				line++;
				cpt++;
			}
			tab[pos] = ft_free_line(&tab[pos]);
		}
		pos++;
	}
	if (line == 0)
		(*current_pwd)[line++] = '/';
	(*current_pwd)[line] = '\0';
}

void			cd_clean_path(char **current_pwd)
{
	char	**tab;
	int		len_tab;

	tab = cd_epure_line(current_pwd, &len_tab);
	ft_bzero(*current_pwd, PATH_MAX);
	cd_join_path(tab, current_pwd, len_tab);
	free(tab);
	tab = NULL;
}
