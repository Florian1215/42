# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 09:48:29 by fguirama          #+#    #+#              #
#    Updated: 2022/11/28 14:39:45 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 
OBJS_SRC	= $(SRCS:.c=.o)
HEAD		= minitalk.h
NAME		= client


CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror

all:		${NAME}

%.o: %.c Makefile ${HEAD}
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:	${OBJS_SRC}
			${CC} ${FLAGS} ${OBJS_SRC} -o ${NAME}

bonus:		${OBJS_SRC} ${OBJS_BON}
			${CC} ${FLAGS} ${OBJS_SRC} ${OBJS_BON} -o ${NAME_BON}

clean:
			${RM} ${OBJS_SRC}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus