# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 09:25:41 by nmandlan          #+#    #+#              #
#    Updated: 2018/09/08 11:40:15 by nmandlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

IDIR = ./includes/
INCS = ft_ls.h \
       libft.h

INCC = $(addprefix $(IDIR), $(INCS))

LDIR = ./func
LIBS = -lft

SDIR = ./src/
SRCS = ft_ls.c \
       create_list.c \
       free_list.c \
       print_info.c \
       print_list.c \
       reverse_sort.c \
       sort_list.c \
       ls_flags.c \
       main.c \


SRCC = $(addprefix $(SDIR), $(SRCS))

ODIR = ./objs/
OBJS = $(SRCS:.c=.o)
OBCC = $(addprefix $(ODIR), $(OBJS))

FLAGS = -g -Wall -Werror -Wextra

$(NAME): $(OBCC)
	make -C ./func/
	gcc $(FLAGS) $(OBCC) -L$(LDIR) $(LIBS) -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	gcc $^ $(FLAGS) -c -o $@ -I$(IDIR)

all: $(NAME)

clean:
	@make -C ./func/ clean
	/bin/rm -rf $(OBJS)

fclean: clean
	@make -C ./func/ fclean
	/bin/rm ./func/libft.h.gch
	/bin/rm -rf $(NAME)
	/bin/rm -rf ./objs

re: fclean all

.PHONY: all fclean clean re
