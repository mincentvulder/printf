# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vmulder <vmulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:18:40 by vmulder        #+#    #+#                 #
#    Updated: 2019/04/22 16:31:06 by vmulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

## EXECUTABLE ##
NAME = libftprintf.a

## INCLUDES ##
SRC_PATH = srcs
HEADER = ../incl/printf.h

## SOURCES ##
SOURCES = main.c

## OBJECTS ##
SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(SOURCES:.c=.o)

## COMPILATION ##
CC = gcc
FLAGS = -Wall -Werror -Wextra -c

## RULES ##
all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(FLAGS) $(SRCS) -I $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@echo "Project successfully compiled"

clean:
	@echo "Cleaning..."
	@make clean -C libft
	@rm -rf *.o

fclean:
	@echo "Fcleaning..."
	@rm -rf *.o
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean
