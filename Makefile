NAME = libft.a
$(CC) = cc

MY_SOURCES =	ft_printf.c

MY_OBJECTS = $(MY_SOURCES:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

DEBUGFLAGS = -g -lbsd -fPIC main.c libft.a

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
