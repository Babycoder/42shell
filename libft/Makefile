# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayghazal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 23:45:50 by ayghazal          #+#    #+#              #
#    Updated: 2019/10/27 02:34:15 by ayghazal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclan re

NAME = libft.a

SRC = ft_isalpha.c ft_memccpy.c ft_strchr.c m_strlen.c \
		ft_atoi.c ft_putchar_fd.c ft_strdup.c m_substr.c\
	  	ft_bzero.c ft_isdigit.c  ft_putendl_fd.c ft_strjoin.c ft_strncmp.c \
	  	ft_calloc.c ft_memcpy.c  \
	  	ft_isalnum.c ft_putstr_fd.c  ft_split.c\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
re: fclean all

bonus:
	echo ok
