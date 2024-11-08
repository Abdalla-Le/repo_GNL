/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:40:06 by lnovis-a          #+#    #+#             */
/*   Updated: 2024/11/08 18:23:28 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	tam_s1;
	size_t	tam_s2;
	size_t	i;
	size_t	j;

	tam_s1 = ft_strlen(s1);
	tam_s2 = ft_strlen(s2);
	new_s = (char *) malloc(sizeof(char) * (tam_s1 + tam_s2 + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			new_s[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
	{
		new_s[i + j] = s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	free(s1);
	return (new_s);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	size_t	i;

	if(s == NULL)
		return (NULL);

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if ((nmemb == 0) || (size == 0))
	{
		ptr = malloc(1);
		return (ptr);
	}
	total = size * nmemb;
	if (total / size != nmemb)
		return (NULL);
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return ((void *)ptr);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
	{
		return ((char *)s + (ft_strlen(s)));
	}
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*s_char;

	s_char = (unsigned char *) s;
	while (n--)
	{
		*s_char = '\0';
		s_char++;
	}
	return (s);
}

