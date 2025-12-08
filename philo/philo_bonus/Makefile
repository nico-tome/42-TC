NAME := philo_bonus

SRC_DIR := src_bonus/
BUILD_DIR := build_bonus/

SRCS := $(SRC_DIR)ft_parser.c \
		$(SRC_DIR)ft_free.c \
		$(SRC_DIR)ft_init.c \
		$(SRC_DIR)ft_routine.c \
		$(SRC_DIR)ft_action.c \
		$(SRC_DIR)ft_time.c \
		$(SRC_DIR)ft_write_log.c \
		$(SRC_DIR)main.c

OBJ := $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRCS))

HEADERS := includes_bonus/

CC := cc

FLAGS := -g -Wall -Werror -Wextra

all: ${NAME}

$(NAME): ${OBJ}
	${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${FLAGS}

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re all
