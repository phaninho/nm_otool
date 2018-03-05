# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stmartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 18:56:34 by stmartin          #+#    #+#              #
#    Updated: 2018/03/05 19:41:05 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NM_NAME = ft_nm
OTOOL_NAME = ft_otool

SRC_NM_PATH = ./src/ft_nm/
SRC_OTOOL_PATH = ./src/ft_otool/
OBJ_NM_PATH = ./obj_nm/
OBJ_OTOOL_PATH = ./obj_otool/

INC_PATH = ./include/ ./libft/
LIB_PATH = ./libft/

SRC_NM_NAME = ft_nm.c display_64.c manage_64.c display_32.c manage_32.c \
	order_display.c symbol_type.c manage_fat.c manage_archive.c
OBJ_NM_NAME = $(SRC_NM_NAME:.c=.o)

SRC_OTOOL_NAME = ft_otool.c display_64.c manage_64.c display_32.c \
manage_32.c manage_fat.c manage_archive.c
OBJ_OTOOL_NAME = $(SRC_OTOOL_NAME:.c=.o)

LIB_NAME = -lft
DEP = ./include/nm_otool.h

SRC_NM = $(addprefix $(SRC_NM_PATH),$(SRC_NM_NAME))
SRC_OTOOL = $(addprefix $(SRC_OTOOL_PATH),$(SRC_OTOOL_NAME))
OBJ_NM = $(addprefix $(OBJ_NM_PATH),$(OBJ_NM_NAME))
OBJ_OTOOL = $(addprefix $(OBJ_OTOOL_PATH),$(OBJ_OTOOL_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NM_NAME)
	@make $(OTOOL_NAME)

$(NM_NAME): $(OBJ_NM)
	$(CC) -I $(INC) $^ -o $@ $(LIB) $(LIB_NAME)

$(OBJ_NM_PATH)%.o: $(SRC_NM_PATH)%.c $(DEP)
	@mkdir -p $(OBJ_NM_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OTOOL_NAME): $(OBJ_OTOOL)
	$(CC) -I $(INC) $^ -o $@ $(LIB) $(LIB_NAME)

$(OBJ_OTOOL_PATH)%.o: $(SRC_OTOOL_PATH)%.c $(DEP)
	@mkdir -p $(OBJ_OTOOL_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C $(LIB_PATH)

clean:
	rm -rf $(OBJ_NM) $(OBJ_OTOOL) $(OBJ_NM_PATH) $(OBJ_OTOOL_PATH)

fclean: clean
	@make -C $(LIB_PATH) fclean
	rm -f $(NM_NAME) $(OTOOL_NAME) $(LINK) $(TEST_NAME)


re: fclean all

test:
	$(CC) test_malloc/test1.c $(INC) $(LINK) -o test1

norme :
	@echo "\033[37;44m norme libft \033[0m"
	@norminette ./libft/*[ch]
	@echo "\033[37;44m norme src directory \033[0m"
	@norminette ./src/ft_nm/*.c ./src/ft_otool/*.c
	@echo "\033[37;44m norme include directory \033[0m"
	@norminette ./include/*.h
