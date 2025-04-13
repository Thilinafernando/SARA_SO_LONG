#include "../so_long.h"

void	freemtx(char **mxt)
{
	int	i;

	i = 0;
	if (!mxt)
		return ;
	while (mxt[i])
	{
		free(mxt[i]);
		i++;
	}
	free(mxt);
}

int	move_check(t_play *play, size_t n_x, size_t n_y)
{
	if (!play || !play-> map.base)
		return (-1);
	if (n_x >= play -> map.l || n_y>= play -> map.h)
		return (-1);
	if (play -> map.base[n_y] == NULL)
		return (-1);
	return (0);
}

void exit_win(t_play *play)
{
	if (play -> map.paw == 0)
	{
		ft_printf("Moves %d\n", play->moves + 1);
		ft_printf("Wow You Win!!\n");
		cls_win(play);
	}
}


int	img_check(char *file)
{
	int		fd;
	size_t	len;

	if (!file || ft_strlen(file) < 4)
	return (-1);
	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".xpm", 4) != 0)
	return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	return (-1);
	return (fd);
}

int cls_win(t_play *play)
{
	dest_img(play);
	exit(1);
	return (0);
}
