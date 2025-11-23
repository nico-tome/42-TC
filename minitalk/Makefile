NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

SRC_DIR = src/
BUILD_DIR = build/

CLIENT_MANDA = ft_client.c

SERVER_MANDA = ft_server.c

CLIENT_BONUS = ft_client_bonus.c

SERVER_BONUS = ft_server_bonus.c

OBJ_CLIENT_MANDA = $(patsubst %.c, $(BUILD_DIR)%.o, $(CLIENT_MANDA))

OBJ_SERVER_MANDA = $(patsubst %.c, $(BUILD_DIR)%.o, $(SERVER_MANDA))

OBJ_CLIENT_BONUS = $(patsubst %.c, $(BUILD_DIR)%.o, $(CLIENT_BONUS))

OBJ_SERVER_BONUS = $(patsubst %.c, $(BUILD_DIR)%.o, $(SERVER_BONUS))

HEADERS = includes/

LIBS = lib/printf/libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

all: ${NAME_CLIENT} ${NAME_SERVER}

${LIBS}:
	make -C lib/printf
    
$(NAME_CLIENT): ${LIBS} ${OBJ_CLIENT_MANDA}
	${CC} -o ${NAME_CLIENT} -I ${HEADERS} ${OBJ_CLIENT_MANDA} ${LIBS} ${FLAGS}

$(NAME_SERVER): ${LIBS} ${OBJ_SERVER_MANDA}
	${CC} -o ${NAME_SERVER} -I ${HEADERS} ${OBJ_SERVER_MANDA} ${LIBS} ${FLAGS}

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	mkdir -p build
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

clean:
	rm -f ${OBJ_CLIENT_MANDA} ${OBJ_CLIENT_BONUS} ${OBJ_SERVER_MANDA} ${OBJ_SERVER_BONUS}
	make -C lib/printf clean

bonus: ${LIBS} ${OBJ_CLIENT_BONUS} ${OBJ_SERVER_BONUS}
	${CC} -o ${NAME_CLIENT_BONUS} -I ${HEADERS} ${OBJ_CLIENT_BONUS} ${LIBS} ${FLAGS}
	${CC} -o ${NAME_SERVER_BONUS} -I ${HEADERS} ${OBJ_SERVER_BONUS} ${LIBS} ${FLAGS}

fclean: clean
	rm -f ${NAME_CLIENT}
	rm -f ${NAME_SERVER}
	rm -f ${NAME_CLIENT_BONUS}
	rm -f ${NAME_SERVER_BONUS}
	rm -f ${LIBS}

re: fclean all

.PHONY: clean fclean re all
