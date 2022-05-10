/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:37:34 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/30 12:11:41 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (ft_printstr("(null)"));
	else
	{
		while (str[++i] != '\0')
			write(1, &str[i], 1);
		return (i);
	}
}

void	print_nbr(int n)
{
	if (n > 9)
		print_nbr(n / 10);
	ft_printchar((n % 10) + 48);
}

int	ft_printnbr(int n)
{
	int	basamak_s;
	int	sayi;

	if (n == -2147483648)
		return (ft_printstr("-2147483648"));
	sayi = n;
	basamak_s = 0;
	if (!n)
	{
		ft_printchar(48);
		return (1);
	}
	while (sayi != 0 && ++basamak_s)
		sayi /= 10;
	if (n < 0 && ++basamak_s)
	{
		ft_printchar('-');
		n *= -1;
	}
	if (n)
		print_nbr(n);
	return (basamak_s);
}

int	ft_printchar_hex(unsigned int x, char format)
{
	static int	i;
	char		c;

	i = 0;
	c = x % 16 + 48;
	if (x)
		if (x / 16 != 0)
			ft_printchar_hex(x / 16, format);
	if (x % 16 < 10 && ++i)
		write(1, &c, 1);
	else
	{
		c += 39;
		if (format == 'X')
			c -= 32;
		write(1, &c, 1);
		++i;
	}
	return (i);
}

int	ft_print_unsigned_char(unsigned int u)
{
	static int	i;
	char		c;

	c = u % 10 + 48;
	i = 0;
	if (u)
		if (u / 10 != 0)
			ft_print_unsigned_char(u / 10);
	write(1, &c, 1);
	return (++i);
}
