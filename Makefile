CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = abstractVM

SRC = ./src/Exceptions.cpp ./src/VM.cpp ./src/Converter.cpp ./src/main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@ $(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@ rm -rf $(OBJ)

fclean: clean
	@ rm -rf $(NAME)

re: fclean all