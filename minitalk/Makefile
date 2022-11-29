# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 09:48:29 by fguirama          #+#    #+#              #
#    Updated: 2022/11/29 17:01:20 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERV	= server
SRCS_SERV	= printf.c server.c
OBJS_SERV	= $(SRCS_SERV:.c=.o)

NAME_CLI	= client
SRCS_CLI	= printf.c client.c
OBJS_CLI	= $(SRCS_CLI:.c=.o)

HEAD		= minitalk.h

CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror

all:		${NAME_SERV} ${NAME_CLI}

%.o: %.c Makefile ${HEAD}
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME_SERV}:	${OBJS_SERV}
				${CC} ${FLAGS} ${OBJS_SERV} -o ${NAME_SERV}

${NAME_CLI}:	${OBJS_CLI}
				${CC} ${FLAGS} ${OBJS_CLI} -o ${NAME_CLI}

clean:
			${RM} ${OBJS_SERV} ${OBJS_CLI}

fclean:		clean
			${RM} ${NAME_SERV} ${NAME_CLI}

re:			fclean all

.PHONY:		all clean fclean re