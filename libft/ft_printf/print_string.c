/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:12:50 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 08:49:57 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_print_len(char *str, t_flags f)
{
	int	len;

	len = ft_strlen(str);
	if (f.has_precision && f.precision < len)
		len = f.precision;
	return (len);
}

static int	ft_put_str_prefix(t_flags f, int spaces)
{
	int	printed;

	printed = 0;
	if (!f.minus)
		printed += ft_putnchar(' ', spaces);
	return (printed);
}

static int	ft_put_str_body(char *str, int len)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (i < len)
	{
		ft_putchar_fd(str[i], 1);
		i++;
		printed++;
	}
	return (printed);
}

int	ft_print_str(char *str, t_flags f)
{
	int		len;
	int		spaces;
	int		printed;

	if (!str)
		str = "(null)";
	len = ft_get_print_len(str, f);
	spaces = 0;
	if (f.width > len)
		spaces = f.width - len;
	printed = ft_put_str_prefix(f, spaces);
	printed += ft_put_str_body(str, len);
	if (f.minus)
		printed += ft_putnchar(' ', spaces);
	return (printed);
}
