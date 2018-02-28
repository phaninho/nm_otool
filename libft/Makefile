# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stmartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/12 22:04:11 by stmartin          #+#    #+#              #
#    Updated: 2018/02/28 10:23:34 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./
OBJ_PATH = ./
INC_PATH = ./
LIB_PATH = ./

SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strchr.c ft_atoi.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	  ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
	  ft_memchr.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putchar.c ft_putstr.c \
	  ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_strsplit.c ft_strlcat.c ft_itoa.c ft_lstnew.c \
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  ft_swap.c ft_strrev.c ft_crypt.c ft_decrypt.c ft_debug.c get_next_line.c \
	  ft_tab_free.c ft_tab_len.c ft_count_line_in_file.c ft_sqrt.c ft_atol.c \
	  ft_count_2d_tab.c ft_itoa_base.c ft_strclen.c ft_hexa_itoa.c \
	  ft_print_memory.c ft_put_long.c ft_ltoa.c ft_put_ulong.c ft_ltoa_base.c \
	  ft_ultoa.c ft_hexa_ltoa.c ft_ultoa_base.c ft_size_ttoa.c \
	  ft_printf.c padding.c percent_percent.c percent_s.c width.c percent_c.c \
	  percent_x.c percent_l.c percent_j.c percent_h.c percent_z.c percent_d.c \
	  percent_d_up.c percent_p.c percent_o.c percent_o_up.c percent_c_up.c \
	  percent_d_2.c percent_s_up.c percent_u_up.c init.c check.c \
	  check_struct.c percent_l_2.c write_space_or_zero.c space_or_zero.c \
	  width_2.c write_space_or_zero_2.c wchar_t.c percent_s_up_precision.c \
	  misc.c precision.c ft_printf_2.c particular_case.c \
	  write_space_or_zero_3.c ft_lltoa.c ft_tabdel.c ft_p2.c ft_abs.c \
	  ft_countword_btwsign.c ft_double_abs.c ft_intsize.c ft_isspace.c \
	  ft_move_sign.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = libft.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -fv $(OBJ)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
