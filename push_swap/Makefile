NAME = push_swap

SRC_DIR = src/
BUILD_DIR = build/

SRC = ft_check_sort.c \
      ft_combined_move_utils.c \
      ft_find_best_move_utils.c \
      ft_index_values_utils.c \
      ft_parse_utils.c \
      ft_parse_utils_2.c \
      ft_push_back.c \
      ft_push_swap.c \
      ft_push_utils.c \
      ft_reverse_rotate_utils.c \
      ft_rotate_utils.c \
      ft_smaller.c \
      ft_sort.c \
      ft_sort_3.c \
      ft_swap_utils.c
      
BONUS = ft_lstnew_bonus.c

OBJ    :=    $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))

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

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	mkdir -p build
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
