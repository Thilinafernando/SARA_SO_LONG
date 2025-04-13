CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -Lminilibx-linux -lXext -lX11 -lm -lbsd

INCLUDES = -I/usr/include -Iminilibx-linux -Ilibft -Iget_next_line -Iprintf

PRINTDIR = printf/
PRINT = $(PRINTDIR)libftprintf.a

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

GNL = get_next_line/
GNL_SRC = get_next_line.c get_next_line_utils.c

SRCDIR = source/
SRC = parsing.c parsing2.c parsing3.c util.c util1.c destroy.c win.c so_long.c

OBJ_DIR = obj

OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
GNL_OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRC:.c=.o)))

all: $(MLX) $(NAME)


$(NAME): $(LIBFT) $(OBJECTS) $(GNL_OBJECTS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJECTS) $(GNL_OBJECTS) -o $(NAME) $(PRINT) $(LIBFT) $(MLX_FLAGS)

$(MLX):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	cd $(MLX_DIR) && make
# Libft compiling
$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR) --quiet

# Printf compiling
$(PRINT): $(PRINTDIR)
	@$(MAKE) -C $(PRINTDIR) --quiet

$(OBJ_DIR)/%.o: $(SRCDIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Bonus object
#$(OBJ_DIR)/%.o: $(BONUSDIR)%.c
#	mkdir -p $(OBJ_DIR)
#	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# GNL
$(OBJ_DIR)/%.o: $(GNL)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(PRINTDIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) clean -C $(MLX_DIR); fi
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(PRINTDIR)
	rm -rf $(NAME)
	rm -rf $(MLX_DIR)
re: fclean all

.PHONY: all bonus clean fclean re
