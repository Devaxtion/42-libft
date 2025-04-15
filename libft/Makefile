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

# Variables
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Project structure
SRC_DIR = .
HDR_DIR = $(SRC_DIR)

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)
HDRS = $(wildcard $(HDR_DIR)/*.h)
OBJS = $(SRCS:.c=.o)

# Rules
all: ${NAME}

${NAME}: ${OBJS}
	$(AR) ${NAME} $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re