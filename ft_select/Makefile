# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 12:04:23 by nmandlan          #+#    #+#              #
#    Updated: 2018/09/21 13:20:44 by nmandlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCDIR = ./src/
SRCNAMES = arrow_keys.c \
		   auxilary.c \
		   column_display.c \
		   delete_arg.c \
		   free_mem.c \
		   ft_select.c \
		   init_args.c \
		   key_handler.c \
		   main.c \
		   select_arg.c \
		   signal_handler.c

SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./includes/
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/includes/

CC = gcc

CFLAGS = -Wall -Werror -Wextra -D_XOPEN_SOURCE=500

all: $(BUILDDIR) $(LIBFT) $(NAME)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<

$(NAME): $(BUILDOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LIBFT) -ltermcap

$(LIBFT):
	make -C $(LIBDIR)

clean:
	rm -rf $(BUILDDIR)
	make -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all fclean clean re
