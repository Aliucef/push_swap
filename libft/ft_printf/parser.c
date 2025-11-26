/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:12:53 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 13:49:23 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// % [flags] [width] [.precision] [specifier]

#include "ft_printf.h"

static int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

static int	is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static void	flags_check(t_flags *f, int *i, const char *fmt)
{
	while (is_flag(fmt[*i]))
	{
		if (fmt[*i] == '-')
			f->minus = 1;
		else if (fmt[*i] == '0')
			f->zero = 1;
		else if (fmt[*i] == '+')
			f->plus = 1;
		else if (fmt[*i] == ' ')
			f->space = 1;
		else if (fmt[*i] == '#')
			f->hash = 1;
		(*i)++;
	}
}

int	parse_flags(const char *fmt, int i, t_flags *f)
{
	flags_check(f, &i, fmt);
	if (ft_isdigit(fmt[i]))
	{
		f->width = 0;
		while (ft_isdigit(fmt[i]))
		{
			f->width = f->width * 10 + (fmt[i] - '0');
			i++;
		}
	}
	if (fmt[i] == '.')
	{
		f->has_precision = 1;
		i++;
		f->precision = 0;
		while (ft_isdigit(fmt[i]))
		{
			f->precision = f->precision * 10 + (fmt[i] - '0');
			i++;
		}
	}
	if (is_specifier(fmt[i]))
		f->specifier = fmt[i];
	return (i);
}
