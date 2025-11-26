/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:14:40 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 15:48:50 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

void	init_flags(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = 0;
	f->has_precision = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->specifier = 0;
}

int	ft_handle_conversion(const char *fmt, int *i, va_list args)
{
	t_flags			f;
	int				printed;

	init_flags(&f);
	*i = parse_flags(fmt, *i, &f);
	printed = 0;
	if (f.specifier == 'd' || f.specifier == 'i')
		printed = ft_print_int(va_arg(args, int), f);
	else if (f.specifier == 'u')
		printed = ft_print_unsigned(va_arg(args, unsigned int), f);
	else if (f.specifier == 'x')
		printed = ft_print_hex(va_arg(args, unsigned int), 0, f);
	else if (f.specifier == 'X')
		printed = ft_print_hex(va_arg(args, unsigned int), 1, f);
	else if (f.specifier == 'p')
		printed = ft_print_pointer(va_arg(args, void *), f);
	else if (f.specifier == 's')
		printed = ft_print_str(va_arg(args, char *), f);
	else if (f.specifier == 'c')
		printed = ft_print_char(va_arg(args, int), f);
	else if (f.specifier == '%')
		printed = write(1, "%", 1);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_conversion(format, &i, args);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
