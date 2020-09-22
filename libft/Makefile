# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 20:19:19 by sungslee          #+#    #+#              #
#    Updated: 2020/08/08 20:38:50 by sungslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c	\
		ft_atoi.c	\
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnstr.c \
		ft_atouni.c \
		ft_ulltoa.c \
		ft_uitoa.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_is_set.c \
		ft_itoa_base.c \
		ft_lltoa.c \
		ft_lltoa_base.c
NAME = libft.a
OBJS = ${SRCS:.c=.o}
HEAD = libft.h
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

bonus : ${NAME}

$(NAME): ${HEAD} ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o : %.c %.h
		${CC} ${CFLAGS} -c ${<} -o ${@}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all

.PHONY : all bonus clean fclean re