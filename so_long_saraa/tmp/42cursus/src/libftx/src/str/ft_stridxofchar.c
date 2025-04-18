/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stridxofchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:19 by odudniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:13:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stridxofchar(const char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}
