# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 18:37:01 by fguirama          #+#    #+#              #
#    Updated: 2022/12/04 11:11:54 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ls *.c | tr "\t\n" " "
SRCS		= color_set.c fractal.c fractol.c hook.c utils.c utils_colors.c utils_fractal.c utils_mlx.c menu.c
OBJS_SRC	= $(SRCS:.c=.o)

NAME		= fractol
HEAD		= fractol.h

CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -O3

MLX_DIR		= minilibx
MLX_NAME	= libmlx.a
MLX_FLAGS	= -framework OpenGL -framework AppKit

all:		mlx ${NAME}
			./${NAME}
#			leaks -atExit -- ./${NAME}

%.o: %.c ${HEAD} Makefile
		${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

mlx:
			make -C ${MLX_DIR}

${NAME}:	${OBJS_SRC}
			${CC} ${FLAGS} ${OBJS_SRC} ${MLX_DIR}/${MLX_NAME} ${MLX_FLAGS} -o ${NAME}

clean:
			${RM} ${OBJS_SRC} ${OBJS_BON}
			make clean -C ${MLX_DIR}

fclean:		clean
			${RM} ${NAME} ${NAME_BON}

re:			fclean all

.PHONY:		all clean fclean re