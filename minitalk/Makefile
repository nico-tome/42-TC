CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

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

FLAGS = -g -Wall -Werror -Wextra

all: ${CLIENT} ${SERVER}

${LIBS}:
	make -C lib/printf
    
$(CLIENT): ${LIBS} ${OBJ_CLIENT_MANDA}
	${CC} -o ${CLIENT} -I ${HEADERS} ${OBJ_CLIENT_MANDA} ${LIBS}

$(SERVER): ${LIBS} ${OBJ_SERVER_MANDA}
	${CC} -o ${SERVER} -I ${HEADERS} ${OBJ_SERVER_MANDA} ${LIBS}

${BUILD_DIR}%.o: ${SRC_DIR}%.c
	mkdir -p build
	${CC} -o $@ -I ${HEADERS} -c $< ${FLAGS}

clean:
	rm -f ${OBJ_CLIENT_MANDA} ${OBJ_CLIENT_BONUS} ${OBJ_SERVER_MANDA} ${OBJ_SERVER_BONUS}
	make -C lib/printf clean

bonus: ${LIBS} ${OBJ_CLIENT_BONUS} ${OBJ_SERVER_BONUS}
	${CC} -o ${CLIENT_BONUS} -I ${HEADERS} ${OBJ_CLIENT_BONUS} ${LIBS}
	${CC} -o ${SERVER_BONUS} -I ${HEADERS} ${OBJ_SERVER_BONUS} ${LIBS}

fclean: clean
	rm -f ${CLIENT}
	rm -f ${SERVER}
	rm -f ${CLIENT_BONUS}
	rm -f ${SERVER_BONUS}
	rm -f ${LIBS}

re: fclean all

.PHONY: clean flcean re all
