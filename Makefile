# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 11:49:22 by lleal-go          #+#    #+#              #
#    Updated: 2025/01/24 15:19:38 by lleal-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Src directory
NAME = so_long
SRC_DIR = .
INC_DIR = .

#List of files
SRC = $(SRC_DIR)/src/open_window.c \
	$(SRC_DIR)/src/read.c \
	$(SRC_DIR)/src/validate.c \
	$(SRC_DIR)/src/main.c
	
#objects

OBJ = $(SRC:$(SRC_DIR)/%.c=%.o)

#Compilators and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_DIR = library/minilibx-linux

#Libft directories
LIBFT_DIR = library/libft
LIBFT = $(LIBFT_DIR)/libft.a

#Link flags
LDFLAGS = -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lX11 -lXext -lm


#Main rule
all: $(NAME)

#Compile the game
$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR) -c $< -o $@
#Compile Libft
#$(LIBFT):
#	$(MAKE) -C $(LIBFT_DIR)

#Cleaning
clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

#Rebuild
re: fclean all

.PHONY: all clean fclean re