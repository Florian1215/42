# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 10:37:38 by fguirama          #+#    #+#              #
#    Updated: 2022/08/21 12:00:47 by fguirama         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

DIR_SRC		= srcs/
SRCS		= ft_check.c ft_dict.c ft_dict_create.c ft_digit.c ft_print.c ft_read_file.c ft_str.c main.c
OBJS		= $(addprefix ${DIR_SRC}, ${SRCS:.c=.o})
HEAD		= includes
NAME		= rush-02
RM			= rm -f
CC			= gcc
FLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${FLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			clean all

.PHONY:		all clean fclean re
