# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 09:51:39 by fguirama          #+#    #+#              #
#    Updated: 2022/11/28 14:39:30 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJS_SRC	= $(SRCS:.c=.o)
BONUS		= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS_BONUS	= $(BONUS:.c=.o)
NAME		= libft.a
HEAD		= libft.h
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

%.o: %.c Makefile ${HEAD}
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o $@


all:		${NAME}

${NAME}:	${OBJS_SRC}
			ar rc ${NAME} ${OBJS_SRC}

clean:
			${RM} ${OBJS_SRC}
			${RM} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${NAME} ${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS} ${OBJS_SRC}

.PHONY:		all clean fclean re bonus