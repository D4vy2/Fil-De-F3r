NAME = libft.a

SRC = basic_functions.c basic_functions_2.c ft_open_file.c \
      get_next_line.c height.c init.c invert.c line.c \
      main.c mlx_expose_hook.c mlx_manage.c read_map.c \
      split.c gnl_functions.c draw.c ft_check_ret.c

DEL = rm -rf

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo
	@echo "make: $(NAME) created."
	@echo

clean:
	@$(DEL) $(OBJ)
	@echo
	@echo "clean: .o -> deleted."
	@echo

fclean: clean
	@$(DEL) $(NAME)
	@echo "fclean: $(NAME) deleted."
	@echo

re: fclean all
	@echo "re: $(NAME) reloaded."

.PHONY: clean fclean all re
