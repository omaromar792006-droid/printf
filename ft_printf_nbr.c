/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaljausi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:58:28 by oaljausi          #+#    #+#             */
/*   Updated: 2026/10/29 14:58:58 by oaljausi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	num;
	int		count;
	char	oo;

	count = 0;
	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	oo = (num % 10) + '0';
	write(1, &oo, 1);
	count++;
	return (count);
}

int	ft_put_unsigned(unsigned int n)
{
	int		count;
	char	o;

	count = 0;
	if (n >= 10)
		count += ft_put_unsigned(n / 10);
	o = (n % 10) + '0';
	write(1, &o, 1);
	count++;
	return (count);
}
