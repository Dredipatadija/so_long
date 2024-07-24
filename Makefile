# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arenilla <arenilla@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 19:52:09 by arenilla          #+#    #+#              #
#    Updated: 2024/05/22 10:33:27 by arenilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./so_long.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = so_long.h

SOURCES = main.c parse_c_map.c parse.c printmsg.c utils_map.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS) $(OBJECTSB)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re
