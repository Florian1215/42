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

OBJS_DIR	= OBJS/
SRCS		= animation.c colors_set1.c colors_set2.c colors_utils.c fractals1.c fractals_pos.c fractals_set1.c fractals_set2.c fractals_utils.c hook.c main.c menu.c menu_utils.c thread.c utils_mlx.c
OBJS_SRC	= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

NAME		= fractol
HEAD		= $(NAME).h

CC			= cc
RM			= rm -rf
FLAGS		= -Wall -Wextra -Werror -O3

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