# Compiler
CPP = c++

# Compiler flags
CPPFLAGS = -Werror -Wall -Wextra -std=c++98

# Source files
SRC = main.cpp RPN.cpp

# Object files generated from source files
OBJ = $(SRC:.cpp=.o)

# Name of the main executable to be generated
NAME = RPN

# Default target to be built
all: $(NAME)

# Rule to generate the main executable from the object files
$(NAME): $(OBJ) RPN.hpp
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

# Rule to generate the object files from the source files
%.o: %.cpp RPN.hpp
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