# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 09:51:39 by fguirama          #+#    #+#              #
#    Updated: 2022/08/23 14:55:00 by fguirama         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

DIR_SRC		= srcs/
SRCS		= main.c solve_map.c read_file.c pars_map.c check_map.c stdin.c func.c func2.c
OBJS		= $(addprefix ${DIR_SRC}, ${SRCS:.c=.o})
HEAD		= includes
NAME		= bsq
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re