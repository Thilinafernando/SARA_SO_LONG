
#include "../so_long.h"

void *creat_textu(void *mlx, char *path, t_play *play)
{
	int l;
	int h;
	void *img;

	img = mlx_xpm_file_to_image(mlx, path, &l, &h);
	if(!img)
	{
		write(2, "Error\n", 6);
		dest_win(play);
		exit(1);
	}
	return(img);
}

void	place_img(t_play *play)
{
	play -> wall = creat_textu(play -> mlx, "textur/wall.xpm", play);
	play -> floor = creat_textu(play -> mlx, "textur/floor.xpm", play);
	play -> player = creat_textu(play -> mlx, "textur/player.xpm", play);
	play -> coll = creat_textu(play -> mlx, "textur/coll.xpm", play);
	play -> exit = creat_textu(play -> mlx, "textur/exit.xpm", play);

}

void	map_load(t_play *play)
{
	size_t x;
	size_t y;

	if (!play -> map.base || !play->mlx || !play->win)
		return ;
	y = 0;
	while (y < play -> map.h)
	{
		x = 0;
		while (x < play -> map.l)
		{
			img_win(play, x, y);
			x++;
		}
		y++;
	}
}

int key_hook(int keycd, t_play *play)
{
	if ( keycd == XK_w)
		mv_player(play, play -> map.x, play -> map.y -1);
	else if (keycd == XK_s)
		mv_player(play, play -> map.x, play -> map.y +1);
	else if (keycd == XK_a)
		mv_player(play, play -> map.x - 1, play -> map.y);
	else if (keycd == XK_d)
		mv_player(play, play -> map.x + 1, play -> map.y);
	else if (keycd == XK_Escape)
		cls_win(play);
	return (0);
}

void	mv_player(t_play *play, size_t n_x, size_t n_y)
{
	char pos;
	if (move_check(play, n_x, n_y) == -1)
		return ;
	pos = play->map.base[n_y][n_x];
	if ( pos == '1')
		return;
	if (pos == 'E')
	{
		exit_win(play);
		return ;
	}
	if (pos == 'C')
	{
		play -> map.paw--;
		play -> map.base[n_y][n_x] = '0';
	}
	play->map.base[play->map.y][play->map.x] = '0';
	play -> map.base[n_y][n_x] = 'P';
	play -> map.x = n_x;
	play -> map.y = n_y;
	play -> moves++;
	ft_printf("Moves %d\n", play -> moves);
	map_load(play);
}
