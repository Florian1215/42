# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 09:48:29 by fguirama          #+#    #+#              #
#    Updated: 2022/12/06 14:28:48 by fguirama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR		= OBJ/

SRCS			= ins_push.c ins_reverse.c ins_rotate.c ins_swap.c parsing.c sort_index.c split.c utils1.c utils2.c
OBJS_SRCS		= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

SRCS_PS			= push_swap.c solve_radix.c solve_smart_sort.c utils_solve1.c utils_solve2.c
OBJS_PS			= $(addprefix ${OBJS_DIR}, $(SRCS_PS:.c=.o))
NAME			= push_swap

BON				= bonus_checker.c bonus_get_next_line.c
OBJS_BON		= $(addprefix ${OBJS_DIR}, $(BON:.c=.o))
NAME_BON		= checker

HEAD			= push_swap.h
CC				= cc
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror

all:			${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD}
				${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:		dir ${OBJS_SRCS} ${OBJS_PS}
				${CC} ${FLAGS} ${OBJS_SRCS} ${OBJS_PS} -o ${NAME}

dir:
				mkdir -p ${OBJS_DIR}

bonus:			dir ${OBJS_SRCS} ${OBJS_BON}
				${CC} ${FLAGS} ${OBJS_SRCS} ${OBJS_BON} -o ${NAME_BON}

clean:
				${RM} ${OBJS_DIR}

fclean:			clean
				${RM} ${NAME} ${NAME_BON}

re:				fclean all

.PHONY:			all clean fclean re bonus dir