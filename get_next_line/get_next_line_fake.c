#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1

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

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line = NULL;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		if (*buffer == '\n')
			break;
	}

	if (!line)
		return 0;
	return line;
}

int main ()
{
	int fd;

	fd = open("./test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	line = get_next_line(fd);
	printf("%s", line);
}
