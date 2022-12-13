# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 18:37:01 by fguirama          #+#    #+#              #
#    Updated: 2022/12/12 16:28:10 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= fractal.c fractol.c hook.c menu.c set_colors.c set_fractals.c thread.c utils_colors.c utils_fractal.c utils_loop.c utils_menu.c utils_mlx.c
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