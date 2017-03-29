/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 22:36:45 by qrosa             #+#    #+#             */
/*   Updated: 2016/03/04 13:45:23 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <sys/types.h>
# include <limits.h>
# include <sys/stat.h>

/*
**	For wait(); function
*/
# include <sys/wait.h>

/*
**	For kill() and signal() functions;
*/
# include <signal.h>

# define ERROR 	1
# define SUCCESS 0

/*
**	****************************************
**	*********** CUSTOM VARIABLES ***********
**	****************************************
*/

/*
**	Prompt Definition.
*/
# define PROMPT "Minishell $$$>> "

/*
**	Historical Limit
**	$$ Can't be inferior to 1.
*/
# define HISTORICAL_LIMIT	500

/*
**	****************************************
**	****************************************
**	****************************************
*/

/*
**	*********** FIXED VARIABLES ************
*/
# define NB_BUILTIN			7
# define NB_ERROR			5

/*
**	***************
**	*** LEXIQUE ***
**	***************
**	*
**	cmd = command;
**	hist = historical;
**	nbr = number;
**	*
**	***************
*/

/*
**	Current Command Line Structure
*/
typedef struct		s_cmd
{
	char			*line;
	unsigned int	size_line;
	char			**split_line;
	size_t			size_split_line;
	unsigned int	*pos_cmd;
	size_t			error_nbr;
	char			*error_name;
	int				env_mark;
}					t_cmd;

/*
**	Historical Session Structure
*/
typedef struct		s_hist
{
	unsigned int	index;
	struct s_cmd	*cmd;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

/*
**	Global Environnement Structure
*/
typedef struct		s_env
{
	struct s_hist	*historical;
	struct s_cmd	*current_cmd;
	int				size_env;
	char			**env;
	char			**original_env;
}					t_env;

/*
**	Tableau de pointeur sur fonction
*/
bool				(*g_builtins[NB_BUILTIN])(t_env **e);

/*
**	Principals Functions
*/
int					main(int ac, char **av, char **env);
void				sh_start_endless_loop(char **av, char **env);
bool				sh_exec_command(t_env **e, char **av);

/*
**	General Functions
*/
char				check_typefile(mode_t mode);
void				sh_add_end_path(char **current_pwd, char *add_elem,
	int pwd_len);

/*
**	Historical Functions
*/
void				list_push_front_hist_struct(t_env **e);
void				list_push_front_hist_max(t_env **e);

/*
**	Input Functions
*/
bool				sh_get_input(char **command_line);
bool				is_empty(char *line);
void				prepare_cmd_line(t_env **e, char *command_line, char **env);
bool				create_new_env(t_env **e, char *command_line, char **env);
void				create_new_cmd_struct(t_env **e, char *command_line);
bool				create_path_name(t_env **e, t_opt **cd_opt,
	char **current_pwd);

/*
**	System Exec Command
*/
void				exec_system_cmd(t_env **e, char **av);
bool				exec_check_path(t_env **e, char **path);

/*
**	Builtins
*/
bool				exec_builtins(t_env **e);
bool				cd_builtin(t_env **e);
bool				env_builtin(t_env **e);
bool				setenv_builtin(t_env **e);
bool				unsetenv_builtin(t_env **e);
bool				exit_builtin(t_env **e);
bool				envreset_builtin(t_env **e);
bool				history_builtin(t_env **e);

/*
**	Env Functions
*/
int					env_position_line(t_env **e, char *var_e, int len);
void				env_replace_var(char **env, char *variable, char *value,
	int position);

/*
**	Setenv Functions
*/
int					setenv_var(t_env **e, char *var_env, char *value);

/*
**	CD Builtins Functions
*/
void				cd_create_path_name(t_env **e, t_opt **cd_opt,
	char **current_pwd);
bool				cd_check_valid_file(t_env **e, char **current_pwd,
	char *name);
void				cd_set_error(t_env **e, char *name, int nbr);
int					cd_check_new_path(char *new_path);
void				cd_oldpwd(t_env **e, char **current_pwd);
void				cd_home(t_env **e, char **current_pwd, char *new_path);
void				cd_relative_path(t_env **e, char **current_pwd,
	char *new_path);
void				cd_absolute_path(t_env **e, char **current_pwd,
	char *new_path);
void				cd_swap_pwd_env(t_env **e, char **current_pwd,
	t_opt **cd_opt);
void				cd_clean_path(char **current_pwd);

/*
**	Free Functions
*/
void				free_cmd_struct(t_cmd *cmd_struct);
void				free_historical(t_hist *tmp);
void				free_all_env(t_env **e);
void				env_free_all_env(t_env **e);

/*
**	Print Error Functions
*/
void				sh_print_error(int error, char *name);
void				exec_print_error(int error, char *name);
void				cd_print_error(int error, char *name);

#endif

#ifdef DEBUG
# define D_PUTENDL(str) ft_putendl_fd(str, 2)
#else
# define D_PUTENDL(str)
#endif
