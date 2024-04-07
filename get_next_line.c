/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/07 12:35:31 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&backup), NULL);
	if (!backup || !ft_strchr(backup, '\n'))
		backup = read_file(fd, backup);
	if (!backup)
		return (NULL);
	line = extract_line(backup);
	if (!line)
		return (ft_free(&backup), NULL);
	backup = save_rest(backup, ft_strlen(line));
	if (!backup)
		return (ft_free(&line), NULL);
	return (line);
}

char	*read_file(int fd, char *bkup)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	ssize_t	bytes_read;

	aux = NULL;
	bytes_read = 1;
	if (!bkup)
		bkup = ft_strdup("");
	if (!bkup)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(&bkup), ft_free(&aux), NULL);
		buffer[bytes_read] = '\0';
		if (!aux)
			aux = ft_strdup(bkup);
		aux = ft_strjoin_gnl(aux, buffer);
		if (!aux)
			return (ft_free(&bkup), NULL);
		if (ft_strchr(aux, '\n'))
			break ;
	}
	return (ft_free(&bkup), aux);
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
