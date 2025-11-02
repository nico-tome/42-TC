NAME = push_swap

SRC = src/ft_check_sort.c \
	  src/ft_combined_move_utils.c \
	  src/ft_find_best_move_utils.c \
	  src/ft_index_values_utils.c \
	  src/ft_parse_utils.c \
	  src/ft_parse_utils_2.c \
	  src/ft_push_back.c \
	  src/ft_push_swap.c \
	  src/ft_push_utils.c \
	  src/ft_reverse_rotate_utils.c \
	  src/ft_rotate_utils.c \
	  src/ft_smaller.c \
	  src/ft_sort.c \
	  src/ft_sort_3.c \
	  src/ft_swap_utils.c
	  
BONUS = ft_lstnew_bonus.c

OBJ = $(SRC:.c=.o)

OBJS = ${OBJ} ${BONUS:.c=.o}

HEADERS = headers/

LIBS = lib/libft/libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra

all: ${NAME}

${LIBS}:
	make -C lib/libft
	
$(NAME): ${LIBS} ${OBJ}
	${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${LIBS}

.c.o:
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

clean:
	rm -f ${OBJS}
	make -C lib/libft clean

bonus: ${OBJS} ${LIBS}
	${AR} ${NAME} ${OBJS}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBS}

re: fclean all

.PHONY: clean flcean re all

