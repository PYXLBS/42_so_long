# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 17:16:25 by pabertha          #+#    #+#              #
#    Updated: 2024/02/06 17:30:21 by pabertha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

VPATH = ft_printf:get_next_line

SRC_LIBFT_MANDATORY = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

SRC_LIBFT_BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

SRC_FT_PRINTF_MANDATORY = ft_convert.c \
	ft_printf.c \
	ft_vtoi.c

SRC_GET_NEXT_LINE_MANDATORY = get_next_line.c

SRC_GET_NEXT_LINE_BONUS = get_next_line_bonus.c

SRCS = $(SRC_LIBFT_MANDATORY) $(SRC_LIBFT_BONUS) \
	$(SRC_FT_PRINTF_MANDATORY) \
	$(SRC_GET_NEXT_LINE_MANDATORY) $(SRC_GET_NEXT_LINE_BONUS)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

OBJ_DIR = obj/
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c libft.h
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

everything : all clean
	norminette -R CheckForbiddenSourceHeader

.PHONY : all clean fclean re everything
.SILENT :
