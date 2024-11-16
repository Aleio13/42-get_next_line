/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:20:48 by almatsch          #+#    #+#             */
/*   Updated: 2024/11/15 18:41:06 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(src);
	dest = malloc(length + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	t_len;
	unsigned char	*mem;
	int				i;
	int				j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	t_len = (unsigned int)ft_strlen(s1) + (unsigned int)ft_strlen(s2) + 1;
	mem = (unsigned char *)malloc(t_len);
	if (mem == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		mem[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		mem[i++] = s2[j++];
	}
	mem[i] = '\0';
	return ((char *)mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*mem;
	unsigned int	s_len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	s_len = (unsigned int)ft_strlen(s);
	if (start >= s_len)
	{
		mem = (unsigned char *)malloc(1);
		if (mem == NULL)
			return (NULL);
		mem[0] = '\0';
		return ((char *)mem);
	}
	if ((unsigned int)len > s_len - start)
		len = s_len - start;
	mem = (unsigned char *)malloc(len + 1);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		mem[i++] = s[start++];
	mem[i] = '\0';
	return ((char *)mem);
}

char	*ft_strchr(const char	*s, int c)
{
	int		i;
	char	cr;

	i = 0;
	cr = c;
	while (s[i] != '\0')
	{
		if (s[i] == cr)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cr)
		return ((char *)&s[i]);
	return (NULL);
}
