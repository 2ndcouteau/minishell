# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:46:25 by qrosa             #+#    #+#              #
#    Updated: 2016/03/04 00:36:39 by qrosa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC:=./srcs/main.c\
	./srcs/sh_start_endless_loop.c\
	./srcs/sh_print_error.c\
	./srcs/sh_free_all_env.c\
	./srcs/sh_get_input.c\
	./srcs/is_empty.c\
	./srcs/sh_exec_command.c\
	./srcs/sh_create_new_env.c\
	./srcs/sh_create_new_cmd_struct.c\
	./srcs/sh_prepare_line.c\
	./srcs/sh_add_end_path.c\
	./srcs/hist_list_push_front.c\
	./srcs/free_struct.c\
	./srcs/exec_system_cmd.c\
	./srcs/exec_check_path.c\
	./srcs/exec_print_error.c\
	./srcs/exec_builtins.c\
	./srcs/builtin_cd.c\
	./srcs/builtin_env.c\
	./srcs/env_free_all_env.c\
	./srcs/builtin_setenv.c\
	./srcs/builtin_unsetenv.c\
	./srcs/builtin_envreset.c\
	./srcs/builtin_history.c\
	./srcs/builtin_exit.c\
	./srcs/env_position_line.c\
	./srcs/env_replace_var.c\
	./srcs/cd_swap_pwd_env.c\
	./srcs/cd_clean_path.c\
	./srcs/cd_create_path_name.c\
	./srcs/cd_check_valid_file.c\
	./srcs/cd_set_error.c\
	./srcs/cd_oldpwd.c\
	./srcs/cd_home.c\
	./srcs/cd_absolute_path.c\
	./srcs/cd_relative_path.c\
	./srcs/cd_check_new_path.c\
	./srcs/cd_print_error.c\
	./srcs/check_typefile.c

OBJ=$(SRC:.c=.o)

# Lib includes
INC=-I ./includes/
LIBFT=libft/libft.a
LIB=-L ./libft/ -lft

# Options can be changed
CFLAGS:=-Wall -Wextra -Werror
CFLAGS_OBJ:=-Wall -Wextra -Werror
CC:=gcc
NAME:=minishell

# Sweet colors just for swag :)

RED=\033[0;31m
BLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
GREEN=\033[1;32m
NC=\033[0m

all: $(LIBFT) $(NAME)

debug:
	$(eval CFLAGS_OBJ += -DDEBUG)

db: debug all

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ)
	@echo "${BLUE}--Linking $(NAME)${NC}"
	@$(CC) $(OBJ) $(CFALGS) -o $(NAME) $(INC) $(LIB)

%.o: %.c
	@echo "${CYAN}Compiling $^ into $@ ${NC}";
	@$(CC) -g -c $^ -o $@ $(CFLAGS_OBJ) $(INC)

clean:
	@make clean -C libft
	@echo "${ORANGE}--Delete ft_ls/libft OBJS OK ${NC}";
	@rm -f $(OBJ)

fclean: clean
	@echo "${RED}--Remove $(LIBFT)${NC}"
	@rm -f $(LIBFT)
	@echo "${RED}--Remove $(NAME)${NC}"
	@rm -f $(NAME)

re: fclean all

rdb: fclean db

.PHONY: all clean fclean re db rdb
