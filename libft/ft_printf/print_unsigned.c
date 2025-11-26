/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:12:38 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 09:44:22 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int n, t_flags f)
{
	int	len;

	len = ft_unsigned_numlen(n);
	if (f.has_precision && f.precision == 0 && n == 0)
		len = 0;
	return (len);
}

int	ft_put_unsigned_prefix(t_flags f, int spaces)
{
	int	printed;

	printed = 0;
	if (!f.minus && !f.zero)
		printed += ft_putnchar(' ', spaces);
	if (!f.minus && f.zero)
		printed += ft_putnchar('0', spaces);
	return (printed);
}

static int	ft_put_unsigned_body(unsigned int nb, int len, int zeros)
{
	int	printed;

	printed = ft_putnchar('0', zeros);
	if (len > 0)
		ft_unsigned_putnbr(nb);
	printed += len;
	return (printed);
}

int	ft_print_unsigned(unsigned int n, t_flags f)
{
	int		len;
	int		arr[2];
	int		printed;

	len = ft_unsigned_len(n, f);
	if (f.has_precision)
		f.zero = 0;
	ft_get_params(len, f, arr);
	printed = ft_put_unsigned_prefix(f, arr[1]);
	printed += ft_put_unsigned_body(n, len, arr[0]);
	if (f.minus)
		printed += ft_putnchar(' ', arr[1]);
	return (printed);
}
