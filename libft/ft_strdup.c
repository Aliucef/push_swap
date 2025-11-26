/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:53:20 by alyousse          #+#    #+#             */
/*   Updated: 2025/10/29 12:32:08 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*d;

	d = dest;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		size;

	size = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, s);
	return (ptr);
}
