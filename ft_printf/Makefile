# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 08:29:51 by nmandlan          #+#    #+#              #
#    Updated: 2018/08/10 12:22:37 by nmandlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CSRC_DIR = src/
AUX_DIR = aux/

CSRC = ft_printf_flags.c \
       ft_printf_specifiers.c \
       ft_printf_strings.c \
       ft_printf_numbers.c \
       ft_printf.c

AUX_FILES = ft_atoi.c \
			ft_isdigit.c \
			ft_strrev.c \
			ft_bzero.c \
			ft_memalloc.c \
			ft_strsub.c \
			ft_convert_bin.c \
			ft_putchar.c \
			ft_tolower.c \
			ft_convert_hex.c \
			ft_putnbr.c \
			ft_unsigned_format.c \
			ft_convert_number.c	\
			ft_putnchar.c \
			ft_wclen.c \
			ft_convert_octal.c \
			ft_putstr.c	\
			ft_wcscpy.c \
			ft_decimal_type.c \
			ft_putwchar.c \
			ft_wcsdup.c \
			ft_get_hex.c \
			ft_putwstr.c \
			ft_wcslen.c \
			ft_get_spaces.c	\
			ft_signed_format.c \
			ft_wcsncpy.c \
			ft_get_zeroes.c	\
			ft_strdup.c	\
			ft_wcsnew.c \
			ft_handle_dec.c	\
			ft_strlen.c \
			ft_hex_digits.c	\
			ft_strncpy.c


SRC = $(addprefix $(CSRC_DIR), $(CSRC))
AUX = $(addprefix $(AUX_DIR), $(AUX_FILES))

OBJ = $(CSRC:.c=.o) $(AUX_FILES:.c=.o)

INC = -Iincludes/
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "Compiling... Please Wait."
	@gcc -c $(FLAGS) $(SRC) $(AUX) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) Created Successfully."

clean:
	@/bin/rm -f $(OBJ)
	@echo "$(OBJ) Removed."

fclean:
	@/bin/rm -f $(NAME) $(OBJ)
	@echo "It's all gone, what have you done!!"

re: fclean all

.PHONY: all clean fclean re
