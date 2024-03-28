/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:50:28 by aolabarr          #+#    #+#             */
/*   Updated: 2024/03/28 18:46:21 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
#endif

# include <stdlib.h>
# include <stddef.h>
#include <fcntl.h>
# include <stdio.h>
# include <unistd.h>


char    *get_next_line(int fd);
char    *read_file(int fd);
char    *extract_line(char *bufaux);
char    *save_rest(char *bufaux, size_t len);

char    *ft_strchr(const char *s, int c);
char    *ft_strjoin_gnl(char *s1, char *s2);
char    *ft_strdup(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t  ft_strlen(const char *str);

#endif
