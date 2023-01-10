# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 18:51:51 by fguirama          #+#    #+#              #
#    Updated: 2022/12/17 18:51:54 by fguirama         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

OBJS_DIR	= OBJS/
SRCS		= binary.c error.c pipex.c printf.c read_file.c split.c str.c
OBJS		= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

NAME		= pipex
HEAD		= pipex.h

CC			= cc
RM			= rm -rf
#FLAG		= -Wall -Wextra -Werror

all:		${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD}
			${CC} ${FLAG} -I ${HEAD} -c $< -o $@

${NAME}:	dir ${OBJS}
			${CC} ${FLAG} ${OBJS} -o ${NAME}

dir:
			@mkdir -p ${OBJS_DIR}

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
