NAME		:= 	AbstractAnimals

SRCS		:= 	main.cpp \
				Brain.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp

DIR		:=	srcs/
BUILD_DIR	:=	build/

OBJS		:=	$(patsubst %.cpp, $(BUILD_DIR)%.o, $(SRCS))

CC			:= c++

FLAGS 		:= -Wall -Werror -Wextra -g -I ./includes -std=c++98

TPUT 					= tput -T xterm-256color
_RESET 					:= $(shell $(TPUT) sgr0)
_BOLD 					:= $(shell $(TPUT) bold)
_ITALIC 				:= $(shell $(TPUT) sitm)
_UNDER 					:= $(shell $(TPUT) smul)
_GREEN 					:= $(shell $(TPUT) setaf 2)
_YELLOW 				:= $(shell $(TPUT) setaf 3)
_RED 					:= $(shell $(TPUT) setaf 1)
_GRAY 					:= $(shell $(TPUT) setaf 8)
_PURPLE 				:= $(shell $(TPUT) setaf 5)

OBJS_TOTAL	= $(words $(OBJS))
N_OBJS		:= $(shell find $(DIR) -type f -name $(OBJS) 2>/dev/null | wc -l)
OBJS_TOTAL	:= $(shell echo $$(( $(OBJS_TOTAL) - $(N_OBJS) )))
CURR_OBJ	= 0

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${FLAGS} -o ${NAME} ${OBJS}
	@printf "$(_BOLD)$(NAME)$(_RESET) compiled $(_GREEN)$(_BOLD)successfully$(_RESET)\n\n"

${BUILD_DIR}%.o: ${DIR}%.cpp
	@mkdir -p ${BUILD_DIR}$(dir $@)
	@${CC} ${FLAGS} -o $@ -c $< $(FLAGS)
	@$(eval CURR_OBJ=$(shell echo $$(( $(CURR_OBJ) + 1 ))))
	@$(eval PERCENT=$(shell echo $$(( $(CURR_OBJ) * 100 / $(OBJS_TOTAL) ))))
	@printf "$(_GREEN)($(_BOLD)%3s%%$(_RESET)$(_GREEN)) $(_RESET)Compiling $(_BOLD)$(_PURPLE)$<$(_RESET)\n" "$(PERCENT)"
	
clean:
	@rm -rf ${OBJS}
	@printf "\n$(_BOLD)All objects are $(_GREEN)cleaned $(_RESET)! 🎉\n\n"

fclean: clean
	@rm -f ${NAME}
	@printf "Cleaned $(_BOLD)$(NAME)$(_RESET) !\n\n"

re: fclean all

.PHONY: clean fclean re all
