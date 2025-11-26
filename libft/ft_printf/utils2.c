/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:38:46 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 13:39:06 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_putnbr(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_unsigned_putnbr(n / 10);
	c = (n % 10 + '0');
	ft_putchar_fd(c, 1);
}

int	ft_unsigned_numlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_get_params(int len, t_flags f, int *arr)
{
	int	total;

	arr[0] = 0;
	if (f.has_precision && f.precision > len)
		arr[0] = f.precision - len;
	total = len + arr[0];
	arr[1] = 0;
	if (f.width > total)
		arr[1] = f.width - total;
}

void	ft_putnbr_long(long n)
{
	char	c;

	if (n >= 10)
		ft_putnbr_long(n / 10);
	c = (n % 10 + '0');
	ft_putchar_fd(c, 1);
}
