NAME =		cub3D

SRC_DIR = 	srcs
MLX_DIR = 	mlx_linux
OBJS_DIR =	objs

CC =		clang
FLAGS_CC =	-Wall -Wextra -Werror
FLAGS_MLX =	-lm -lbsd -lX11 -lXext -L ./$(MLX_DIR) -lmlx

HEAD =		-I./includes -I./$(MLX_DIR)
					
MLX =		$(MLX_DIR)/libmlx.a
SRCS =		$(SRC_DIR)/main.c \
				$(SRC_DIR)/geom.c

OBJS =		$(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

RM =		/bin/rm -rf

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(OBJS) $(HEAD) $(FLAGS_CC) $(FLAGS_MLX) -o $@

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(HEAD) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PONY: all clean fclean re
