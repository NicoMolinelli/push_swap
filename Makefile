NAME	=	push_swap

LIBFT	= libft/libft.a

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

SRCS	=	sub.c stack.c

H_PATH	=	includes

RM		=	rm -f

all: ${NAME}

${NAME}: ${LIBFT} ${SRCS}
	$(CC) $^ $(FLAGS) -o $@ -I ${H_PATH}

${LIBFT}:
	make -C libft

clean:
	make $@ -C libft

fclean:	clean
	make $@ -C libft
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re