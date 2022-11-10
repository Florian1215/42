# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 09:08:09 by fguirama          #+#    #+#              #
#    Updated: 2022/11/10 16:27:57 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC		= srcs/
SRCS		= ft_base.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_strlen.c ft_printf.c 
OBJS_SRC	= $(addprefix ${DIR_SRC}, ${SRCS:.c=.o})
BONUS		= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS_BONUS	= $(addprefix ${DIR_BONUS}, ${BONUS:.c=.o})
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

bonus:		${NAME} ${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS} ${OBJS_SRC}

.PHONY:		all clean fclean re