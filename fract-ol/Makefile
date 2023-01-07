# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 18:37:01 by fguirama          #+#    #+#              #
#    Updated: 2023/01/05 14:48:31 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR	= OBJS/
SRCS		= 1_mandelbrot.c 2_julia.c 3_celtic.c 4_burning_ship.c 5_buffalo.c 6_burning_julia.c 7_julia3.c 8_celtic_mandelbar.c 9_perpendicular_celtic.c 10_heart.c 11_mandelbar.c 12_celtic_mandelbrot.c animation.c fractals_utils_1.c fractals_utils_2.c hook.c hook_mouse.c main.c menu.c menu_utils.c render_fractal.c utils_color.c utils_mlx.c
OBJS_SRC	= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

NAME		= fractol
HEAD		= $(NAME).h

CC			= cc
RM			= rm -rf
FLAGS		= -Wall -Wextra -Werror -O3 -g3

MLX_DIR		= minilibx/
MLX_NAME	= libmlx.a
MLX_FLAGS	= -framework OpenGL -framework AppKit

all:		dir mlx ${NAME}
			./${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD} Makefile
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

dir:
			mkdir -p $(OBJS_DIR)

mlx:
			make -j -C ${MLX_DIR}

${NAME}:	${OBJS_SRC}
			${CC} ${FLAGS} ${OBJS_SRC} ${MLX_DIR}${MLX_NAME} ${MLX_FLAGS} -o ${NAME}

clean:
			${RM} ${OBJS_DIR}
			make clean -C ${MLX_DIR}

fclean:		clean
			${RM} ${NAME} ${NAME_BON}

re:			fclean all

.PHONY:		all dir mlx clean fclean re
