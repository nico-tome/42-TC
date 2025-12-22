NAME = Account

CC = c++
FLAGS = -Wall -Werror -Wextra -g -std=c++98 -I .

SRCS = Account.cpp \
       tests.cpp

OBJ_DIR = .build/
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "Account compiled !\n"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "Objects deleted !\n"

fclean: clean
	@rm -f $(NAME)
	@printf "Programme deleted !\n"

re: fclean all

.PHONY: all clean fclean re
