#include "../so_long.h"

int	check_c(t_long *map)//collectables
{
	int	i;
	int	j;

	i = 0;
	map->paw = 0;
	while (map->base[i])
	{
		j = 0;
		while (map->base[i][j])
		{
			if (map->base[i][j] == 'C')
				map->paw++;
			j++;
		}
		i++;
	}
	if (map->paw != 0)
		return (map->paw);
	return (-1);
}

char	**copy_map(char *file, t_long *map)
{
	int	i;

	i = 0;
	map->dmap = malloc((count_line(file, map) + 1) * sizeof(char *));
	if (!map->dmap)
		return (freemtx(map-> dmap), NULL);
	while (i < count_line(file, map))
	{
		map->dmap[i] = ft_strdup(map->base[i]);
		if (!map->dmap[i])
			return (freemtx(map->dmap), NULL);
		i++;
	}
	map->dmap[i] = NULL;
	return (map->dmap);
}

void	find_pos(t_long *map)
{
	int	x;
	int	y;

	if (!map || !map->base)
		return ;
	y = 0;
	while (map->base[y])
	{
		x = 0;
		while (map->base[y][x])
		{
			if (map->base[y][x] == 'P')
			{//find for coordinate
				map->x = x;
				map->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	search_pos(size_t x, size_t y, t_long *map)
{
	if (x >= map->l || y >= map->h)
		return (-1);
	if (map->dmap[y][x] == '1' || map->dmap[y][x] == 'X')
		return (-1);
	if (map->dmap[y][x] == 'E')
	{
		map->exit = 1;
		return (-1);
	}
	return (0);
}

int sign(t_long *map)//checks theres no other char than the one i need
{
	int i;
	int j;

	i = 0;
	while (map->base[i])
	{
		j = 0;
		while (map->base[i][j])
		{
			if (map->base[i][j] == 'C' || map->base[i][j] == 'E' || \
				map->base[i][j] == 'P' || map->base[i][j] == '1' || \
				map->base[i][j] == '0' || map->base[i][j] == '\n')
				j++;
			else
				return (-1);
		}
		i++;
	}
	if (map->paw != 0)//its justto have a positive return
		return (map->paw);
	return (-1);
}
