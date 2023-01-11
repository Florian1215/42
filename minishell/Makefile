# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 11:03:03 by fguirama          #+#    #+#              #
#    Updated: 2023/01/08 11:03:05 by fguirama         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OBJS_DIR		=	.OBJS/

SRCS			=	BUILTINS/cd.c BUILTINS/echo.c BUILTINS/pwd.c \
					EXEC/exec.c EXEC/init.c \
					FREE/free.c \
					PARSING/parsing.c PARSING/cmd.c \
					UTILS/split.c UTILS/io.c UTILS/str.c UTILS/str2.c UTILS/dict.c UTILS/env.c \
					main.c

OBJS_SRCS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

NAME			=	minishell
HEAD			=	minishell.h

CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -g3

all:				$(NAME)

$(OBJS_DIR)%.o:		%.c $(HEAD) Makefile
					$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@

dir:
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)BUILTINS
					@mkdir -p $(OBJS_DIR)EXEC
					@mkdir -p $(OBJS_DIR)FREE
					@mkdir -p $(OBJS_DIR)PARSING
					@mkdir -p $(OBJS_DIR)UTILS

$(NAME):			dir $(OBJS_SRCS)
					$(CC) -lreadline $(FLAGS) $(OBJS_SRCS) -o $(NAME)

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
