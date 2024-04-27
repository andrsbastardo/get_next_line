/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:14 by ajordan-          #+#    #+#             */
/*   Updated: 2024/04/27 15:29:41 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
/* #include <stdio.h>
#include <fcntl.h> */

char	*ft_strdup(char *s)
{
	char	*str;
	char	*dest;
	int		i;

	i = 0;
	str = (char *)s;
	dest = (char *)malloc(ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_read(int fd, char *text)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(text, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			if (text)
				free(text);
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
	return (text);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftovers;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftovers = ft_read(fd, leftovers);
	if (!leftovers)
		return (NULL);
	line = ft_get_line(leftovers);
	leftovers = ft_leftovers(leftovers);
	return (line);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("get_next_line.c", O_RDONLY);
	fd2 = open("get_next_line.h", O_RDONLY);
	fd3 = open("get_next_line_utils.c", O_RDONLY);
	i = 1;
	while (i < 800)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
