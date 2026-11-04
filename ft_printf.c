/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaljausi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:47:43 by oaljausi          #+#    #+#             */
/*   Updated: 2026/10/29 14:47:50 by oaljausi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	chech_format(char lo, va_list args)
{
	int	count;

	count = 0;
	if (lo == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (lo == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (lo == 'd' || lo == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (lo == 'x' || lo == 'X')
		count += ft_puthex(va_arg(args, unsigned int), lo);
	else if (lo == 'u')
		count += ft_put_unsigned(va_arg(args, unsigned int));
	else if (lo == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (lo == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			len += chech_format(format[i], args);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
