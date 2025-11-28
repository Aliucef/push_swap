# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 09:29:20 by alyousse          #+#    #+#              #
#    Updated: 2025/10/30 09:29:20 by alyousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ft_isdigit.c \
		ft_strlen.c \
		ft_atoi.c ft_strdup.c ft_substr.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_strjoin.c ft_split.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf/ft_printf.c \
		ft_printf/parser.c \
		ft_printf/utils.c \
		ft_printf/print_int.c \
		ft_printf/print_unsigned.c \
		ft_printf/print_char.c \
		ft_printf/print_string.c \
		ft_printf/print_hex.c \
		ft_printf/print_pointer.c \
		ft_printf/utils2.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
