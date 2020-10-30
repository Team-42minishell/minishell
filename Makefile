NAME = minishell

INCS = -I./includes
CC = gcc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror $(INCS)
INCLIB = -Llibft -lft

LIBFT = ./libft

SRCS =	./src/cd.c \
		./src/execute.c \
		./src/ft_is_format.c \
		./src/pwd.c \
		./src/utils_get_parser.c \
		./src/converter.c \
		./src/execve.c \
		./src/get_next_line.c \
		./src/setting.c \
		./src/utils_converter.c \
		./src/utils_pipe.c \
		./src/echo.c \
		./src/execve2.c \
		./src/lexer.c \
		./src/signal.c \
		./src/utils_env.c \
		./src/utils_set_parser.c \
		./src/env.c \
		./src/exit.c \
		./src/main.c \
		./src/tokenizer.c \
		./src/utils_fd.c \
		./src/utils_string.c \
		./src/error.c \
		./src/export.c \
		./src/parser.c \
		./src/unset.c \
		./src/utils_free.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re
