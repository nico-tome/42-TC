NAME := so_long

SRC_DIR := src/
ERROR_DIR := error/
GAME_DIR := game/
PARSER_DIR := parser/
BUILD_DIR := build/

SRCS := $(ERROR_DIR)ft_error.c \
        $(ERROR_DIR)ft_error_codes.c \
        $(GAME_DIR)main.c \
		$(GAME_DIR)ft_event_handling.c \
		$(GAME_DIR)ft_page_manager.c \
		$(GAME_DIR)ft_put_string_utils.c \
		$(GAME_DIR)ft_textures_utils.c \
		$(GAME_DIR)ft_wall_texture_utils.c \
        $(PARSER_DIR)ft_check_map.c \
        $(PARSER_DIR)ft_file_parser.c \
        $(PARSER_DIR)ft_parse_map_utils.c \
        $(PARSER_DIR)ft_pathfinding.c \
        $(PARSER_DIR)ft_pathfinding_utils.c

OBJ := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

HEADERS := headers/

LIBS := lib/libft/libft.a \
		lib/MacroLibX/libmlx.so

CC := cc

FLAGS := -g -Wall -Werror -Wextra -lm -lSDL2

all: ${NAME}

${LIBS}:
	@make -C lib/libft
	@make -C lib/MacroLibX -j16
    
$(NAME): ${LIBS} ${OBJ}
	${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${LIBS} ${FLAGS}

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

clean:
	rm -f ${OBJ}
	@make -C lib/MacroLibX clean
	@make -C lib/libft clean

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBS}

re: fclean all

.PHONY: clean flcean re all
