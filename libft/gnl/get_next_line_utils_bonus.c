/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:20:19 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/13 09:26:51 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen_bonus(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_strlen_bonus(s);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr_bonus(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;
	size_t		total_length;

	if (!s)
		return (NULL);
	total_length = ft_strlen_bonus(s);
	if (start >= total_length)
		return (ft_strdup(""));
	if (start + len > total_length)
		len = total_length - start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen_bonus(s1);
	len2 = ft_strlen_bonus(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < len1)
		result[i] = s1[i];
	while (j < len2)
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
