# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 10:10:04 by wiozsert          #+#    #+#              #
#    Updated: 2022/12/09 15:18:46 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRC = main.cpp vectorTest.cpp

SRCS = $(addprefix ./srcs/, $(SRC) )

FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -Iinc/utils -Iinc

OBJ = $(SRCS:.cpp=.o)

DEP = $(OBJ:%.o=%.d)

all : $(NAME)

.cpp.o:
	c++ $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

clean :
	rm -rf $(OBJ) $(DEP)

fclean : clean
	rm -rf $(NAME)

re : fclean all