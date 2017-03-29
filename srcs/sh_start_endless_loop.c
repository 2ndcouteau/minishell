/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_start_endless_loop.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:41:31 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/03 21:07:26 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

static void	print_prompt(int sig)
{
	if (sig == SIGINT || sig == SIGTSTP)
	{
		ft_putchar('\n');
		ft_putstr(PROMPT);
	}
}

static bool	sh_parsing_std_enter(char **av, char **env, t_env **e)
{
	char	*command_line;

	command_line = NULL;
	ft_putstr(PROMPT);
	signal(SIGINT, print_prompt);
	signal(SIGTSTP, print_prompt);
	if (!sh_get_input(&command_line))
	{
		if (is_empty(command_line))
		{
			ft_free_line(&command_line);
			return (SUCCESS);
		}
		D_PUTENDL("Before prepare_cmd_line");
		prepare_cmd_line(e, command_line, env);
		ft_free_line(&command_line);
		sh_exec_command(e, av);
		return (SUCCESS);
	}
	else
	{
		ft_free_line(&command_line);
		sh_print_error(1, NULL);
		return (ERROR);
	}
}

void		sh_start_endless_loop(char **av, char **env)
{
	t_env	*e;

	e = NULL;
	while (1)
	{
		D_PUTENDL("Start new loop");
		if ((sh_parsing_std_enter(av, env, &e)))
			break ;
	}
}
