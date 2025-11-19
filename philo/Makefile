NAME := philo
NAME_BONUS := philo_bonus

SRC_DIR := philo/
SRC_BONUS_DIR := philo_bonus/
BUILD_DIR := build/

SRCS :=	$(SRC_DIR)ft_parser.c \
		$(SRC_DIR)main.c

OBJ := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

HEADERS := includes/

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

.PHONY: clean flcean re all
