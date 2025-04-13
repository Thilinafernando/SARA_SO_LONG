/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:14:05 by sara              #+#    #+#             */
/*   Updated: 2025/04/12 12:00:53 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_open(char *file)
{
	int		fd;
	size_t	len;

	if (!file || ft_strlen(file) < 4)
		return (-1);
	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".ber", 4) != 0)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	count_line(char *file, t_long *map)//calcola h e len
{
	int		fd;
	char	*line;

	if (check_open(file) < 0)
		return (write(2, "wrong file\n", 11), -1);
	fd = open(file, O_RDONLY);
	map->h = 0;
	line = get_next_line(fd);
	if (!line)
		return (write(2, "gnl failed\n", 11), close(fd), -1);
	map->l = ft_strlen(line) -1;
	while (line)
	{
		if (map->l != ft_strlen(line) - 1 && (line[0] != '\n'))
			return (write(2, "wrong lenght\n", 13), free(line), close(fd), -1);
		if (line[0] != '\n')
			map->h++;
		else
			return (write(2, "wrong height\n", 13), free(line), close(fd), -1);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (map->h);
}

char	**readmap(char *file, t_long *map)
{
	int		fd;
	int		i;
	char	*line;

	map->base = malloc((count_line(file, map) + 1) * sizeof(char *));
	if (!map->base)
		return (freemtx(map->base), NULL);
	fd = check_open(file);
	if (fd < 0)
		return (freemtx(map->base), write(2, "Error: open\n", 12), NULL);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map->base[i] = ft_strdup(line);//leggo la linea e la metto in map
		free (line);//freo per next gnl lread
		if (!map->base[i])
			return (freemtx(map->base), write(2, "Error1\n", 7), NULL);
		line = get_next_line(fd);//alloco next line if exists
		i++;
	}
	map->base[i] = NULL;
	close (fd);
	return (map->base);//ritorna matrix map
}

int	check_wall(t_long *map)
{
	size_t	i;//col
	size_t	j;//row
	size_t	len;

	i = 0;
	len = ft_strlen(map->base[i]) - 2;//i has strlen lenght
	while (map->base[i])
	{
		j = 0;
		while (map->base[i][j] && map->base[i][j] != '\n')
		{
			if ((i == 0) && map->base[i][j] != '1')//se le j alla prima riga non sono 1
				return (-1);
			if ((i == map->h - 1) && map->base[i][j] != '1')//se le j all'ultima riga non sono 1
				return (-1);
			if (j == 0 && map->base[i][j] != '1')//if not 1 the firsts
				return (-1);
			if (((j == len) && (map -> base[i][j] != '1')))//if last is not 1
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	pe(t_long *map)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	i = 0;
	exit = 0;
	player = 0;
	while (map->base[i])
	{
		j = 0;
		while(map->base[i][j])
		{
			if (map -> base[i][j] == 'P')
				player++;
			if (map -> base[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 1 && player == 1)
		return (0);
	return(-1);
}
