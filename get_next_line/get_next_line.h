/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:01:17 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/11/06 10:38:54 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 7

# include <stdarg.h>
# include <unistd.h>


char *get_next_line(int fd);
void *ft_calloc(size_t nmemb, size_t size);


#endif
