/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:45:34 by xhamzall          #+#    #+#             */
/*   Updated: 2025/04/12 18:18:46 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstring(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (fft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_hex(va_arg(args, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_hex(va_arg(args, unsigned int), 'X'));
	else if (c == 'p')
		return (ft_ptr(va_arg(args, unsigned long)));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (write(1, &c, 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_format(str[++i], args);
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end (args);
	return (count);
}

// int main ()
// {
// 	int s = -1;

// 	printf("Printf %p ", 1);
// 	printf("\n");
// 	ft_printf("Mio %p ", -1);
// }
