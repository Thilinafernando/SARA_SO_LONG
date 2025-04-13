#include "../so_long.h"

int win_create(t_play *play)
{
	int win_l;
	int win_h;

	win_l = play -> map.l * 64;
	win_h = play -> map.h * 64;
	play -> win = mlx_new_window(play -> mlx, win_l, win_h, "so_long");
	if (!play -> win)
	{
		mlx_destroy_display(play -> mlx);
		free (play -> mlx);
		freemtx(play -> map.base);
		return (-1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_play	game;

	ft_memset(&game, 0, sizeof(t_play));
	game.moves = 0;
	if (argc != 2)
		return (write(2, "Error\n", 6), -1);
	if (check_all(argv[1], &game.map) == -1)
		return (-1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (write(2, "Error\n", 6), freemtx(game.map.base), -1);
	win_create(&game);
	place_img(&game);
	map_load(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, cls_win, &game);
	mlx_loop(game.mlx);
	dest_img(&game);
	return (0);
}
