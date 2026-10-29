NAME = libftprintf.a
CC = cc

MY_SOURCES =	src/ft_printf.c \
				src/ft_unsigned_itoa.c \
				src/ft_convert_base.c \
				src/ft_putnbr_base.c

MY_OBJECTS = $(MY_SOURCES:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

DEBUGFLAGS = -g -lbsd main.c libft.a

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
