#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 5

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
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if ((nmemb == 0) || (size == 0))
	{
		return (NULL);
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


char	*new_line(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while(line[i] && line[i] != '\n')
		i++;
	new_line = (char *)ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i++] = '\n';
	new_line[i] = '\0';

	free(line);
	return (new_line);
}

char	*read_file(int fd, char *buffer, char *line)
{
	int bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == 0)
		{
			break;
		}
		if (bytes_read == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line,'\n')) //pra quebrar o looping se encontrar quebre de linha
		{
			free(buffer);
			break;
		}
	}
	if (bytes_read == 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);  // Fim do arquivo sem mais dados
    }
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*unprocessed = NULL;;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (unprocessed != NULL)
	{
		line = unprocessed;
		unprocessed = NULL;
	}
	else
		line = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = read_file(fd, buffer, line);
	if (line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	free(unprocessed);
	unprocessed = ft_strdup(ft_strchr(line,'\n') + 1);
	return (new_line(line));
}


int main(void)
{
	int fd;
	char *line;

	// Abre um arquivo para ler
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro ao abrir o arquivo\n");
		return (1);
	}

	// Leitura de linhas
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha lida: %s", line);
		free(line);  // Liberação de memória após ler cada linha
	}

	close(fd);

	return (0);
}
