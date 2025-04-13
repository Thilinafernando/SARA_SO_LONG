# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 14:48:47 by xhamzall          #+#    #+#              #
#    Updated: 2025/01/13 14:33:58 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_put_chr_str.c ft_utily.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c ${CFLAGS} $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
