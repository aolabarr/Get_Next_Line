/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:27:00 by marvin            #+#    #+#             */
/*   Updated: 2024/03/25 13:27:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 256

# include <stdlib.h>
# include <stddef.h>

size_t	ft_linelen(const char *str);
size_t	ft_strlen_gnl(const char *str);
size_t	ft_read_next_buffer(int fd, char *buffer);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_bufferjoin(char line, char *buffer, int num);

#endif
