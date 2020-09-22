NAME = minishell

INCS = -I./includes
CC = gcc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror $(INCS)

LIBFT = ./libft

SRCS = ./src/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS)

clean:
	# $(MAKE) clean -C $(LIBFT)

fclean: clean
	# $(MAKE) fclean -C $(LIBFT)
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re