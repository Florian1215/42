# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 09:48:29 by fguirama          #+#    #+#              #
#    Updated: 2022/11/23 09:51:12 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_str.c ft_putnb.c ft_printf.c 
OBJS_SRC	= $(SRCS:.c=.o)
HEAD		= push_swap.h
NAME		= push_swap
CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror

all:		${NAME}

%.o: %.c Makefile ${HEAD}
			${CC} ${FLAGS} -I ${HEAD} $< -o $@

${NAME}:	${OBJS_SRC}
			${CC} ${FLAGS} ${OBJS_SRC}

clean:
			${RM} ${OBJS_SRC}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re