CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
HEADER = ft_printf.h
SOURCES = ft_printf.c ft_print_putnbr.c ft_printstr.c ft_putchar.c ft_putnbr_hex_lower.c ft_putnbr_hex_upper.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) libft.a
	ar rcs $(NAME) $(OBJECTS)
	ar rcs $(NAME) libft.a

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
