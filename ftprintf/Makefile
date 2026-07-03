NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = .
AR = ar rcs
SRC = ft_printf.c \
	src/ft_print_char.c \
	src/ft_print_hex.c \
	src/ft_print_int.c \
	src/ft_print_pointer.c \
	src/ft_print_string.c \
	src/ft_print_uns_int.c

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
%.o: %.c
		$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re