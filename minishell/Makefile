OBJS_DIR		= OBJ/

SRCS			= main.c
OBJS_SRCS		= $(addprefix ${OBJS_DIR}, $(SRCS:.c=.o))

HEAD			= push_swap.h
CC				= cc
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror

all:			${NAME}

$(OBJS_DIR)%.o: %.c ${HEAD}
				${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

${NAME}:		dir ${OBJS_SRCS}
				${CC} ${FLAGS} ${OBJS_SRCS} -o ${NAME}

dir:
				mkdir -p ${OBJS_DIR}

clean:
				${RM} ${OBJS_DIR}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re bonus dir