# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 11:22:15 by ymeziane          #+#    #+#              #
#    Updated: 2023/10/25 11:22:15 by ymeziane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror 

MLX_DIR = ./MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS = -L$(MLX_DIR) -ldl -lglfw -pthread -lm
INCLUDES = -I./inc -I./libft/inc -I$(MLX_DIR)

LIBFT = libft/libft.a
LIBFT_DIR = libft

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main read_map init_frames init_struct valid_map valid_map_utils load_textures \
            display_map display_map_utils utils movement game_loop free

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES:=.c))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	@echo "${GREEN}Creating executable $(NAME)${NC}"
	@$(CC) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) $(LIBFT) -no-pie -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "${YELLOW}Compiling $<${NC}"
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "${GREEN}Building libft${NC}"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@echo "${GREEN}Building MLX42${NC}"
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "${RED}Cleaning object files${NC}"
	@rm -rf $(OBJ_DIR)
	@echo "${YELLOW}Cleaning libft${NC}"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "${RED}Removing executable $(NAME)${NC}"
	@rm -f $(NAME)
	@echo "${YELLOW}Full clean of libft${NC}"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re