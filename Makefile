NAME = minishell

INCS = -I./includes
CC = gcc
RM = rm -f
# CFLAGS = -g -Wall -Wextra -Werror $(INCS)
CFLAGS = -g $(INCS)
INCLIB = -Llibft -lft

LIBFT = ./libft

SRCS =	./src/main.c \
		./src/get_next_line.c \
		./src/parse_line.c \
		./src/parse_quote.c \
		./src/exec_cmds.c \
		./src/builtin_cd.c \
		./src/builtin_pwd.c \
		./src/builtin_echo.c \
		./src/builtin_env.c \
		./src/builtin_export.c \
		./src/builtin_export2.c \
		./src/builtin_unset.c \
		./src/builtin_exit.c \
		./src/exec_cmd_path_env.c \
		./src/utils.c \
		./src/utils_env.c \
		./src/tokenizer.c \
		./src/utils_memory.c \
		./src/lexer.c \
		./src/utils_string.c \
		./src/parser.c \
		./src/utils_get_parser.c \
		./src/utils_set_parser.c \
		./src/converter.c \
		./src/utils_converter.c \
		./src/execute.c \
		./src/pwd.c \
		./src/cd.c \
		./src/echo.c \
		./src/env.c \
		./src/export.c \
		./src/unset.c \
		./src/utils_free.c \
		./src/signal.c \
		./src/exit.c \
		./src/error.c \
		./src/setting.c \
		./src/ft_is_format.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	# $(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	# $(MAKE) clean -C $(LIBFT)

fclean: clean
	#$(MAKE) fclean -C $(LIBFT)
	rm -rf $(OBJS)
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re
