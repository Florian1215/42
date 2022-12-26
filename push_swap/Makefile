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

OBJS_DIR	= OBJ/

INS			= solve_b.c utils_solve.c solve_a.c efficient_rrr.c solve_3.c solve_5.c print_stack.c ins_push.c ins_reverse.c ins_rotate.c ins_swap.c parsing.c sort_index.c split.c utils1.c utils2.c sort.c
OBJS_INS	= $(addprefix ${OBJS_DIR}, $(INS:.c=.o))

SRCS		= push_swap.c solve.c
OBJS_SRC	= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))
HEAD		= push_swap.h
NAME		= push_swap

BON			= checker.c get_next_line.c get_next_line_utils.c
OBJS_BON	= $(addprefix ${OBJS_DIR}, $(BON:.c=.o))
NAME_BON	= checker

CC			= cc
RM			= rm -rf
FLAGS		= -Wall -Wextra -Werror

ARGS		= -436 -337 94 3 469 127 -258 -327 211 -98 490 206 -50 -325 -406 -154 -266 397 -212 267 346 -298 98 292 -448 438 22 -464 481 65 29 8 470 273 -295 460 -309 285 -159 -360 417 -54 376 320 -303 335 406 391 339 -287

all:		${NAME}
			./push_swap ${ARGS}
#			./push_swap ${ARGS} | ./Push_Swap-Tester/checker_Mac ${ARGS}

$(OBJS_DIR)%.o: %.c ${HEAD} Makefile
			@mkdir -p ${OBJS_DIR}
			${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:	${OBJS_INS} ${OBJS_SRC}
			${CC} ${FLAGS} ${OBJS_INS} ${OBJS_SRC} -o ${NAME}

bonus:		${OBJS_INS} ${OBJS_BON}
			${CC} ${FLAGS} ${OBJS_INS} ${OBJS_BON} -o ${NAME_BON}

check:		${NAME} bonus
			./push_swap ${ARGS} | ./checker ${ARGS} 
			./push_swap ${ARGS} | wc -l

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ${NAME} ${NAME_BON}

re:			fclean all

.PHONY:		all clean fclean re bonus check