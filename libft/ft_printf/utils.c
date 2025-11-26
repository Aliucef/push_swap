/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:12:32 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/06 13:38:56 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int n)
{
	int		len;
	long	nb;

	len = 1;
	nb = n;
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	long	n;
	int		bsize;

	bsize = 0;
	while (base[bsize])
		bsize++;
	n = nbr;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= bsize)
		ft_putnbr_base((int)(n / bsize), base);
	ft_putchar_fd(base[n % bsize], 1);
}

void	ft_putnbr_base_long(unsigned long long nbr, char *base)
{
	int		bsize;

	bsize = 0;
	while (base[bsize])
		bsize++;
	if (nbr >= (unsigned long long)bsize)
		ft_putnbr_base_long((nbr / bsize), base);
	ft_putchar_fd(base[nbr % bsize], 1);
}

int	get_nbr_len_in_hex(unsigned int n)
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
