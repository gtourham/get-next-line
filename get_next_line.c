#include "get_next_line.h"

static void	del_line(char *stash, size_t count)
{
	size_t	i;

	i = 0;
	while (stash[count + i])
	{
		stash[i] = stash[count + i];
		i++;
	}
	stash[i] = '\0';
}

static int	has_newline(const char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

static char	*read_stash(int fd, char *stash, char *buf)
{
	ssize_t	ret;
	char	*joined;

	while (!has_newline(stash))
	{
		ret = read(fd, buf, BUF_SIZE);
		if (ret < 0)
			return (free(stash), NULL);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		joined = ft_strjoin(stash, buf);
		free(stash);
		if (!joined)
			return (NULL);
		stash = joined;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;

	if (fd < 0 || BUF_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	buf = malloc((size_t)BUF_SIZE + 1);
	if (!buf)
		return (free(stash), stash = NULL, NULL);
	stash = read_stash(fd, stash, buf);
	free(buf);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = ft_strdup(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	del_line(stash, ft_strlen(line));
	if (!*stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}