
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = basics.c hexadecimals.c pointers.c ft_printf.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
