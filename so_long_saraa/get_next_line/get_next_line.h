/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:15:41 by xhamzall          #+#    #+#             */
/*   Updated: 2025/02/25 14:38:01 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_get_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);

#endif
