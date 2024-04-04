/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/04 12:09:53 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*aux_buffer = NULL;
	char		*line;
	char		*tmp1;
	//char		*tmp2;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (ft_free(&aux_buffer), NULL);
	tmp1 = read_file(fd, aux_buffer);
	if (!tmp1)
	{
		//write(1, "Hola",4);
		return (ft_free(&aux_buffer), ft_free(&line), ft_free(&tmp1), NULL);
	}
		if (aux_buffer)
		aux_buffer = ft_strjoin_gnl(aux_buffer, tmp1);
	else
		aux_buffer = ft_strdup(tmp1);
	if (!aux_buffer)
		return (ft_free(&tmp1),ft_free(&aux_buffer), ft_free(&line), NULL);
	ft_free(&tmp1);
	line = extract_line(aux_buffer);
	if (!line || line[0] == '\0')
		return (ft_free(&line), ft_free(&aux_buffer), ft_free(&tmp1), NULL);
	/*
	tmp2 = ft_strdup(aux_buffer + ft_strlen(line));
	if (!tmp2)
		return (ft_free(&aux_buffer), ft_free(&line), ft_free(&tmp2), NULL);
	ft_free(&aux_buffer);
	aux_buffer = tmp2;
	tmp2 = NULL;
	*/
	aux_buffer = save_rest(aux_buffer, ft_strlen(line));
	if (!aux_buffer)
		return (ft_free(&line), NULL);
	return (line);
}

char	*read_file(int fd, char *aux_buffer)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	size_t	bytes_read;

	aux = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			aux_buffer = NULL;
			ft_free(&aux);
			aux = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!aux)
			aux = ft_strdup("");
		aux = ft_strjoin_gnl(aux, buffer);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if (!aux)
			return (NULL);
		if (ft_strchr(aux, '\n') || bytes_read == 0)
			break ;
	}
	//printf("zzzzzzzzz\n");
	return (aux);
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
	newline = malloc((len + 1) * sizeof(char));
	if (!newline)
		return (NULL);
	ft_strlcpy(newline, aux, len + 1);
	newline[len] = '\0';
	return (newline);
}

char	*save_rest(char *aux, size_t len)
{
	char *rest;

	rest = ft_strdup(aux + len);
	ft_free(&aux);
	aux = NULL;
	return (rest);
}

void	ft_free(char **str)
{
	if (*str)
	{
		ft_bzero(*str, ft_strlen(*str));
		free(*str);
		*str = NULL;
	}
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = '\0';
		i++;
	}
}
