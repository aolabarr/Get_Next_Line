/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/03/23 16:51:33 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *buffer;
	static int	start;
	int			num;
	char		*line;

	line = NULL;
	if(!buffer)
	{
		num = ft_read_next_buffer(fd, buffer);
		start = 0;
	}
	while (!ft_linelen(buffer) &&  num == BUFFER_SIZE)
	{
		line = bufferjoin(line, buffer, num);
		num = ft_read_next_buffer(fd, buffer);
	}
	if num == BUFFER_SIZE
	{
		line = ft_manage_line(buffer, start, finbuf);
		start = start + ft_linelen(line);
		return(line);
	}
	else if ft_strlen(buffer + start)
	{
		line = ft_manage_final(bufplus, buffer, start, finbuf);
		start = start + ft_finalfilelen(line);
		return(line);
	}
}

size_t	ft_read_next_buffer(int fd, char *buffer)
{
	if !(buffer)
		buffer = malloc((BUFFER_SIZE) * sizeof(char));
	num = read(fd, buffer, sizeof(buffer));
	return(num);
}

char	*ft_bufferjoin(char line, char *buffer, int num)
{
	char	*str;

	if (line != NULL)
	{
		if (num == BUFFER_SIZE)
		{
			str = malloc((sizeof(line) + BUFFER_SIZE * sizeof(char));
			ft_memcpy(str, line, sizeof(line));	
			ft_memcpy(str + sizeof(line) + 1, buffer, sizeof(buffer));
			free(line);
		}
		else	
		{
			str = malloc((sizeof(line) + num * sizeof(char));
			ft_memcpy(str, line, sizeof(line));	
			ft_memcpy(str + sizeof(line) + 1, buffer, num * sizeof(char));
			free(line);
		}
	}
	else
	{
		if (num == BUFFER_SIZE)
			ft_memcpy(str, buffer, sizeof(buffer));
		else
			ft_memcpy(str, buffer, num * sizeof(char));
	}
	return (str);
}
