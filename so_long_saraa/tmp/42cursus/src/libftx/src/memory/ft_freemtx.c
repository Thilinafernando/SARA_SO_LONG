/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemtx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:16 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/01 21:53:25 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_freemtx(void *mtx, size_t rows)
{
	unsigned char	**mtxp;
	size_t			i;

	if (!mtx)
		return (NULL);
	i = 0;
	mtxp = (unsigned char **) mtx;
	while (i < rows)
		free(mtxp[i++]);
	free(mtxp);
	return (NULL);
}
