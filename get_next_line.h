/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:50:28 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/03 21:21:10 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

# include <stdlib.h>
# include <stddef.h>
#include <fcntl.h>
# include <stdio.h>
# include <unistd.h>


char    *get_next_line(int fd);
char    *extract_line(char *bufaux);
char	*save_rest(char *aux, size_t len);
void    ft_free(char **str);
char	*read_from_file(int fd);
char	*read_file(int fd, char *aux_buffer);
void    ft_bzero(void *str, size_t n);

char    *ft_strchr(const char *s, int c);
char    *ft_strjoin_gnl(char *s1, char *s2);
char    *ft_strdup(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t  ft_strlen(const char *str);
//void	ft_free2(char **str);

#endif

// unistd	- read
// stdlib	- malloc
// fcntl	- open
