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
SRCS_DIR = .

# Files
FILES = ft_atoi ft_bzero ft_calloc ft_isalnum \
		ft_isalpha ft_isascii ft_isdigit ft_isprint \
		ft_itoa ft_memchr ft_memcmp ft_memcpy \
		ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
		ft_putstr_fd ft_split ft_strchr ft_strdup \
		ft_striteri ft_strjoin ft_strlcat ft_strlcpy \
		ft_strlen ft_strmapi ft_strncmp ft_strnstr \
		ft_strrchr ft_strtrim ft_substr \
		ft_tolower ft_toupper

FILES_BONUS = ft_lstadd_back_bonus ft_lstadd_front_bonus ft_lstclear_bonus \
			ft_lstdelone_bonus ft_lstiter_bonus ft_lstlast_bonus ft_lstmap_bonus \
			ft_lstnew_bonus ft_lstsize_bonus

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
SRCS_BONUS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES_BONUS)))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Rules
all: ${NAME}

${NAME}: ${OBJS}
	$(AR) $@ $^

# bonus: ${OBJS_BONUS}
# 	$(AR) ${NAME} $(OBJS_BONUS)
bonus: ${NAME} ${OBJS_BONUS}
	${AR} ${NAME} ${OBJS_BONUS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re