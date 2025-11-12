NAME = so_long

SRC_DIR = src/
ERROR_DIR = error/
GAME_DIR = game/
PARSER_DIR = parser/
BUILD_DIR = build/

ERROR_ALL = ft_error.c \
			ft_error_codes.c

GAME_ALL = main.c

PARSER_ALL = ft_check_map.c \
			 ft_file_parser.c \
			 ft_parse_map_utils.c \
			 ft_pathfinding.c \
			 ft_pathfinding_utils.c

OBJ   = $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC_ALL))

OBJ_MANDA = $(patsubst %.c, $(BUILD_DIR)%.o, $(MANDA))

OBJ_BONUS = $(patsubst %.c, $(BUILD_DIR)%.o, $(BONUS))

HEADERS = headers/

LIBS = lib/libft/libft.a

CC = cc

FLAGS = -g -Wall -Werror -Wextra

all: ${NAME}

${LIBS}:
	make -C lib/libft
    
$(NAME): ${LIBS} ${OBJ} ${OBJ_MANDA}
	${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${OBJ_MANDA} ${LIBS}

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	mkdir -p build
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

${BUILD_DIR}%.o: ${BONUS_DIR}%.c
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

clean:
	rm -f ${OBJ} ${OBJ_MANDA} ${OBJ_BONUS}
	make -C lib/libft clean

bonus: ${LIBS} ${OBJ} ${OBJ_BONUS}
	${CC} -o ${NAME_BONUS} -I ${HEADERS} ${OBJ} ${OBJ_BONUS} ${LIBS}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}
	rm -f ${LIBS}

re: fclean all

.PHONY: clean flcean re all
