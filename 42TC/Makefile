SRCS = ft_printf.c \
	   ft_putnbr.c \
	   ft_putstr.c \
	   ft_print_ptr.c \
	   ft_put_hex.c \
	   ft_putnbr_unsigned.c \
	   

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

NAME = libftprintf.a

#rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
