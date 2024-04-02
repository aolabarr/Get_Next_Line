/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/02 20:34:30 by aolabarr         ###   ########.fr       */
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
	if (!ft_strchr(aux_buffer, '\n') || !ft_strchr(aux_buffer, EOF))
	{
		tmp = read_file(fd);
		aux_buffer = ft_strjoin_gnl(aux_buffer, tmp);
		ft_free(tmp);
	}
	line = extract_line(aux_buffer);
	//printf("line\t%s\tget_next_line()\n", line);
	tmp = ft_strdup(aux_buffer + ft_strlen(line));
	//printf("aux\t%s\n", tmp);
	ft_free(aux_buffer);
	aux_buffer = tmp;
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
		//printf("bytes: %zu\n", bytes_read);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!aux)
			aux = ft_strdup(buffer);
		else
			aux = ft_strjoin_gnl(aux, buffer);
		//printf("%p\tPrueba 200\n", aux);
		if (!aux)
			return (NULL);
		if (ft_strchr(aux, '\n') || bytes_read == 0)
			return (aux);
	}
	return (NULL);
}

char	*extract_line(char *aux)
{
	char	*newline;
	size_t	len;

	if(!aux)
		return(NULL);
	if (ft_strchr(aux, '\n'))
		len = ft_strlen(aux) - ft_strlen(ft_strchr(aux, '\n')) + 1;
	else
		len = ft_strlen(aux);
	//printf("P1 len: %zu\n", ft_strlen(aux));
	//printf("P2 len: %zu\n", ft_strlen(ft_strchr(aux, '\n')));
	//printf("P3 len: %zu\n", len);
	newline = malloc((len + 1) * sizeof(char));
	if (!newline)
		return (NULL);
	ft_strlcpy(newline, aux, len + 1);
	newline[len] = '\0';
	//printf("P4 %s",newline);
	return (newline);
}

void	ft_free(char *str)
{
	if (str)
	{
		free(str);
	//	str = NULL;
	}
}
