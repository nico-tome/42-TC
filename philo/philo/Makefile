NAME := philo
NAME_BONUS := philo_bonus

SRC_DIR := src/
SRC_BONUS_DIR := src_bonus/
BUILD_DIR := build/
BUILD_DIR_BONUS := build_bonus/

SRCS := $(SRC_DIR)ft_parser.c \
		$(SRC_DIR)main.c

SRCS_BONUS :=	$(SRC_BONUS_DIR)ft_error_bonus.c

OBJ := $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRCS))
OBJ_BONUS := $(patsubst $(SRC_BONUS_DIR)%.c, $(BUILD_DIR_BONUS)%.o, $(SRCS_BONUS))

HEADERS := includes/
HEADERS_BONUS := includes_bonus/

CC := cc

FLAGS := -g -Wall -Werror -Wextra

all: ${NAME}

$(NAME): ${OBJ}
	${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${FLAGS}

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

${BUILD_DIR_BONUS}%.o: ${SRC_BONUS_DIR}%.c
	@mkdir -p $(dir $@)
	${CC} -o $@ -I ${HEADERS_BONUS} -c $< ${FLAGS}

bonus: ${OBJ_BONUS}
	${CC} -o ${NAME_BONUS} -I ${HEADERS_BONUS} ${OBJ_BONUS} ${LIBS} ${FLAGS}

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: clean fclean re all
