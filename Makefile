CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -std=c++11

NC = -lncurses

NAME = abstractVM

SRC =	./src/Exceptions.cpp \
		./src/Factory.cpp \
		./src/Token.cpp \
		./src/Lexer.cpp \
		./src/MethodData.cpp \
		./src/Parser.cpp \
		./src/VM.cpp \
		./src/Visualizer.cpp \
		./src/main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CXX) $(CXXFLAGS) $(NC) -o $(NAME) $(OBJ)

%.o: %.cpp
	@ $(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@ rm -rf $(OBJ)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all