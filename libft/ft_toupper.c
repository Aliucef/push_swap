/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:16:49 by alyousse          #+#    #+#             */
/*   Updated: 2025/10/27 16:28:02 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_islow(int c)
{
	if ((c > 'z' || c < 'a'))
		return (0);
	return (1);
}

int	ft_toupper(int c)
{
	if (ft_islow(c))
		return (c - 32);
	return (c);
}
