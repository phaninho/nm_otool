# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stmartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 18:56:34 by stmartin          #+#    #+#              #
#    Updated: 2018/01/27 18:56:38 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = ft_nm

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/
LIB_PATH = ./libft/

SRC_NAME = ft_nm.c display.c manage_64.c order_display.c symbol_type.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft
DEP = ./include/nm_otool.h

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(DEP)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C $(LIB_PATH)

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	@make -C $(LIB_PATH) fclean
	rm -f $(NAME) $(LINK) $(TEST_NAME)


re: fclean all

test:
	$(CC) test_malloc/test1.c $(INC) $(LINK) -o test1

norme :
	@echo "\033[37;44m norme libft \033[0m"
	@norminette ./libft/*[ch]
	@echo "\033[37;44m norme src directory \033[0m"
	@norminette ./src/*.c
	@echo "\033[37;44m norme include directory \033[0m"
	@norminette ./include/*.h
