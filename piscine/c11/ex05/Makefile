# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 15:37:41 by fguirama          #+#    #+#              #
#    Updated: 2022/11/28 14:40:10 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= do-op.c
NAME		= do-op
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

all:
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			${RM} *.o

fclean:		clean
			${RM} ${NAME}

.PHONY:	all clean fclean
