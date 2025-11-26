/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:28:26 by alyousse          #+#    #+#             */
/*   Updated: 2025/10/27 16:44:46 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_isup(int c)
{
	if ((c > 'Z' || c < 'A'))
		return (0);
	return (1);
}

int	ft_tolower(int c)
{
	if (ft_isup(c))
		return (c + 32);
	return (c);
}
