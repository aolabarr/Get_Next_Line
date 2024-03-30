/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/03/30 18:00:54 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *aux;
	char		*line;
	char		*tmp;
	size_t		bytes_read;

	line = NULL;
	printf("Prueba 000\n");
	if (!aux)
		aux = read_file(fd, &bytes_read);
	if (!aux)
		return(NULL);
	printf("Prueba 110\n");
	while(!ft_strchr(aux, '\n') && bytes_read > 0)
	{
		printf("Prueba 132\n");
		tmp = read_file(fd, &bytes_read);
		aux = ft_strjoin_gnl(aux, tmp);
		printf("Prueba 133 aux: %s\n",aux);
		ft_free(tmp);
	}
	if (ft_strchr(aux, '\n'))
	{
		printf("Prueba 130 aux: %s\n",aux);
		line = extract_line(aux);
		//printf("Prueba 131 linea: %s\n",line);
		tmp = ft_strdup(aux + ft_strlen(line));
		ft_free(aux);
		aux = tmp;
		printf("Prueba 131 aux: %s\n",aux);
	}
	if (ft_strlen(aux) == 0)
		ft_free(aux);
	printf("Prueba 140\n");
	return(line);
}

char	*read_file(int fd, size_t *bytes_read)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;

	aux = NULL;
	printf("Prueba 210\n");
	*bytes_read = 1;
	while (bytes_read > 0)
	{
		printf("Prueba 220\n");
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[*bytes_read] = '\0';
		printf("Prueba 230: bytes read: %lu buffer: %s\n", *bytes_read, buffer);
		if(!aux)
			aux = ft_strdup(buffer);
		else
			aux = ft_strjoin_gnl(aux, buffer);
		if (!aux)
			return(NULL);
		printf("Prueba 240: aux: %s\n", aux);
		if (ft_strchr(aux, '\n'))
		{
			//printf("Prueba 250: aux: %s\n", aux);
			return(aux);
		}
	}
	if (ft_strlen(aux) == 0 && *bytes_read <= 0)
		return(NULL);
	printf("Prueba EOF\n");
	return(NULL);
}
/*
char	*read_from_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return(NULL);
	buffer[bytes_read] = '\0';
	return(buffer);
}
*/
char	*extract_line(char *aux)
{
	char	*newline;
	size_t	len;

	len = ft_strlen(aux) - ft_strlen(ft_strchr(aux,'\n') + 2);
	//printf("Prueba 300: len = %lu\n", len);
	newline = malloc((len + 1) * sizeof(char));
	if (!newline)
		return (NULL);
	ft_strlcpy(newline, aux, len);
	newline[len + 1] = '\0';
	//printf("Prueba 3100\n");
	return(newline);
}

void	ft_free(char *str)
{
	printf("Prueba 700\n");
	if (str)
	{
		//printf("str: %s\n", str);
		free(str);
	}
}
