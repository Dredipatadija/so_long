# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arenilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 17:52:18 by arenilla          #+#    #+#              #
#    Updated: 2024/07/24 17:52:27 by arenilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INC)

INC = so_long.h ./minilibx-linux/mlx.h ./libft/libft.h

LDFLAGS = - -lft -L$(MLX_DIR) $(MLX) $(MLX_LINUX) -lX11 -lXext -lm -lbsd -L$(PRINTF_DIR) $(PRINTF) -lftprintf
SOURCES = *.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(INCLUDE) $(OBJECTS)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS) $(OBJECTSB)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re
