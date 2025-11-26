/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyousse <alyousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:19:59 by alyousse          #+#    #+#             */
/*   Updated: 2025/11/14 09:04:07 by alyousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	find_nl(char *s[], int fd)
{
	int	i;

	if (!s[fd])
		return (-1);
	i = 0;
	while (s[fd][i])
	{
		if (s[fd][i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*extract(char *left[], int fd, int idx)
{
	char	*line;
	char	*new_left;
	int		len;

	line = ft_substr_bonus(left[fd], 0, idx + 1);
	len = ft_strlen_bonus(left[fd]) - idx - 1;
	if (len > 0)
		new_left = ft_substr_bonus(left[fd], idx + 1, len);
	else
		new_left = NULL;
	free(left[fd]);
	left[fd] = new_left;
	return (line);
}

static char	*read_and_join(int fd, char *left[])
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
		tmp = left[fd];
		left[fd] = ft_strjoin_bonus(tmp, buf);
		free(tmp);
		if (!left[fd])
			return (free(buf), NULL);
		if (find_nl(left, fd) >= 0)
			break ;
		rd = read(fd, buf, BUFFER_SIZE);
	}
	if (rd < 0)
		return (free(buf), free(left[fd]), NULL);
	free(buf);
	return (left[fd]);
}

static char	*return_last(char *left[], int fd)
{
	char	*line;

	if (!left[fd])
		return (NULL);
	if ((left[fd][0]) == '\0')
	{
		free(left[fd]);
		left[fd] = NULL;
		return (NULL);
	}
	line = left[fd];
	left[fd] = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*left[1024];
	int			idx;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	idx = find_nl(left, fd);
	if (idx >= 0)
		return (extract(left, fd, idx));
	left[fd] = read_and_join(fd, left);
	if (!left[fd])
		return (NULL);
	idx = find_nl(left, fd);
	if (idx >= 0)
		return (extract(left, fd, idx));
	return (return_last(left, fd));
}
