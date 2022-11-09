# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:10:42 by fguirama          #+#    #+#              #
#    Updated: 2022/08/17 15:27:05 by fguirama         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

DIR_SRC		= srcs/
SRCS		= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS		= $(addprefix ${DIR_SRC}, ${SRCS:.c=.o})
HEAD		= includes
NAME		= libft.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
