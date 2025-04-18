/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmtxlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:37:35 by odudniak          #+#    #+#             */
/*   Updated: 2023/11/29 21:13:08 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memmtxlen(void *mem)
{
	unsigned char	**m;
	int				i;

	i = 0;
	m = (unsigned char **)mem;
	while (m && m[i])
		i++;
	return (i);
}
