# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmolinel <nmolinel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/07 15:04:24 by nmolinel      #+#    #+#                  #
#    Updated: 2022/03/08 18:22:51 by nmolinel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT	=	libft/libft.a

FLAGS	=	-Wall -Werror -Wextra

SRCS	=	validation.c \
			actions/swap.c actions/rotate.c actions/rev_rotate.c actions/push.c \
			stack/core.c stack/edit.c stack/print.c stack/get.c stack/util.c \
			sort/sort.c sort/quick.c sort/select.c sort/hand.c \
			sort/partition.c sort/check.c sort/util.c \
			sort/index.c sort/median.c

BSRC	=	checker_bonus/checker.c checker_bonus/op.c checker_bonus/get_next_line.c \
			checker_bonus/get_next_line_utils.c

H_PATH	=	includes

RM		=	rm -f

CHECK	=	checker

all: ${NAME}

${NAME}: ${LIBFT} ${SRCS} main.c
	$(CC) $(FLAGS) -o $@ -I ${H_PATH} $^

${LIBFT}:
	make -C libft

$(CHECK): ${LIBFT} $(SRCS) $(BSRC)
	$(CC) $(FLAGS) -o $(CHECK) -I ${H_PATH} $^

bonus: $(CHECK)

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
