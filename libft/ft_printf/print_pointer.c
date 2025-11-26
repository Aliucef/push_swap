/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:20:45 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 15:48:13 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_pointer_prefix(t_flags f, int pad)
{
	int	printed;

	printed = 0;
	if (!f.minus && f.width > 1)
		printed += ft_putnchar(' ', f.width - pad);
	return (printed);
}

static int	get_long_len_in_hex(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_put_pointer_body(unsigned long ptr)
{
	int				printed;
	unsigned long	temp;

	temp = ptr;
	printed = 0;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		printed += 5;
		return (printed);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_long(ptr, "0123456789abcdef");
	printed += get_long_len_in_hex(temp) + 2;
	return (printed);
}

int	ft_print_pointer(void *str, t_flags f)
{
	int				printed;
	unsigned long	temp;
	int				pad;

	temp = (unsigned long)str;
	if (temp == 0)
		pad = 5;
	else
		pad = get_long_len_in_hex(temp) + 2;
	printed = 0;
	printed = ft_put_pointer_prefix(f, pad);
	printed += ft_put_pointer_body(temp);
	if (f.minus && f.width > 1)
		printed += ft_putnchar(' ', f.width - pad);
	return (printed);
}
