CC = gcc

NAME = push_swap

CFLAGS = -Werror -Wall -Wextra

SRC = $(shell find src -name "*.c") main.c stack_clear.c stack_sort_algorithm_2.c

OBJ = $(SRC:.c=.o)

PRINTF_SRC = ft_printf/ft_print_ptr.c ft_printf/ft_printf_utils.c ft_printf/ft_printf.c

PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

LIBFT_SRC := $(shell find libft -name "ft_*.c")

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

LIBFT = libft.a

PRINTF = libftprintf.a

all:  $(PRINTF) $(LIBFT) $(NAME)

$(PRINTF): $(PRINTF_OBJ)
	ar cr $(PRINTF) $(PRINTF_OBJ)

$(LIBFT): $(LIBFT_OBJ)
	ar cr $(LIBFT) $(LIBFT_OBJ)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L. -lftprintf -lft

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(PRINTF) $(LIBFT) $(PRINTF_OBJ) $(LIBFT_OBJ)

re: fclean all

.PHONY: re all fclean clean
