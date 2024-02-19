/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:03:55 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/17 18:04:00 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*find_line(int fd, char *rest, char *buffer)
{
	ssize_t		read_char;
	char		*tmp;

	while (!ft_sersh_for_newline(buffer, '\n'))
	{
		read_char = read(fd, buffer, BUFFER_SIZE);
		if (read_char <= 0)
			break ;
		buffer[read_char] = '\0';
		if (!rest)
			rest = ft_strdup(buffer);
		else
		{
			tmp = rest;
			rest = ft_strjoin(tmp, buffer);
			free (tmp);
		}
	}
	free (buffer);
	return (rest);
}

char	*fix_line(char *bufl)
{
	char	*rest;
	size_t	i;

	i = 0;
	while (bufl[i] != '\0' && bufl[i] != '\n')
		i++;
	rest = ft_substr(bufl, i + 1, ft_strlen(bufl) - i);
	if (!rest)
		return (NULL);
	if (bufl[i] != 0)
		bufl[i + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX
		|| fd >= OPEN_MAX)
		return (free (rest), rest = NULL, NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free (rest), rest = NULL, NULL);
	buffer[0] = 0;
	line = find_line(fd, rest, buffer);
	if (!line)
		return (rest = NULL, NULL);
	rest = fix_line(line);
	if (!rest)
		return (free(line), NULL);
	if (line[0] == 0)
		return (free (rest), free (line), rest = NULL);
	buffer = ft_strdup(line);
	free(line);
	if (!buffer)
		return (free(rest), rest = NULL, NULL);
	return (buffer);
}
