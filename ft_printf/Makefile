# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 09:08:09 by fguirama          #+#    #+#              #
#    Updated: 2022/11/15 12:37:18 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_base.c ft_str.c ft_putnb.c ft_printf.c 
OBJS_SRC	= $(SRCS:.c=.o)
HEAD		= libftprintf.h
NAME		= libftprintf.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

%.o: %.c Makefile ${HEAD}
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o $@

${NAME}:	${OBJS_SRC}
			ar rc ${NAME} ${OBJS_SRC}

all:		${NAME}

clean:
			${RM} ${OBJS_SRC}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re