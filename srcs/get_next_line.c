#include "get_next_line.h"

static char	*get_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	while (!ft_strchr_gnl(stash, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	if (bytes_read < 0 || (!stash && !bytes_read))
		return (free(stash), stash = NULL, NULL);
	buffer = get_line(stash);
	stash = update_stash(stash);
	return (buffer);
}
