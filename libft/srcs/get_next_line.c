/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmennen <qmennen@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:41:16 by qmennen           #+#    #+#             */
/*   Updated: 2024/11/19 19:20:39 by qmennen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*ft_read_file(int fd, char *buffer)
{
	char	*read_buf;
	int		b_read;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (free(buffer), NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, read_buf, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(read_buf);
			free(buffer);
			return (NULL);
		}
		read_buf[b_read] = 0;
		buffer = ft_join(buffer, read_buf);
		if (!buffer || ft_strchr(read_buf, '\n'))
			break ;
	}
	free(read_buf);
	return (buffer);
}

static char	*ft_get_line(char *buffer)
{
	int		i;
	char	*result;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	result = malloc(i + 1 + (buffer[i] == '\n'));
	if (!result)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		result[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		result[i++] = '\n';
	result[i] = 0;
	return (result);
}

static char	*ft_sanitize(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = malloc(ft_strlen(buffer) - i + 1);
	if (!line)
	{
		return (free(buffer), NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = 0;
	free(buffer);
	return (line);
}

static char	*initialize_buffer(char *buffer)
{
	if (buffer)
		return (buffer);
	buffer = malloc(1);
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = initialize_buffer(buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_sanitize(buffer[fd]);
	return (line);
}
