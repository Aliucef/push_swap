/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:44:46 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 15:48:06 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_char_prefix(t_flags f)
{
	int	printed;

	printed = 0;
	if (!f.minus && f.width > 1)
		printed += ft_putnchar(' ', f.width - 1);
	return (printed);
}

static int	ft_put_char_body(int c)
{
	int	printed;

	printed = 0;
	ft_putchar_fd((char)c, 1);
	printed ++;
	return (printed);
}

int	ft_print_char(int n, t_flags f)
{
	int		printed;

	printed = 0;
	printed = ft_put_char_prefix(f);
	printed += ft_put_char_body(n);
	if (f.minus && f.width > 1)
		printed += ft_putnchar(' ', f.width - 1);
	return (printed);
}
