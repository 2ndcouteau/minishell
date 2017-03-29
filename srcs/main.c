/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/02 18:10:28 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/minishell.h>

int			main(int ac, char **av, char **env)
{
	D_PUTENDL("DEBUG MODE ON");
	if (ac == 1 && av && env)
		sh_start_endless_loop(av, env);
	else
		sh_print_error(0, NULL);
	return (0);
}
