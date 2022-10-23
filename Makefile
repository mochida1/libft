# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 12:44:01 by hmochida          #+#    #+#              #
#    Updated: 2022/10/23 15:00:39 by hmochida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=clang

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

SRC=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ=$(SRC:.c=.o)

$(NAME): libft.h
	$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS_OBJ)

re: fclean all

.PHONY: clean fclean
