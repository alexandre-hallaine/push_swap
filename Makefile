SOURCES				=	utils/ft_put.c \
						utils/ft_equals.c \
						utils/get_next_line_utils.c \
						utils/get_next_line.c \
						utils/parse.c \
						utils/dispatch.c \
						utils/check.c \
						operations/sa.c \
						operations/sb.c \
						operations/ss.c \
						operations/pa.c \
						operations/pb.c \
						operations/ra.c \
						operations/rb.c \
						operations/rr.c \
						operations/rra.c \
						operations/rrb.c \
						operations/rrr.c
OBJECTS				=	${SOURCES:.c=.o}

SOURCES_CHECKER		=	checker_srcs/prompt.c \
						checker_srcs/main.c
OBJECTS_CHECKER		=	${SOURCES_CHECKER:.c=.o}

SOURCES_PUSH_SWAP	=	push_swap_srcs/execute.c \
						push_swap_srcs/number.c \
						push_swap_srcs/sort.c \
						push_swap_srcs/main.c
OBJECTS_PUSH_SWAP	=	${SOURCES_PUSH_SWAP:.c=.o}

NAME_CHECKER		=	checker
NAME_PUSH_SWAP		=	push_swap

COMPILE				=	cc
REMOVE				=	rm -f

COMPILATION_FLAGS	=	-Wall -Wextra -Werror

.c.o:
	${COMPILE} ${COMPILATION_FLAGS} -c $< -o ${<:.c=.o}

all: ${NAME_CHECKER} ${NAME_PUSH_SWAP}

${NAME_CHECKER}: ${OBJECTS} ${OBJECTS_CHECKER}
	${COMPILE} -o ${NAME_CHECKER} ${OBJECTS} ${OBJECTS_CHECKER}

${NAME_PUSH_SWAP}: ${OBJECTS} ${OBJECTS_PUSH_SWAP}
	${COMPILE} -o ${NAME_PUSH_SWAP} ${OBJECTS} ${OBJECTS_PUSH_SWAP}

clean:
	${REMOVE} ${OBJECTS} ${OBJECTS_CHECKER} ${OBJECTS_PUSH_SWAP}

fclean: clean
	${REMOVE} ${NAME_CHECKER} ${NAME_PUSH_SWAP}

re: fclean all

.PHONY: all clean fclean re
