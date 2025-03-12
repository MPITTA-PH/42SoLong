# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 12:03:32 by mpitta-p          #+#    #+#              #
#    Updated: 2025/03/12 18:29:43 by mpitta-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L $(MINILIBX_DIR) -lmlx -Ilmlx -lXext -lX11

# Diretórios e arquivos de biblioteca
LIBFT_DIR = libs/libft
FT_PRINTF_DIR = libs/printf
GNL_DIR = libs/gnl
MINILIBX_DIR = libs/minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
GNL = $(GNL_DIR)/get_next_line.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# Diretórios e arquivos fonte
SOURCES = srcs/checker_args.c srcs/events.c srcs/ft_error.c srcs/game_init.c srcs/init_map.c srcs/map_elems.c srcs/open_win.c srcs/path_validation.c srcs/render.c srcs/so_long.c srcs/validate_map.c

SO_LONG_OBJ_DIR = srcs/objs
SO_LONG_OBJS = $(SOURCES:srcs/%.c=$(SO_LONG_OBJ_DIR)/%.o)

# Cores para a saída do terminal
CLR_RMV	:= \033[0m
RED 	:= \033[1;31m
GREEN 	:= \033[1;32m
YELLOW 	:= \033[1;33m
BLUE 	:= \033[1;34m
CYAN 	:= \033[1;36m

# Regra principal
all: $(NAME)

# Criação do binário final
$(NAME): $(SO_LONG_OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) $(MINILIBX)
	@echo "$(CLR_RMV)$(GREEN)⏳ Compiling $(YELLOW)Sources... 🤓"
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(SO_LONG_OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) $(MINILIBX) -o $(NAME)
	@echo "$(BLUE)🖨️  All tasks done successfully!🤓"

# Compilação dos objetos do so_long
$(SO_LONG_OBJ_DIR)/%.o: srcs/%.c
		@mkdir -p $(SO_LONG_OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

# Compilação de libft
$(LIBFT):
	@echo "$(YELLOW)Compiling libft ...🛠️${CLR_RMV}"
	@make -C $(LIBFT_DIR) --no-print-directory > /dev/null 2>&1
	@echo "$(GREEN)Libft compiled"

# Compilação de printf
$(FT_PRINTF):
	@echo "$(YELLOW)Compiling printf ...🛠️${CLR_RMV}"
	@make -C $(FT_PRINTF_DIR) --no-print-directory > /dev/null 2>&1
	@echo "$(GREEN)Printf compiled"

# Compilação do get_next_line
$(GNL):
	@echo "$(YELLOW)Compiling get_next_line ...🛠️${CLR_RMV}"
	@$(MAKE) -C $(GNL_DIR) --no-print-directory
	@echo "$(GREEN)Get_next_line compiled"

$(MINILIBX):
		@echo "$(GREEN)Compiling minilibx ..."
		@make -C $(MINILIBX_DIR) all --silent > /dev/null 2>&1
		@echo "$(GREEN)Minilibx compiled"

# Limpeza dos objetos
clean:
	@echo "$(RED)Deleting $(CYAN)objects ..."
	@rm -rf $(SO_LONG_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(FT_PRINTF_DIR) clean --no-print-directory
	@$(MAKE) -C $(GNL_DIR) clean --no-print-directory
	@echo "$(BLUE)All objects cleaned successfully! 🧹🗑️"

# Limpeza completa (inclui os binários)
fclean: clean
	@echo "$(RED)Deleting $(CYAN)$(NAME) binary ..."
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory > /dev/null 2>&1
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean --no-print-directory > /dev/null 2>&1
	@$(MAKE) -C $(GNL_DIR) fclean --no-print-directory
	@$(MAKE) -C $(MINILIBX_DIR) clean --silent > /dev/null 2>&1
	@echo "$(BLUE)Everything clean! 🧹🗑️"

# Rebuild (limpeza e reconstrução)
re: fclean all

# Definir regras como "phony" (não correspondem a arquivos reais)
.PHONY: all clean fclean re
