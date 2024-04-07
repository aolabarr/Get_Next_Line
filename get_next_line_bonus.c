/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:02:33 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/07 14:55:42 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (ft_free(&backup[fd]), NULL);
	if (!backup[fd] || !ft_strchr(backup[fd], '\n'))
		backup[fd] = read_file(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	line = extract_line(backup[fd]);
	if (!line)
		return (ft_free(&backup[fd]), NULL);
	backup[fd] = save_rest(backup[fd], ft_strlen(line));
	if (!backup[fd])
		return (ft_free(&line), NULL);
	return (line);
}

char	*read_file(int fd, char *bkup)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	if (!bkup)
		bkup = ft_strdup("");
	if (!bkup)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(&bkup), NULL);
		buffer[bytes_read] = '\0';
		bkup = ft_strjoin_gnl(bkup, buffer);
		if (!bkup)
			return (NULL);
		if (ft_strchr(bkup, '\n'))
			break ;
	}
	return (bkup);
}

char	*extract_line(char *aux)
{
	char	*newline;
	size_t	len;

	if (!aux || aux[0] == '\0')
		return (NULL);
	if (ft_strchr(aux, '\n'))
		len = ft_strlen(aux) - ft_strlen(ft_strchr(aux, '\n')) + 1;
	else
		len = ft_strlen(aux);
	newline = malloc((len + 1) * sizeof(char));
	if (!newline)
		return (NULL);
	ft_strlcpy(newline, aux, len + 1);
	newline[len] = '\0';
	return (newline);
}

char	*save_rest(char *aux, size_t len)
{
	char	*rest;

	rest = ft_strdup(aux + len);
	ft_free(&aux);
	return (rest);
}

void	ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}
