
#include "../so_long.h"

int	back_tracking(int x, int y, t_long *map)
{
	if (search_pos(x, y, map) != 0)
		return (1);//wrong
	if (map->dmap[y][x] == 'C')
		map->getpaw += 1;
	map->dmap[y][x] = 'X';//all pos he is been to, gotta be x
	if (search_pos((x + 1), y, map) == 0)
		back_tracking((x + 1), y, map);
	if (search_pos((x - 1), y, map) == 0)
		back_tracking((x - 1), y, map);
	if (search_pos(x, (y + 1), map) == 0)
		back_tracking(x, (y + 1), map);
	if (search_pos(x, (y - 1), map) == 0)
		back_tracking(x, (y - 1), map);
	return (0);
}

int	valid_map(char *file, t_long *map)
{
	map->dmap = NULL;
	if (!copy_map(file, map))
		return (write(2, "Error\n", 6), -1);
	find_pos(map);
	map->getpaw = 0;
	map->exit = 0;
	back_tracking(map->x, map->y, map);
	if ((map->paw == map->getpaw) && (map->exit == 1))
		return (freemtx(map->dmap), map -> dmap = NULL, 0);
	else
		return (freemtx(map->dmap), map -> dmap = NULL, -1);//mappa non valida
	freemtx(map->dmap);
	map->dmap = NULL;
	return (0);
}

int	check_all(char *file, t_long *map)
{
	if (count_line(file, map) == -1)
		return (-1);
	if (readmap(file, map) == NULL)
		return (write(2, "Error1\n", 8), freemtx(map->base), -1);
	if (check_wall(map) == -1)
		return (write(2, "Error2\n", 8), freemtx(map->base), -1);
	if (check_c(map) == -1)
		return (write(2, "Error3\n", 8), freemtx(map->base), -1);
	if (pe(map) == -1)
		return (write(2, "Error4\n", 8), freemtx(map->base), -1);
	if (sign(map) == -1)
		return(write(2, "Error5\n", 8), freemtx(map->base), -1);
	if (valid_map(file, map) == -1)
		return (write(2, "Error6\n", 8), freemtx(map->base), -1);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	t_long	map;

	if (argc < 2)
		return (1);
	if (check_all(argv[1], &map) == -1)
		return (-1); // map.grid is already freed in chack_all
	else
		ft_printf("everything's fine ˙ᵕ˙");
	freemtx(map.base);
	return (0);
}*/
