/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:07:54 by xhamzall          #+#    #+#             */
/*   Updated: 2025/04/12 17:54:53 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstring(char *str);
int	fft_putnbr(int nbr);
int	ft_unsigned(unsigned int nbr);
int	ft_hex(unsigned long nb, char is_uppercase);
int	ft_ptr(unsigned long memory);
int	ft_printf(const char *str, ...);

#endif
