# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 09:08:09 by fguirama          #+#    #+#              #
#    Updated: 2022/11/13 10:00:08 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_base.c ft_putchar.c ft_putnb.c ft_putstr.c ft_strlen.c ft_printf.c 
OBJS_SRC	= $(SRCS:.c=.o)
BONUS		= *_bonus.c
OBJS_BONUS	= $(BONUS:.c=.o)
HEAD		= includes
NAME		= libftprintf.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS_SRC}
			ar rc ${NAME} ${OBJS_SRC}

all:		${NAME}

clean:
			${RM} ${OBJS_SRC}
			${RM} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS_SRC} ${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS} ${OBJS_SRC}

.PHONY:		all clean fclean re