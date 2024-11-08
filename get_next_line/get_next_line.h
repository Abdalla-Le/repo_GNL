/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:01:17 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/11/08 10:11:12 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>


char *get_next_line2(int fd);
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *s);
char *ft_strchr(char *s, int c);
size_t ft_strlen(char *str);
void *ft_bzero(void *s, size_t n);
#endif
