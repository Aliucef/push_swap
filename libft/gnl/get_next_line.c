/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:33:49 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/10 18:52:37 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_nl(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*extract(char **left, int idx)
{
	char	*line;
	char	*new_left;
	int		len;

	line = ft_substr(*left, 0, idx + 1);
	len = ft_strlen(*left) - idx - 1;
	if (len > 0)
		new_left = ft_substr(*left, idx + 1, len);
	else
		new_left = NULL;
	free(*left);
	*left = new_left;
	return (line);
}

static char	*read_and_join(int fd, char *left)
{
	char	*buf;
	char	*tmp;
	int		rd;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rd = read(fd, buf, BUFFER_SIZE);
	while (rd > 0)
	{
		buf[rd] = '\0';
		tmp = left;
		left = ft_strjoin(tmp, buf);
		free(tmp);
		if (!left)
			return (free(buf), NULL);
		if (find_nl(left) >= 0)
			break ;
		rd = read(fd, buf, BUFFER_SIZE);
	}
	if (rd < 0)
		return (free(buf), free(left), NULL);
	free(buf);
	return (left);
}

static char	*return_last(char **left)
{
	char	*line;

	if (!*left)
		return (NULL);
	if ((*left)[0] == '\0')
	{
		free(*left);
		*left = NULL;
		return (NULL);
	}
	line = *left;
	*left = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left;
	int			idx;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	idx = find_nl(left);
	if (idx >= 0)
		return (extract(&left, idx));
	left = read_and_join(fd, left);
	if (!left)
		return (NULL);
	idx = find_nl(left);
	if (idx >= 0)
		return (extract(&left, idx));
	return (return_last(&left));
}
