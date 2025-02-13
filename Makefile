NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I libft/includes/ -I mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
MINECRAFT_GREEN = \033[38;5;70m
RESET = \033[0m
BOLD = \033[1m

SRC = srcs/main.c srcs/map_parser.c srcs/map_read.c srcs/map_utils.c srcs/map_validation.c	\
	srcs/map_path.c srcs/texture_handler.c srcs/game.c srcs/utils.c srcs/init_game.c 		\
	srcs/render.c srcs/move_player.c

# Create objects directory path
OBJ_DIR = objects/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = mlx/
MLX = $(MLX_DIR)libmlx.a

# Count total files for progress bar
TOTAL_FILES := $(words $(SRC))
CURRENT_FILE = 0

# Progress bar function
define update_progress
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(MINECRAFT_GREEN)Progress: [%-50s] %3d%%$(RESET)" "$$(printf '#%.0s' $$(seq 1 $$(($(CURRENT_FILE) * 50 / $(TOTAL_FILES)))))" "$(PERCENTAGE)"
endef

all: $(OBJ_DIR) $(LIBFT) $(MLX) $(NAME)
	@printf "\n$(MINECRAFT_GREEN)$(BOLD)Compilation completed!$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@printf "$(MINECRAFT_GREEN)Building libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@printf "$(MINECRAFT_GREEN)Building MinilibX...$(RESET)\n"
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	@printf "\n$(MINECRAFT_GREEN)$(BOLD)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)

$(OBJ_DIR)%.o: srcs/%.c includes/so_long.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call update_progress)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@printf "$(MINECRAFT_GREEN)Objects cleaned$(RESET)\n"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(MLX)
	@rm -f $(NAME)
	@printf "$(MINECRAFT_GREEN)Executable cleaned$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re