/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:05:33 by alyousse          #+#    #+#             */
/*   Updated: 2025/10/29 16:10:17 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (sep == c)
		return (1);
	return (0);
}

static int	word_count(const char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && is_sep(s[i], sep))
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] != '\0' && !is_sep(s[i], sep))
			i++;
	}
	return (count);
}

static void	free_split(char **arr, size_t count)
{
	size_t	k;

	k = 0;
	while (k < count)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}

static char	**ft_split_allocate(char const *s, char c,
	size_t words, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] != '\0' && is_sep(s[i], c))
			i++;
		start = i;
		while (s[i] != '\0' && !is_sep(s[i], c))
			i++;
		arr[j] = ft_word_dup(s, start, i);
		if (!arr[j])
		{
			free_split(arr, j);
			return (0);
		}
		j++;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	words = word_count(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
	{
		return (0);
	}
	return (ft_split_allocate(s, c, words, arr));
}
