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

# Variables
NAME = libft_tests
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Project structure
SRC_DIR = ..
TEST_DIR = .
UNITS_DIR = $(TEST_DIR)/unit

# Files
SRCS := $(wildcard $(SRC_DIR)/*.c)
UNITS := $(wildcard $(UNITS_DIR)/test_*.c)
TESTS += $(UNITS) $(TEST_DIR)/main.c

# Rules
all: $(NAME)

$(NAME): $(SRCS) $(TESTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: clean all

# Phony targets
.PHONY: all clean fclean re