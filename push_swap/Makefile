# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 09:48:29 by fguirama          #+#    #+#              #
#    Updated: 2022/11/26 13:57:19 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INS			= parsing.c utils.c move.c push.c reverse.c rotate.c swap.c
OBJS_INS	= ${INS:.c=.o}

SRCS		= push_swap.c
OBJS_SRC	= $(SRCS:.c=.o)
HEAD		= push_swap.h
NAME		= push_swap

BON			= checker.c get_next_line.c get_next_line_utils.c
OBJS_BON	= $(BON:.c=.o)
NAME_BON	= checker

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror

ARGS	= 5 3 2

all:		${NAME} bonus
			./push_swap ${ARGS} | wc -l
#| ./checker ${ARGS}

%.o: %.c Makefile ${HEAD}
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:	${OBJS_INS} ${OBJS_SRC}
			${CC} ${FLAGS} ${OBJS_INS} ${OBJS_SRC} -o ${NAME}

bonus:		${OBJS_INS} ${OBJS_BON}
			${CC} ${FLAGS} ${OBJS_INS} ${OBJS_BON} -o ${NAME_BON}

clean:
			${RM} ${OBJS_INS} ${OBJS_SRC} ${OBJS_BON}

fclean:		clean
			${RM} ${NAME} ${NAME_BON}

re:			fclean all

.PHONY:		all clean fclean re bonus