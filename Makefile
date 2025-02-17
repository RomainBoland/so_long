NAME = so_long
NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I libft/includes/ -I mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
MINECRAFT_GREEN = \033[38;5;70m
RESET = \033[0m
BOLD = \033[1m

SRC = srcs/main.c srcs/map_parser.c srcs/map_read.c srcs/map_utils.c srcs/map_validation.c \
	srcs/map_path.c srcs/texture_handler.c srcs/game.c srcs/utils.c srcs/init_game.c \
	srcs/render.c srcs/move_player.c

SRC_BONUS = srcs_bonus/main.c srcs_bonus/map_parser.c srcs_bonus/map_read.c \
	srcs_bonus/map_utils.c srcs_bonus/map_validation.c srcs_bonus/map_path.c \
	srcs_bonus/texture_handler.c srcs_bonus/game.c srcs_bonus/utils.c \
	srcs_bonus/init_game.c srcs_bonus/render.c srcs_bonus/move_player.c \
	srcs_bonus/enemy.c srcs_bonus/render_player.c srcs_bonus/handle_flower.c

OBJ_DIR = objects/
OBJ_BONUS_DIR = objects_bonus/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR), $(notdir $(SRC_BONUS:.c=.o)))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = mlx/
MLX = $(MLX_DIR)libmlx.a

TOTAL_FILES := $(words $(SRC))
TOTAL_FILES_BONUS := $(words $(SRC) $(SRC_BONUS))
CURRENT_FILE = 0

define update_progress
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(MINECRAFT_GREEN)Progress: [%-50s] %3d%%$(RESET)" "$$(printf '#%.0s' $$(seq 1 $$(($(CURRENT_FILE) * 50 / $(TOTAL_FILES)))))" "$(PERCENTAGE)"
endef

define update_progress_bonus
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	$(eval PERCENTAGE=$(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES_BONUS)))))
	@printf "\r$(MINECRAFT_GREEN)Progress: [%-50s] %3d%%$(RESET)" "$$(printf '#%.0s' $$(seq 1 $$(($(CURRENT_FILE) * 50 / $(TOTAL_FILES_BONUS)))))" "$(PERCENTAGE)"
endef

all: $(OBJ_DIR) $(LIBFT) $(MLX) $(NAME)
	@printf "\n$(MINECRAFT_GREEN)$(BOLD)Compilation completed!$(RESET)\n"

bonus: $(OBJ_DIR) $(OBJ_BONUS_DIR) $(LIBFT) $(MLX) $(NAME) $(NAME_BONUS)
	@printf "\n$(MINECRAFT_GREEN)$(BOLD)Bonus compilation completed!$(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

$(LIBFT):
	@printf "$(MINECRAFT_GREEN)Building libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@printf "$(MINECRAFT_GREEN)Building MinilibX...$(RESET)\n"
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	@printf "\n$(MINECRAFT_GREEN)$(BOLD)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(MLX_FLAGS)

$(NAME_BONUS): $(OBJ_BONUS)
	@printf "\n$(MINECRAFT_GREEN)$(BOLD)Linking bonus objects...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS)

$(OBJ_DIR)%.o: srcs/%.c includes/so_long.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call update_progress)

$(OBJ_BONUS_DIR)%.o: srcs_bonus/%.c includes/so_long.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call update_progress_bonus)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@printf "$(MINECRAFT_GREEN)Objects cleaned$(RESET)\n"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(MLX)
	@rm -f $(NAME) $(NAME_BONUS)
	@printf "$(MINECRAFT_GREEN)Executables cleaned$(RESET)\n"

re: fclean all

.PHONY: all bonus clean fclean re
