CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -no-pie
LIBFT = ./LIBFT
LIBFT_INC = $(LIBFT)/includes
LIBFT_LIB = $(LIBFT)/libft.a

SRC = pipex_utils.c pipex_utils2.c pipex.c pipex_pipex.c
OBJ = $(SRC:.c=.o)
NAME = pipex

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(OBJ) -L$(LIBFT) -lft -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
