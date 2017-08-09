NAME = fdf
LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_DIR = libft
MLX_DIR = minilibx_macos

DEL = rm -rf

INCLUDE = minilibx_macos/
LIBRARY = minilibx_macos/

FLAG = -lmlx

FRAMEWORK = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	@(cd $(LIBFT_DIR) && $(MAKE))
	@(cd $(MLX_DIR) && $(MAKE))
	@gcc -o $(NAME) -I $(INCLUDE) -L $(LIBRARY) $(FLAG) $(FRAMEWORK) $(LIBFT)
	@echo
	@echo "      --> fdf created."
	@echo

clean:
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@(cd $(MLX_DIR) && $(MAKE) $@)

fclean: 
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@(cd $(MLX_DIR) && $(MAKE) $@)
	@$(DEL) $(NAME)
	@echo
	@echo "      --> fdf deleted."
	@echo

re: fclean all

.PHONY: clean fclean all re
