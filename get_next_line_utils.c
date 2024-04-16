/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastard <abastard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:41:05 by abastard          #+#    #+#             */
/*   Updated: 2024/04/13 17:53:11 by abastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + (ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char			*cpy;
	unsigned char	ch;

	ch = (unsigned char)c;
	cpy = (char *)s;
	while ((*cpy != ch) && *cpy)
		cpy++;
	if (ch == *cpy)
		return (cpy);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*ptr;

	if (nmemb >= SIZE_MAX || size >= SIZE_MAX || (nmemb * size) > SIZE_MAX)
		return (NULL);
	ptr = (int *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}