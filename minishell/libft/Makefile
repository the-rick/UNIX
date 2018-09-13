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
