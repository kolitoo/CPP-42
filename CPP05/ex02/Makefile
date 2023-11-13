# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 10:09:48 by abourdon          #+#    #+#              #
#    Updated: 2023/11/13 14:55:49 by abourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02
CC = c++
FLAGS = -Wall -Wextra -Werror
C98 = -std=c++98
RM = rm -rf
HEADER = Bureaucrat.hpp \
	 AForm.hpp \

GREEN=\033[33;32m
BLUE=\033[0;34m
BOLD=\033[1m
RESET=\033[0m

	
SRC = 	main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \

OBJ = $(SRC:.cpp=.o)

%.o : %.cpp $(HEADER)
	@$(CC) $(FLAGS) $(C98) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)$(BOLD)Compiling $(NAME)...$(RESET)"
	@$(CC) $(FLAGS) $(C98) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) compiled!$(RESET)"

all: $(NAME)

clean:
	@echo "$(BLUE)$(BOLD)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(BLUE)$(BOLD)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: init all clean fclean re