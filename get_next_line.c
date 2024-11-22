
#include "get_next_line.h"

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
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line,'\n')) //pra quebrar o looping se encontrar quebre de linha
		{
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
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (unprocessed != NULL)
	{
		line = unprocessed;
		unprocessed = NULL;
	}
	else
		line = ft_strdup("");

	line = read_file(fd, buffer, line);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
	{
		return (NULL);
	}
	free(unprocessed);
	unprocessed = ft_strdup(ft_strchr(line,'\n') + 1);
	return (new_line(line));
}


#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
