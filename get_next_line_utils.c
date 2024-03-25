/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:51:10 by aolabarr          #+#    #+#             */
/*   Updated: 2024/03/23 16:51:14 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\n' && count < BUFFER_SIZE - 1))
		count++;
    if (count == BUFFER_SIZE - 1 && str[count] != '\n')
        count = 0;
    else if (count == BUFFER_SIZE - 1 || str[count] == '\n') 
        count++;
	return (count);
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