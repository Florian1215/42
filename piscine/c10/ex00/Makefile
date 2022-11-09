# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 15:37:41 by fguirama          #+#    #+#              #
#    Updated: 2022/08/17 16:32:05 by fguirama         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_display_file.c
OBJS		= ${SRCS:.c=.o}
NAME		= ft_display_file
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

.PHONY:	all clean fclean
