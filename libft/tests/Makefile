# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 17:38:03 by leramos-          #+#    #+#              #
#    Updated: 2025/04/13 17:38:03 by leramos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Tests for libft

# Variables
NAME = libft_tests
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Project structure
SRC_DIR = ..
LIB_DIR = $(SRC_DIR)
TEST_DIR = .
UNITS_DIR = $(TEST_DIR)/unit

# Files
LIBFT = $(LIB_DIR)/libft.a
UNITS := $(wildcard $(UNITS_DIR)/test_*.c)
TESTS += $(UNITS) $(TEST_DIR)/main.c

# Rules
all: $(NAME)

$(NAME): $(TESTS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIB_DIR) -lft -o $@

clean:
	$(RM) $(NAME)

fclean: clean

re: clean all

# Phony targets
.PHONY: all clean fclean re