/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:15:42 by alyousse          #+#    #+#             */
/*   Updated: 2025/10/31 11:15:42 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;

	if (nmemb > 0 && size > 0 && (__SIZE_MAX__ / nmemb < size))
	{
		return (NULL);
	}
	cal = malloc(size * nmemb);
	if (!cal)
		return (NULL);
	ft_memset(cal, 0, nmemb * size);
	return (cal);
}
