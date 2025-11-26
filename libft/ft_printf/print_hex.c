/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:11:00 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 15:48:09 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex_body(unsigned int nb, int is_cap, int len, int zeros)
{
	int	printed;

	printed = ft_putnchar('0', zeros);
	if (len > 0)
	{
		if (len > get_nbr_len_in_hex(nb) && is_cap && nb != 0)
			ft_putstr_fd("0X", 1);
		else if (len > get_nbr_len_in_hex(nb) && !is_cap && nb != 0)
			ft_putstr_fd("0x", 1);
		if (!is_cap)
			ft_putnbr_base(nb, "0123456789abcdef");
		else
			ft_putnbr_base(nb, "0123456789ABCDEF");
	}
	printed += len;
	return (printed);
}

int	ft_print_hex(unsigned int n, int is_cap, t_flags f)
{
	int		len;
	int		arr[2];
	int		printed;

	len = get_nbr_len_in_hex(n);
	if (f.hash && n != 0)
		len += 2;
	if (f.has_precision)
		f.zero = 0;
	ft_get_params(len, f, arr);
	printed = ft_put_unsigned_prefix(f, arr[1]);
	printed += ft_put_hex_body(n, is_cap, len, arr[0]);
	if (f.minus)
		printed += ft_putnchar(' ', arr[1]);
	return (printed);
}
