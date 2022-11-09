# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 15:37:41 by fguirama          #+#    #+#              #
#    Updated: 2022/08/18 13:23:50 by fguirama         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS		= do-op.c
NAME		= do-op
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			${RM} *.o

fclean:		clean
			${RM} ${NAME}

.PHONY:	all clean fclean
