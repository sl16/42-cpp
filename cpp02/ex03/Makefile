# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 23:00:29 by vbartos           #+#    #+#              #
#    Updated: 2024/05/16 08:27:42 by vbartos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COLOURS ---------------------------------- #

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# PROJECT ---------------------------------- #

NAME			= bsp

# FLAGS ------------------------------------ #

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -g -std=c++98
RM				= rm -rf

# SOURCE FILES ----------------------------- #

SRC_PATH		= src/
SRC				= main.cpp \
					Fixed.cpp \
					Point.cpp \
					bsp.cpp
SRCS			= $(addprefix $(SRC_PATH), $(SRC))

# OBJECT FILES ----------------------------- #

OBJ_PATH		= obj/
OBJ				= $(SRC:.cpp=.o)
OBJS			= $(addprefix $(OBJ_PATH), $(OBJ))

# INCLUDES --------------------------------- #

INC 			= -I ./inc/

# RULES ------------------------------------ #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)
	@echo "$(GREEN) - Project compiled.$(RESET)"

$(OBJ_PATH)%.o :$(SRC_PATH)%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

clean:
	@${RM} $(OBJ_PATH)
	@echo "$(RED) - Project object files deleted.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED) - Project object & binary files deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus