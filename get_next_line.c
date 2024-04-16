/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:41:34 by abastard          #+#    #+#             */
/*   Updated: 2024/04/13 18:04:22 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"

static char	*read_fd(int fd, char *buffer, char *prev_line)
{
	int		i;
	char	*line;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		else if (i == 0)
			break ;
		if (!prev_line)
			prev_line = ft_strdup("");
		line = prev_line;
		prev_line = ft_strjoin(line, buffer);
		free(line);
		line = NULL;
		if (!prev_line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (prev_line);
}

static char	*process_liney(char *line)
{
	size_t	i;
	char	*res;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	res = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!res)
	{
		free(res);
		res = NULL;
	}
	line[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*prev_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_fd(fd, buffer, prev_line);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	prev_line = process_liney(line);
	return (line);
}

