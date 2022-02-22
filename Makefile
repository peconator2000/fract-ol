NAME = fractol
INCLUDES = fractol.h
SRC = ft_atoi.c                       ft_complex_operations.c         ft_fractol.c                    ft_hook_control.c               ft_utils.c\
ft_choose_frac.c                ft_coord_transformations.c      ft_functions_frac.c             ft_main.c
OBJ = $(SRC:.c=.o)
REM = rm -rf
MLX = mlx/libmlx.a

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(INCLUDES) $(OBJ) $(SRC) Makefile
	gcc -Wall -Wextra -Werror -I $(INCLUDES) $(OBJ) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

clean:
	$(REM) $(OBJ)

fclean:	clean
	$(REM) $(NAME)

re:	fclean all
