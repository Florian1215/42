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

OBJS_DIR		= OBJS/

SRCS			= exec.c free_pipes.c init.c main.c parsing.c split.c utils_str.c
OBJS_SRCS		= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

NAME			= minishell
HEAD			= minishell.h

CC				= cc
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror -g3

all:			${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD} Makefile
				@mkdir -p ${OBJS_DIR}
				${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:		${OBJS_SRCS}
				${CC} ${FLAGS} ${OBJS_SRCS} -o ${NAME}

clean:
				${RM} ${OBJS_DIR}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
