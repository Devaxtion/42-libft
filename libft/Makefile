# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 11:54:19 by leramos-          #+#    #+#              #
#    Updated: 2025/04/10 11:56:08 by leramos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE_DIR = srcs
HEADER_DIR = includes

MY_SOURCES = ${SOURCE_DIR}/ft_putchar.c \
			${SOURCE_DIR}/ft_swap.c \
			${SOURCE_DIR}/ft_putstr.c \
			${SOURCE_DIR}/ft_strlen.c \
			${SOURCE_DIR}/ft_strcmp.c

MY_HEADERS = ${HEADER_DIR}/ft.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

all: ${NAME}

${NAME}: ${MY_OBJECTS}
	ar rc ${NAME} $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all