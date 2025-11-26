/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:41:26 by alyousse          #+#    #+#             */
/*   Updated: 2025/10/29 15:27:18 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	is_sep(const char c, const char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_start(const char *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && is_sep(s1[i], set))
	{
		i++;
	}
	return (i);
}

char	*ft_word_dup(const char *s, size_t start, size_t end)
{
	char		*res;
	size_t		len;
	size_t		i;

	len = end - start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (start < end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*result;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = find_start(s1, set);
	len = ft_strlen(s1);
	if (start == len)
		return (ft_strdup(""));
	i = len - 1;
	while (is_sep(s1[i], set))
		i--;
	end = i;
	result = ft_word_dup(s1, start, end + 1);
	return (result);
}
