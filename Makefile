NAME	=	push_swap

LIBFT	=	libft/libft.a

FLAGS	=	-Wall -Werror -Wextra

SRCS	=	main.c validation.c \
			actions/swap.c actions/rotate.c actions/rev_rotate.c actions/push.c \
			stack/core.c stack/edit.c stack/print.c stack/get.c \
			sort/sort.c sort/quick.c sort/select.c sort/hand.c \
			sort/partition.c sort/check.c sort/util.c \
			strrep.c sort/index.c

H_PATH	=	includes

RM		=	rm -f

all: ${NAME}

${NAME}: ${LIBFT} ${SRCS}
	$(CC) $(FLAGS) -o $@ -I ${H_PATH} $^

${LIBFT}:
	make -C libft

t10: ${NAME}
	./$< `ruby -e "puts (0..9).to_a.shuffle.join(' ')"`

t100: ${NAME}
	./$< `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

t500: ${NAME}
	./$< `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`

v10: ${NAME}
	python3 pyvisual.py `ruby -e "puts (0..9).to_a.shuffle.join(' ')"`

v100: ${NAME}
	python3 pyvisual.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

v500: ${NAME}
	python3 pyvisual.py `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`

v1000: ${NAME}
	python3 pyvisual.py `ruby -e "puts (-500..500).to_a.shuffle.join(' ')"`


test: ${LIBFT} ${SRCS} test/test.c
	$(CC) $^ $(FLAGS) -o $@ -I ${H_PATH}

clean:
	make $@ -C libft

fclean:
	make $@ -C libft
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
