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
SRCS		= animation.c frac_buffalo.c frac_burning_julia.c frac_burning_ship.c frac_celtic.c frac_celtic_mandelbar.c frac_celtic_mandelbrot.c frac_heart.c frac_julia.c frac_julia3.c frac_mandelbar.c frac_mandelbrot.c frac_perpendicular_celtic.c fractals_utils_1.c fractals_utils_2.c hook.c hook_key.c hook_mouse.c main.c menu.c menu_utils.c thread.c utils_color.c utils_mlx.c
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
