# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 09:51:39 by fguirama          #+#    #+#              #
#    Updated: 2022/11/09 11:31:08 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC		= srcs/
SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJS_SRC	= $(addprefix ${DIR_SRC}, ${SRCS:.c=.o})
DIR_BONUS	= bonus/
BONUS		= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS_BONUS	= $(addprefix ${DIR_BONUS}, ${BONUS:.c=.o})
HEAD		= includes
NAME		= libft.a
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