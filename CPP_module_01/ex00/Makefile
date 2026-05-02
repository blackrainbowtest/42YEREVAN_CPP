# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/02 15:27:14 by aramarak          #+#    #+#              #
#    Updated: 2026/05/02 15:27:15 by aramarak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = Zombie

CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98

SRCS      = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS      = $(SRCS:.cpp=.o)

RM        = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re