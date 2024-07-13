# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 18:45:59 by rchahban          #+#    #+#              #
#    Updated: 2024/07/10 17:15:09 by rchahban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CPP = c++

# Compiler flags
CPPFLAGS = -Werror -Wall -Wextra -std=c++98

# Source files
SRC = main.cpp PmergeMe.cpp

# Object files generated from source files
OBJ = $(SRC:.cpp=.o)

# Name of the PmergeMe executable to be generated
NAME = PmergeMe

# Default target to be built
all: $(NAME)

# Rule to generate the PmergeMe executable from the object files
$(NAME): $(OBJ) PmergeMe.hpp
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

# Rule to generate the object files from the source files
%.o: %.cpp PmergeMe.hpp
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