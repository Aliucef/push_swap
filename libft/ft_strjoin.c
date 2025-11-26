/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:44:53 by alyousse          #+#    #+#             */
/*   Updated: 2025/10/29 14:41:11 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	s1_size;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i < s1_size)
			result[i] = s1[i];
		else
			result[i] = s2[j++];
		i++;
	}
	result[i] = '\0';
	return (result);
}
