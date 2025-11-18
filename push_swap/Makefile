NAME = push_swap
NAME_BONUS = checker

SRC_DIR = src/
BONUS_DIR = src_bonus/
BUILD_DIR = build/

SRC_ALL = ft_check_sort.c \
      	ft_combined_move_utils.c \
      	ft_find_best_move_utils.c \
      	ft_index_values_utils.c \
	  	ft_init.c \
      	ft_parse_utils.c \
      	ft_parse_utils_2.c \
     	ft_push_back.c \
      	ft_push_utils.c \
      	ft_reverse_rotate_utils.c \
      	ft_rotate_utils.c \
      	ft_smaller.c \
      	ft_sort.c \
      	ft_sort_3.c \
	  	ft_free_utils.c \
      	ft_swap_utils.c

MANDA = ft_push_swap.c
      
BONUS = ft_checker_bonus.c

OBJ   = $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC_ALL))

OBJ_MANDA = $(patsubst %.c, $(BUILD_DIR)%.o, $(MANDA))

OBJ_BONUS = $(patsubst %.c, $(BUILD_DIR)%.o, $(BONUS))

HEADERS = headers/

LIBS = lib/libft/libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra

all: ${NAME}

${LIBS}:
	make -C lib/libft
    
$(NAME): ${LIBS} ${OBJ} ${OBJ_MANDA}
	${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${OBJ_MANDA} ${LIBS} ${FLAGS}

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	mkdir -p build
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

${BUILD_DIR}%.o: ${BONUS_DIR}%.c
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

clean:
	rm -f ${OBJ} ${OBJ_MANDA} ${OBJ_BONUS}
	make -C lib/libft clean

bonus: ${LIBS} ${OBJ} ${OBJ_BONUS}
	${CC} -o ${NAME_BONUS} -I ${HEADERS} ${OBJ} ${OBJ_BONUS} ${LIBS} ${FLAGS}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}
	rm -f ${LIBS}

re: fclean all

.PHONY: clean flcean re all
