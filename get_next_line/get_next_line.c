/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:54:43 by almatsch          #+#    #+#             */
/*   Updated: 2024/11/16 14:44:22 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_to_chunk(char *chunk, char *buffer)
{
	char	*tmp;

	if (chunk == NULL)
		chunk = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(chunk, buffer);
		free(chunk);
		chunk = tmp;
	}
	return (chunk);
}

char	*read_in_buffer(int fd, char *buffer, char *chunk)
{
	ssize_t		r_tracker;

	r_tracker = 1;
	while (r_tracker > 0)
	{
		r_tracker = read(fd, buffer, BUFFER_SIZE);
		if (r_tracker == -1)
		{
			free(chunk);
			return (NULL);
		}
		buffer[r_tracker] = '\0';
		if (r_tracker == 0)
			break ;
		chunk = buffer_to_chunk(chunk, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (chunk);
}

static char	*chunk_to_line(char *chunk)
{
	size_t	i;
	char	*line;

	if (chunk == NULL || chunk[0] == '\0')
		return (NULL);
	i = 0;
	while (chunk[i] != '\0' && chunk[i] != '\n')
		i++;
	if (chunk[i] == '\n')
		i++;
	line = ft_substr(chunk, 0, i);
	return (line);
}

char	*update_chunk(char *chunk)
{
	size_t	i;
	char	*u_chunk;

	i = 0;
	while (chunk[i] != '\0' && chunk[i] != '\n')
		i++;
	if (chunk[i] == '\0')
	{
		free(chunk);
		return (NULL);
	}
	u_chunk = ft_strdup(chunk + i + 1);
	if (u_chunk == NULL)
		return (NULL);
	free(chunk);
	return (u_chunk);
}

char	*get_next_line(int fd)
{
	static char	*chunk;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	chunk = read_in_buffer(fd, buffer, chunk);
	free(buffer);
	if (chunk == NULL)
		return (NULL);
	line = chunk_to_line(chunk);
	chunk = update_chunk(chunk);
	return (line);
}
