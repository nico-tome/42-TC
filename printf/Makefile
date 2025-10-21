NAME = libftprintf.a

SRC = ft_flags_utils.c \
	  ft_print_utils.c \
	  ft_printf.c \
	  ft_size_utils.c \
	  ft_ptr_utils.c

OBJ = $(SRC:.c=.o)

HEAD = ft_printf.h

AR = ar -rcs

CC = cc

FLAGS = -Wall -Werror -Wextra

all: ${NAME}

$(NAME): ${OBJ}
	${AR} ${NAME} ${OBJ}

.c.o:
	${CC} -o $@ -c $< ${FLAGS}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean flcean re all
