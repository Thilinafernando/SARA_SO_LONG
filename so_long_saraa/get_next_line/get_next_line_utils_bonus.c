/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:15:09 by xhamzall          #+#    #+#             */
/*   Updated: 2025/01/18 17:28:42 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s1 = 0;
	len_s2 = 0;
	str = NULL;
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2) + 1);
	if (str == NULL)
		return (NULL);
	if (s1)
		ft_memcpy(str, s1, len_s1);
	if (s2)
		ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = 0;
	if (s)
		len = ft_strlen(s);
	else
		len = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = '\0';
		i++;
	}
}
