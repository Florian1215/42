# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 17:13:45 by fguirama          #+#    #+#              #
#    Updated: 2022/11/26 17:22:03 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 09:48:29 by fguirama          #+#    #+#              #
#    Updated: 2022/11/26 16:51:59 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 
OBJS_SRC	= $(SRCS:.c=.o)
HEAD		= minitalk.h
NAME		= client


CC			= gcc
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