# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 12:24:27 by dmusulas          #+#    #+#              #
#    Updated: 2025/07/17 16:20:30 by dmusulas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP             = c++
CPPFLAGS        = -Wall -Wextra -Werror -std=c++98 -MMD -MP
NAME            = real_type
MAKE            = make
RM              = rm -rf

SRCS            = main.cpp Base.cpp

OBJS            = $(SRCS:%.cpp=obj/%.o)
OBJ_DIR         = obj

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
		$(CPP) $(CPPFLAGS) $(OBJS) -o $@

obj/%.o: %.cpp | $(OBJ_DIR)
		$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
