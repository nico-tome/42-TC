NAME = PhoneBook

CC = c++
FLAGS = -Wall -Werror -Wextra -g -std=c++98 -I include

SRC_DIR = src/
SRCS = $(SRC_DIR)Contact.cpp \
	   $(SRC_DIR)main.cpp \
	   $(SRC_DIR)PhoneBook.cpp

OBJ_DIR = .build/
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all fclean clean re
