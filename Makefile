NAME = libftprintf.a
CC = cc

MY_SOURCES =	srcs/ft_printf.c \
				srcs/ft_unsigned_itoa.c \
				srcs/ft_convert_base.c \
				srcs/ft_putnbr_base.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_itoa.c \
				libft/ft_memset.c \
				libft/ft_putchar_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_strlcpy.c \
				libft/ft_strdup.c \
				libft/ft_strlen.c

MY_OBJECTS = $(MY_SOURCES:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

DEBUGFLAGS = -g -lbsd main.c

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar crs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

debug: $(MY_OBJECTS)
	@$(CC) $(CFLAGS) $(MY_OBJECTS) $(DEBUGFLAGS)

clean:
	@rm -f $(MY_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all debug clean re
