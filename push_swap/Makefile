# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 09:48:29 by fguirama          #+#    #+#              #
#    Updated: 2022/12/06 14:28:48 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INS			= ins_push.c ins_reverse.c ins_rotate.c ins_swap.c parsing.c sort_index.c split.c utils.c utils2.c
OBJS_INS	= $(INS:.c=.o)

SRCS		= push_swap.c solve.c
OBJS_SRC	= $(SRCS:.c=.o)
HEAD		= push_swap.h
NAME		= push_swap

BON			= checker.c get_next_line.c get_next_line_utils.c
OBJS_BON	= $(BON:.c=.o)
NAME_BON	= checker

CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror

ARGS		= -237 -56 324 264 -18 47 -257 407 472 -223

all:		${NAME}

%.o: %.c ${HEAD} Makefile
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:	${OBJS_INS} ${OBJS_SRC}
			${CC} ${FLAGS} ${OBJS_INS} ${OBJS_SRC} -o ${NAME}

bonus:		${OBJS_INS} ${OBJS_BON}
			${CC} ${FLAGS} ${OBJS_INS} ${OBJS_BON} -o ${NAME_BON}

check:		${NAME} bonus
			./push_swap ${ARGS} | ./checker ${ARGS} 
			./push_swap ${ARGS} | wc -l

clean:
			${RM} ${OBJS_INS} ${OBJS_SRC} ${OBJS_BON}

fclean:		clean
			${RM} ${NAME} ${NAME_BON}

re:			fclean all

.PHONY:		all clean fclean re bonus check