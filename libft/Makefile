# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 13:39:12 by nmandlan          #+#    #+#              #
#    Updated: 2018/09/11 13:41:10 by nmandlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CSRC = *.c
OSRC = *.o
HEADER = libft.h
FLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(HEADER) $(CSRC)
	ar -rc $(NAME) $(OSRC)

clean:
	rm -rf $(OSRC)

fclean:
	rm -rf $(NAME) $(OSRC)
	rm libft.h.gch

re: fclean all

.PHONY: clean fclean all re
