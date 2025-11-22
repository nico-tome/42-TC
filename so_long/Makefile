NAME := so_long
NAME_BONUS := so_long_bonus

SRC_DIR := src/
SRC_BONUS_DIR := src_bonus/
ERROR_DIR := error/
GAME_DIR := game/
PARSER_DIR := parser/
BUILD_DIR := build/
BUILD_DIR_BONUS := build_bonus/

SRCS := $(ERROR_DIR)ft_error.c \
        $(ERROR_DIR)ft_error_codes.c \
        $(GAME_DIR)main.c \
		$(GAME_DIR)ft_event_handling.c \
		$(GAME_DIR)ft_page_manager.c \
		$(GAME_DIR)ft_textures_utils.c \
		$(GAME_DIR)ft_wall_texture_utils.c \
		$(GAME_DIR)ft_player.c \
		$(GAME_DIR)ft_tile_size_utils.c \
		$(GAME_DIR)ft_check_textures.c \
        $(PARSER_DIR)ft_check_map.c \
        $(PARSER_DIR)ft_file_parser.c \
        $(PARSER_DIR)ft_parse_map_utils.c \
        $(PARSER_DIR)ft_pathfinding.c \
        $(PARSER_DIR)ft_pathfinding_utils.c

SRCS_BONUS :=	$(ERROR_DIR)ft_error_bonus.c \
        		$(ERROR_DIR)ft_error_codes_bonus.c \
				$(GAME_DIR)ft_animation_bonus.c \
				$(GAME_DIR)ft_check_textures_bonus.c \
				$(GAME_DIR)ft_event_handling_bonus.c \
				$(GAME_DIR)ft_page_manager_bonus.c \
				$(GAME_DIR)ft_textures_utils_bonus.c \
				$(GAME_DIR)ft_wall_texture_utils_bonus.c \
				$(GAME_DIR)ft_player_bonus.c \
				$(GAME_DIR)ft_free_image_bonus.c \
				$(GAME_DIR)ft_tile_size_utils_bonus.c \
				$(GAME_DIR)ft_enemy_bonus.c \
				$(GAME_DIR)ft_editor_bonus.c \
				$(GAME_DIR)ft_death_bonus.c \
				$(GAME_DIR)ft_save_map_bonus.c \
				$(GAME_DIR)ft_attack_bonus.c \
    			$(GAME_DIR)main_bonus.c \
		        $(PARSER_DIR)ft_check_map_bonus.c \
		        $(PARSER_DIR)ft_file_parser_bonus.c \
	        	$(PARSER_DIR)ft_parse_map_utils_bonus.c \
	    	    $(PARSER_DIR)ft_pathfinding_bonus.c \
		        $(PARSER_DIR)ft_pathfinding_utils_bonus.c

OBJ := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))
OBJ_BONUS := $(patsubst %.c, $(BUILD_DIR_BONUS)%.o, $(SRCS_BONUS))

HEADERS := includes/
HEADERS_BONUS := includes_bonus/

LIBS := lib/libft/libft.a \
		lib/MacroLibX/libmlx.so

CC := cc

FLAGS := -g -Wall -Werror -Wextra

all: ${NAME}

${LIBS}:
	@make -C lib/libft
	@make -C lib/MacroLibX -j16

$(NAME): ${LIBS} ${OBJ}
	${CC} -o ${NAME} -I ${HEADERS} ${OBJ} ${LIBS} ${FLAGS} -lm -lSDL2

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(dir $@)
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

${BUILD_DIR_BONUS}%.o: ${SRC_BONUS_DIR}%.c
	@mkdir -p $(dir $@)
	${CC} -o $@ -I ${HEADERS_BONUS} -c $< ${FLAGS}

bonus: ${LIBS} ${OBJ_BONUS}
	${CC} -o ${NAME_BONUS} -I ${HEADERS_BONUS} ${OBJ_BONUS} ${LIBS} ${FLAGS} -lm -lSDL2

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS}
	@make -C lib/MacroLibX clean
	@make -C lib/libft clean

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBS}
	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: clean flcean re all
