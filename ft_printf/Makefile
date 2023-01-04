# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 09:08:09 by fguirama          #+#    #+#              #
#    Updated: 2022/11/28 14:39:27 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR	= OBJS/
SRCS		= printf.c put_nb.c flags.c str.c
OBJS_SRC	= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

HEAD		= ft_printf.h
NAME		= libftprintf.a

CC			= cc
RM			= rm -rf
AR			= ar rc
FLAGS		= -Wall -Wextra -Werror

bonus:		${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD}
			mkdir -p $(OBJS_DIR)
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:	${OBJS_SRC}
			${AR} ${NAME} ${OBJS_SRC}


clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re