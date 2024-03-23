/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/03/23 14:16:29 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *buffer;
	static char	*bufplus;
	static int	start;
	static int	finbuf;
	char		*line;

	if(!buffer)
	{
		ft_read_next_buffer(fd, buffer);
		start = 0;
		finbuf = 0;i

	leer en bucle hasta encontrar el \n o \0
	}
	if ft_linelen(buffer + start)
	{
		line = ft_manage_line(bufplus, buffer, start, finbuf);
		start = start + ft_linelen(line);
		return(line);
	}
	else if ft_strlen(buffer + start)
	{
		line = ft_manage_final(bufplus, buffer, start, finbuf);
		start = start + ft_finalfilelen(line);
		return(line);
	}
	else
	{
		bufplus = ft_manage_end_buffer(surplus, buffer, start);
		finbuf = 1;

	}
}

void	ft_read_next_buffer(int fd, char *buffer)
{
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read(fd, buffer, sizeof(buffer));
	buffer (BUFFER_SIZE + 1) = '\0';
}

char	*ft_manage_line(char *bufplus, char *buffer, start, finbuf) 
{
	char	*line;
	if finbuf
		line = ft_linejoin(bufplus, buffer, start);
	else
		line = ft_create_line(buffer, start);
	return(line);
}

char	*ft_linejoin(char *bufplus, char *buffer, int start)
{
	len = ft_linelen(buffer + start);

}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	
	i = 0;
	if (src == NULL && dst == NULL)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	*ft_linelen(char *str)
{
	size_t	count;

	count = 0;
	while (str[i] !='\n')
	   count++;
	count++;
	return(count);	
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	count++;
	return (count);
}
