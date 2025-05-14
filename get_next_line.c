/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:54:53 by tkurukul          #+#    #+#             */
/*   Updated: 2025/05/14 15:44:27 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	check_nl(char *str)
{
	int	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buffer)
{
	int		i = 0, j = 0, size;
	char	*new;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	size = ft_strlen(line) + ft_strlen(buffer);
	new = malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(line);
	return (new);
}

char	*line_creation(char *str)
{
	int		i = 0;
	char	*new;

	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = malloc((i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*save_prev(char *str)
{
	int		i = 0, j = 0, size = 0;
	char	*new;

	while (str && str[i] && str[i] != '\n')
		i++;
	if (!str || !str[i])
		return (NULL);
	i++;
	while (str[i + size])
		size++;
	new = malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	int			size;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;
	char		*tmp;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = NULL;
	if (save)
	{
		tmp = ft_strjoin(NULL, save);
		free(save);
		save = NULL;
	}
	size = 1;
	while (!check_nl(tmp) && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (free(tmp), NULL);
		buffer[size] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
			return (NULL);
	}
	if (!tmp || !tmp[0]) // End
		return (free(tmp), NULL);
	line = line_creation(tmp);
	save = save_prev(tmp);
	free(tmp);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

