/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/02 13:09:03 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*aux_buffer;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!aux_buffer)
		aux_buffer = read_file(fd);
	if (!aux_buffer)
		return (NULL);
	while (!ft_strchr(aux_buffer, '\n'))
	{
		tmp = read_file(fd);
		if (!tmp)
			return (NULL);
		aux_buffer = ft_strjoin_gnl(aux_buffer, tmp);
		ft_free(tmp);
	}
	if (ft_strchr(aux_buffer, '\n'))
	{
		line = extract_line(aux_buffer);
		//printf("%p\tget_next_line()\n", line);
		tmp = ft_strdup(aux_buffer + ft_strlen(line));
		//printf("%p\tPrueba 100\n", tmp);
		ft_free(aux_buffer);
		aux_buffer = tmp;
	}
	return (line);
}

char	*read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	size_t	bytes_read;

	aux = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!aux)
			aux = ft_strdup(buffer);
		else
			aux = ft_strjoin_gnl(aux, buffer);
		//printf("%p\tPrueba 200\n", aux);
		if (!aux)
			return (NULL);
		if (ft_strchr(aux, '\n'))
			return (aux);
	}
	return (NULL);
}

char	*extract_line(char *aux)
{
	char	*newline;
	size_t	len;

	len = ft_strlen(aux) - ft_strlen(ft_strchr(aux, '\n')) + 2;
	newline = malloc((len + 1) * sizeof(char));
	if (!newline)
		return (NULL);
	ft_strlcpy(newline, aux, len);
	newline[len] = '\0';
	return (newline);
}

void	ft_free(char *str)
{
	if (str)
		free(str);
}
