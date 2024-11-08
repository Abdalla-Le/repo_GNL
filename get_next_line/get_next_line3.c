
#include "get_next_line.h"

char	*get_next_line3(int fd)
{
	static char	*unprocessed = NULL;
	char		*buffer;
	char		*line;
	int			bytes_read;
	int			i;
	char		*newline;


	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}

	if (unprocessed != NULL)
		line = unprocessed;
	else
		line = ft_calloc(1, 1);

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == 0)
			break;
		if (bytes_read == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		//botar no nulo dentro de buffer

		line = ft_strjoin(line, buffer); //se ligar no free do line
		if (ft_strchr(line,'\n')) //pra quebrar o looping se encontrar quebre de loinha
		{
			free(buffer);
			break;
		}
	}
	// o erro ta aqui !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (bytes_read == 0 && line[0] == '\0')
    {
        free(line);
        return (NULL);  // Fim do arquivo sem mais dados
    }



	unprocessed = ft_strdup(ft_strchr(line,'\n') + 1); //maloca o resto apos o \n

	i = 0;
	while(line[i] && line[i] != '\n')
		i++;
	newline = (char *)ft_calloc(i + 2,sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		newline[i] = line[i];
		i++;
	}
	newline[i++] = '\n';
	newline[i] = '\0';

	free(line);
	return (newline);

}
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int fd;
	char *line;


	fd = open("test.txt", O_RDONLY);
	line = get_next_line3(fd);
	while(line)
	{
		printf("%s", line);
		line = get_next_line3(fd);
	}
	/*line = get_next_line2(fd);
	line = get_next_line2(fd);
	line = get_next_line2(fd);*/


	return (0);
}
