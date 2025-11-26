/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:07:02 by alyousse          #+#    #+#             */
/*   Updated: 2025/10/29 12:32:20 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	get_num_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	populate_str(char *str, long nb, int len)
{
	str[len] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return ;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_neg;
	long	nb;

	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		nb = -(long)n;
	}
	else
		nb = n;
	len = get_num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	populate_str(str, nb, len);
	if (is_neg)
		str[0] = '-';
	return (str);
}
