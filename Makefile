##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Plazza
##

SRC		=	src/main.cpp	\
			src/Parsing/ParseArgs.cpp	\
			src/Parsing/ParsingExceptions.cpp	\
			src/Reception/Reception.cpp	\
			src/Parsing/ParseInput.cpp	\
			src/Process/Process.cpp \
			src/Kitchen/Fridge.cpp \
			src/Pizza/Americana.cpp \
			src/Pizza/Fantasia.cpp \
			src/Pizza/APizza.cpp \
			src/Pizza/Margarita.cpp \
			src/Pizza/Regina.cpp \
			src/Pizza/PizzaFactory.cpp \
			src/Kitchen/Kitchen.cpp	\
			src/MessageQueue/MessageQueue.cpp \
			src/Thread/Thread.cpp \
			src/Kitchen/Refill.cpp \
			src/Pizza/Monza.cpp \

OBJ		=	$(SRC:.cpp=.o)

NAME		=	plazza

CPPFLAGS	=	-iquote ./include

CXXFLAGS	=	-Wall -Wextra -std=c++20 -fno-gnu-unique

RM?		=	rm -f

all: 	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re all core
