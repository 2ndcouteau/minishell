/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_create_new_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:40:11 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/04 04:10:49 by kaosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	init_struct_historical(t_env **e)
{
	if (!((*e)->historical = (t_hist *)malloc(sizeof(t_hist))))
		exit(EXIT_FAILURE);
	(*e)->historical->cmd = (*e)->current_cmd;
	(*e)->historical->index = 0;
	(*e)->historical->next = NULL;
	(*e)->historical->prev = NULL;
}

static void	save_env(t_env **e, char **env)
{
	int		len;

	len = ft_tablen(env) + 1;
	if (!((*e)->env = (char**)malloc(sizeof(char*) * len)))
		exit(EXIT_FAILURE);
	if (!((*e)->original_env = (char**)malloc(sizeof(char*) * len)))
		exit(EXIT_FAILURE);
	len = 0;
	while (env[len] != NULL)
	{
		(*e)->env[len] = ft_strdup(env[len]);
		(*e)->original_env[len] = ft_strdup(env[len]);
		len++;
	}
	(*e)->size_env = len;
	(*e)->env[len] = NULL;
	(*e)->original_env[len] = NULL;
}

static void	increase_shlvl(t_env **e)
{
	int		shlvl_pos;
	int		shlvl_value;
	char	*shlvl_char;

	if ((shlvl_pos = env_position_line(e, "SHLVL=", 6)) >= 0)
	{
		shlvl_value = ft_atoi((*e)->env[shlvl_pos] + 6);
		shlvl_value++;
		shlvl_char = ft_itoa(shlvl_value);
		env_replace_var((*e)->env, "SHLVL=", shlvl_char, shlvl_pos);
		shlvl_char = ft_free_line(&shlvl_char);
	}
	else
		setenv_var(e, "SHLVL", "1");
}

bool		create_new_env(t_env **e, char *command_line, char **env)
{
	if (!(*e = (t_env *)malloc(sizeof(t_env))))
		return (ERROR);
	save_env(e, env);
	create_new_cmd_struct(e, command_line);
	init_struct_historical(e);
	increase_shlvl(e);
	return (SUCCESS);
}
