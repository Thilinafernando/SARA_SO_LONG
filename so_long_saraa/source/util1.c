
#include "../so_long.h"

void	img_win(t_play *play, size_t x, size_t y)
{
	if (play -> map.base[y][x] == '1')
		mlx_put_image_to_window(play->mlx,
			play->win, play->wall, x * 64, y * 64);
	else if (play->map.base[y][x] == '0')
		mlx_put_image_to_window(play->mlx,
			play->win, play->floor, x * 64, y * 64);
	else if (play->map.base[y][x] == 'P')
		mlx_put_image_to_window(play->mlx,
			play->win, play->player, x * 64, y * 64);
	else if (play->map.base[y][x] == 'C')
		mlx_put_image_to_window(play->mlx,
			play->win, play->coll, x * 64, y * 64);
	else if (play->map.base[y][x] == 'E')
		mlx_put_image_to_window(play->mlx,
			play->win, play->exit, x * 64, y * 64);
}
