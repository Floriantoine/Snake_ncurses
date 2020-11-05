##
## EPITECH PROJECT, 2018
## DANTE_2018
## File description:
## generator_Makefile
##

SRC			=	src/main.cpp\
				src/randy.cpp\
				src/body.cpp\
				src/class/Setting.cpp\
				src/class/Snake.cpp

OBJ_SRC		=	$(SRC:.cpp=.o)

NAME		=	 my_snake

CC			=	g++

override CXXFLAGS	+=	-Wall -Wextra -Werror -I ./include -lncurses -lmenu

$(NAME): $(OBJ_SRC)
	@echo -e "\e[36;1m\nMAKE $(NAME)\n\e[0m"
	@$(CC) $(CXXFLAGS) $^ -o $@

all:$(NAME)

clean:
	@echo -e "\e[31;1mCLEANING OBJ: $(NAME)\e[0m"
	@rm -rf $(OBJ_SRC)

fclean: clean
	@echo -e "\033[31;1mCLEANING: $(NAME)\033[0m"
	@rm -f $(NAME) $(NAME_TESTS)

re:	fclean	all

.PHONY:	all	clean	fclean	re
