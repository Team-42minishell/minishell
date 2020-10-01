NAME = minishell

INCS = -I./includes
CC = gcc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror $(INCS)
INCLIB = -Llibft -lft

LIBFT = ./libft

SRCS =	./src/main.c \
		./src/get_next_line.c \
		./src/builtin_cd.c \
		./src/builtin_pwd.c \
		./src/builtin_echo.c \
		./src/process_line.c \
		./src/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	# $(MAKE) clean -C $(LIBFT)

fclean: clean
	# $(MAKE) fclean -C $(LIBFT)
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re