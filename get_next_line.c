/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/03/29 18:02:50 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *aux;
	char		*line;
	char		*tmp;

	line = NULL;
	printf("Prueba 000\n");
	if (!aux)
		aux = read_file(fd);
	printf("Prueba 100\n");
	if (!aux)
		return(NULL);
	printf("Prueba 110\n");
	if (!ft_strchr(aux, '\n'))
	{
		printf("Prueba 120\n");
		tmp = aux;
		aux = read_file(fd);
		line = extract_line(aux);
		aux = ft_strdup(aux + ft_strlen(line));
		line = ft_strjoin_gnl(tmp, line);
	}
	else
	{
		printf("Prueba 130\n");
		printf("aux:%s\n",aux);
		line = extract_line(aux);
		//printf("Prueba 131 linea: %s\n",line);
		tmp = ft_strdup(aux + ft_strlen(line));
		ft_free(aux);
		aux = tmp;
		printf("Prueba 132 aux: %s\n",aux);
	}
	if (ft_strlen(aux) == 0)
		ft_free(aux);
	printf("Prueba 140\n");
	return(line);
}

char	*read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*inter;
	size_t	bytes_read;

	inter = NULL;
	printf("Prueba 210\n");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		printf("Prueba 220\n");
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		printf("Prueba 230: bytes read: %lu buffer: %s\n", bytes_read, buffer);
		if(!inter)
			inter = ft_strdup(buffer);
		else
			inter = ft_strjoin_gnl(inter, buffer);
		if (!inter)
			return(NULL);
		printf("Prueba 240: inter: %s\n", inter);
		if (ft_strchr(inter, '\n'))
		{
			printf("Prueba 250\n");
			return(inter);
		}
	}
	printf("Prueba EOF\n");
	return(NULL);
}

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
		free(str);
}
