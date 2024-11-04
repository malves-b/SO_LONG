# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 17:23:31 by malves-b          #+#    #+#              #
#    Updated: 2024/09/06 10:30:04 by malves-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = so_long

FILES = $(wildcard srcs/*.c) $(wildcard libft/*.c)

OBJS = $(FILES:.c=.o)

CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBRARY = so_long.a

MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR) -lmlx
MLX_FLAGS = -lX11 -lXext -lm -lz

#API VINC
#$(NAME): $(OBJ)
#	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBRARY) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBRARY) $(MLX) $(MLX_FLAGS)

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBRARY) $(TARGET)

re: fclean all

.PHONY: all, clean, fclean, re