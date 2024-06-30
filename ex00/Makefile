# Compiler
CPP = c++

# Compiler flags
CPPFLAGS = -Werror -Wall -Wextra -std=c++98

# Source files
SRC = main.cpp BitcoinExchange.cpp

# Object files generated from source files
OBJ = $(SRC:.cpp=.o)

# Name of the btc executable to be generated
NAME = btc

# Default target to be built
all: $(NAME)

# Rule to generate the btc executable from the object files
$(NAME): $(OBJ) BitcoinExchange.hpp
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

# Rule to generate the object files from the source files
%.o: %.cpp BitcoinExchange.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJ)

# Fclean target to remove executable files and finally perform clean
fclean: clean
	rm -f $(NAME)

# Re target to rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re