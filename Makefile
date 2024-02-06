# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 17:28:22 by pabertha          #+#    #+#              #
#    Updated: 2024/02/06 17:28:23 by pabertha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

VPATH = src/

SRC = main.c \
	check_elements.c \
	check_path.c \
	display_map.c \
	handle_input.c \
	handle_map.c \
	initialize.c \
	move_enemy.c \
	parse_everything.c \
	secure_destroy.c

HEADER = so_long.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

RM = rm -rf

LIBFT = libs/libft
LIBMLX = libs/mlx

MLX_FLAGS = -lXext -lX11

LIBS = -L $(LIBFT) -lft -L $(LIBMLX) -lmlx

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o : %.c so_long.h
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : all

clean :
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)
	$(RM) $(OBJ_DIR)

fclean : clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re : fclean all

everything : all clean
	make everything -C $(LIBFT)
	norminette -R CheckForbiddenSourceHeader $(VPATH) $(HEADER)

.PHONY : all bonus clean fclean re everything
.SILENT :
