/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaljausi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:57:07 by oaljausi          #+#    #+#             */
/*   Updated: 2026/10/29 14:58:03 by oaljausi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned long n, char format)
{
	int		count;
	char	*b;
	char	o;

	count = 0;
	if (format == 'x')
		b = "0123456789abcdef";
	else
		b = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	o = (b[n % 16]);
	write(1, &o, 1);
	count++;
	return (count);
}

int	ft_putptr(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)p, 'x');
	return (count);
}
