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
SRCS		= printf.c put_nb.c put_nb_flags.c flags.c str.c utils.c
OBJS_SRC	= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

HEAD		= ft_printf.h
NAME		= libftprintf.a

CC			= cc
RM			= rm -rf
AR			= ar rc
FLAGS		= -Wall -Wextra -Werror -g3

all:		${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD} Makefile
			@mkdir -p $(OBJS_DIR)
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:	${OBJS_SRC}
			${AR} ${NAME} ${OBJS_SRC}

bonus:		${NAME}

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re