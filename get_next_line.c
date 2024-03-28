/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:58:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/03/28 15:48:30 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *inter;
	char		*line;

	line = NULL;
	if (!buffer)
}


char	*read_file(int fd)
{
	char	*buffer;
	char	*inter;
	size_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return(NULL);
	buffer[BUFFER_SIZE + 1] = '\0';
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (ft_strchr(buffer, '\n'))
		{
			if (!inter)
				return(buffer);
			else
			{
				inter = ft_strjoin_gnl(inter, buffer)
				if (!inter)
					return(NULL);	
				return(inter);
			}
		}
		else
		{
			if(!inter)
				inter = strdup(buffer);
			else
				inter = strjoin_gnl(inter, buffer);
			if (!inter)
				return(NULL);
		}
	}
	return(inter);
}	
