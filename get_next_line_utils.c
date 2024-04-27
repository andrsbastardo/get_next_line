/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:58 by ajordan-          #+#    #+#             */
/*   Updated: 2024/04/27 15:13:07 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *leftovers, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!leftovers)
		leftovers = ft_strdup("");
	if (!leftovers)
	{
		free(buff);
		return (NULL);
	}
	str = malloc(sizeof(char) * ((ft_strlen(leftovers) + ft_strlen(buff)) + 1));
	if (!str)
	{
		free(buff);
		return (NULL);
	}
	i = -1;
	j = 0;
	if (leftovers)
		while (leftovers[++i] != '\0')
			str[i] = leftovers[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(leftovers) + ft_strlen(buff)] = '\0';
	free(leftovers);
	return (str);
}

char	*ft_get_line(char *leftovers)
{
	int		i;
	char	*str;

	i = 0;
	if (!leftovers[i])
		return (NULL);
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2)); //El error esta aqui
	if (!str)
		return (NULL);
	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
	{
		str[i] = leftovers[i];
		i++;
	}
	if (leftovers[i] == '\n')
	{
		str[i] = leftovers[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_leftovers(char *leftovers)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	if (!leftovers[i])
	{
		free(leftovers);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(leftovers) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (leftovers[i])
		str[j++] = leftovers[i++];
	str[j] = '\0';
	free(leftovers);
	leftovers = NULL;
	return (str);
}
