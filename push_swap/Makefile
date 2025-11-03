NAME = push_swap
NAME_BONUS = checker

SRC_DIR = src/
BONUS_DIR = src_bonus/
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
	  ft_free_utils.c \
      ft_swap_utils.c
      
BONUS = ft_checker_bonus.c

OBJ := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))

OBJ_BONUS = $(patsubst %.c, $(BUILD_DIR_BONUS)%.o, $(BONUS))

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

${BUILD_DIR_BONUS}%.o: ${BONUS_DIR}%.c
	mkdir -p build_bonus
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

clean:
	rm -f ${OBJS}
	make -C lib/libft clean

bonus: ${OBJ} ${OBJ_BONUS} ${LIBS}
	${CC} -o ${NAME_BONUS} -I ${HEADERS} ${OBJ} ${LIBS}
	${CC} -o ${NAME_BONUS} -I ${HEADERS} ${OBJ_BONUS} ${LIBS}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBS}

re: fclean all

.PHONY: clean flcean re all
