/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_create_path_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 08:34:44 by kaosu             #+#    #+#             */
/*   Updated: 2016/03/02 18:09:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	cd_read_argument(t_env **e, char **current_pwd, char *new_path)
{
	int		cpt;

	cpt = cd_check_new_path(new_path);
	if (cpt < 2)
	{
		if (cpt == 0)
			cd_relative_path(e, current_pwd, new_path);
		else
			cd_absolute_path(e, current_pwd, new_path);
	}
	else
	{
		if (cpt == 2)
			cd_home(e, current_pwd, new_path + 1);
		else
			cd_oldpwd(e, current_pwd);
	}
}

static void	no_name(t_env **e, char **current_pwd)
{
	int		home_pos;

	ft_bzero(*current_pwd, PATH_MAX);
	if ((home_pos = env_position_line(e, "HOME=", 5)) >= 0)
	{
		*current_pwd = ft_strcpy(*current_pwd, (*e)->env[home_pos] + 5);
		cd_check_valid_file(e, current_pwd, (*e)->env[home_pos] + 5);
	}
	else
		*current_pwd = ft_strcpy(*current_pwd, "/");
}

void		cd_create_path_name(t_env **e, t_opt **cd_opt, char **current_pwd)
{
	if (ft_strlen(*current_pwd) < (PATH_MAX - 1))
	{
		if ((*cd_opt)->nb_arg != 0)
			cd_read_argument(e, current_pwd, (*cd_opt)->s_arg[0]);
		else if ((*e)->current_cmd->size_split_line - (*cd_opt)->position != 0)
			cd_read_argument(e, current_pwd,
	(*e)->current_cmd->split_line[(*cd_opt)->position]);
		else
			no_name(e, current_pwd);
	}
	else
		cd_set_error(e, "", 1);
}
