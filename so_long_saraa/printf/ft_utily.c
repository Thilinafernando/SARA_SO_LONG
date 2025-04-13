/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utily.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:08:21 by xhamzall          #+#    #+#             */
/*   Updated: 2025/04/12 18:26:22 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fft_putnbr(int nbr)
{
	long	nb;
	int		len;
	int		result;

	nb = nbr;
	len = 0;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		len += fft_putnbr(nb / 10);
	result = (nb % 10) + '0';
	len += write(1, &result, 1);
	return (len);
}

int	ft_unsigned(unsigned int nbr)
{
	int		len;
	char	result;

	len = 0;
	if (nbr > 9)
	{
		len += ft_unsigned(nbr / 10);
	}
	result = (nbr % 10) + '0';
	len += write(1, &result, 1);
	return (len);
}

int	ft_hex(unsigned long nb, char is_uppercase)
{
	char			*up;
	char			*low;
	unsigned int	temp;
	int				len;

	up = "0123456789ABCDEF";
	low = "0123456789abcdef";
	len = 0;
	if (nb == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	if (nb != 0)
	{
		if ((nb > 15))
			len += ft_hex((nb / 16), is_uppercase);
	}
	temp = (nb % 16);
	if (is_uppercase == 'X')
		len += ft_putchar(up[temp]);
	else if (is_uppercase == 'x')
		len += ft_putchar(low[temp]);
	return (len);
}

int	ft_ptr(unsigned long memory)
{
	int					len;

	len = 0;
	if (!memory)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_hex(memory, 'x');
	return (len);
}
