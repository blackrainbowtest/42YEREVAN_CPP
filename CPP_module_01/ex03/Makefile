# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/02 15:27:00 by aramarak          #+#    #+#              #
#    Updated: 2026/05/04 16:31:16 by aramarak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = unnecessary_violence

CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

SRC_FILES	=	HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))


RM        = rm -f
RMDIR     = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RMDIR) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re