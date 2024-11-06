
#include "get_next_line.h"
/*
char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	int		read;

	if (buffer_size == 0)
		return (NULL);
	line = NULL;
	while (nao chegar ate o fial do arquivo/)
	{
		read = read(fd, buf, BUFFER_SIZE);
		line = ft_join(line, &buf);

	}
	read()

}
*/


char	*get_next_line2(int fd)
{
	static char	*unprocessed;
	char		*buffer;
	char		*line;
	int			bytes_read;


	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}

	char *buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		unprocessed = ft_strjoin(line, buffer);
		//verificar o \n nos nao processados


	}

}

char	*verification_n(str)
{
	while (str)
	{
		int i;

		i = 0;
		if (strchr())
		{

		}
	}
}


char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*unprocessed;

	buffer = (char *)alloca((BUFFER_SIZE + 1) * sizeof(char));

	read(fd, buffer, BUFFER_SIZE);



}
