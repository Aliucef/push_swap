/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:12:44 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 15:48:11 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int_len(int n, t_flags f)
{
	int	len;

	len = ft_numlen(n);
	if (f.has_precision && f.precision == 0 && n == 0)
		len = 0;
	return (len);
}

static void	ft_get_int_params(int n, int len, t_flags f, int *arr)
{
	int	sign;
	int	total;

	sign = (n < 0);
	arr[0] = 0;
	if (f.has_precision && f.precision > len)
		arr[0] = f.precision - len;
	total = len + arr[0] + sign;
	if (f.plus && !sign)
		total++;
	else if (f.space && !sign && !f.plus)
		total++;
	arr[1] = 0;
	if (f.width > total)
		arr[1] = f.width - total;
}

static int	ft_put_int_prefix(int n, t_flags f, int spaces)
{
	int	printed;

	printed = 0;
	if (!f.minus && !f.zero)
		printed += ft_putnchar(' ', spaces);
	if (n < 0)
		printed += write(1, "-", 1);
	else if (f.plus)
		printed += write(1, "+", 1);
	else if (f.space)
		printed += write(1, " ", 1);
	if (!f.minus && f.zero)
		printed += ft_putnchar('0', spaces);
	return (printed);
}

static int	ft_put_int_body(long nb, int len, int zeros)
{
	int	printed;

	printed = ft_putnchar('0', zeros);
	if (len > 0)
		ft_putnbr_long(nb);
	printed += len;
	return (printed);
}

int	ft_print_int(int n, t_flags f)
{
	long	nb;
	int		len;
	int		arr[2];
	int		printed;

	nb = n;
	if (nb < 0)
		nb = -nb;
	len = ft_int_len(n, f);
	if (f.has_precision)
		f.zero = 0;
	ft_get_int_params(n, len, f, arr);
	printed = ft_put_int_prefix(n, f, arr[1]);
	printed += ft_put_int_body(nb, len, arr[0]);
	if (f.minus)
		printed += ft_putnchar(' ', arr[1]);
	return (printed);
}
