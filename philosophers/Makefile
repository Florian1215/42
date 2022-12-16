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

OBJS_DIR	= OBJ/

#ls *.c | tr "\t\n" " "
SRCS		= parsing.c philosophers.c printf.c
OBJS		= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))
NAME		= philosopher
HEAD		= ${NAME}.h

CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror

all:		${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD} Makefile
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:	dir ${OBJS}
			${CC} ${FLAGS} ${OBJS_INS} ${OBJS_SRC} -o ${NAME}

dir:
			@mkdir -p ${OBJS_DIR}

bonus:		${OBJS_INS} ${OBJS_BON}
			${CC} ${FLAGS} ${OBJS_INS} ${OBJS_BON} -o ${NAME_BON}

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME} ${NAME_BON}

re:			fclean all

.PHONY:		all clean fclean re bonus