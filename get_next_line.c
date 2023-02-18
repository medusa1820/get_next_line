#include "get_next_line.h"

char	*check_remainder(char **remainder, char **line)
{
	char	*p_n;
	char	*tmp;

	p_n = NULL;
	if (*remainder)
	{
		p_n = ft_strchr(*remainder, '\n');
		if (p_n)
		{
			tmp = ft_strdup(++p_n);
			if (!tmp)
				return (free(*remainder), *remainder = NULL, *line = NULL, NULL);
			*p_n = '\0';
			*line = ft_strdup(*remainder);
			if (!*line)
				return (free(tmp), tmp = NULL, free(*remainder), *remainder = NULL, NULL);
			free(*remainder);
			*remainder = tmp;
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
			if (!*line)
				return (NULL);
		}
	}
	else
	{
		*line = ft_strnew(1);
		if (!*line)
			return (NULL);
	}
	return (p_n);
}

int	read_to_buf(char **remainder, char **line, char **p_n, int *fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		bwr;

	bwr = read(*fd, buf, BUFFER_SIZE);
	if ((bwr < 0) || (bwr == 0 && **line == '\0'))
		return (bwr);
	if (bwr == 0 && **line != '\0')
		return (bwr);
	if (bwr > 0)
	{
		buf[bwr] = '\0';
		*p_n = ft_strchr(buf, '\n');
		if (*p_n)
		{
			*remainder = ft_strdup(++*p_n);
			if (!*remainder)
				return (bwr);
			**p_n = '\0';
		}
		*line = ft_strjoin(*line, buf);
		if (!*line)
			return (bwr);
	}
	return (bwr);
}

char	*get_next_line(int fd)
{
	static char		*remainder;
	char			*p_n;
	char			*line;
	int				bwr;

	p_n = check_remainder(&remainder, &line);
	if (!line)
		return (NULL);
	while (!p_n)
	{
		bwr = read_to_buf(&remainder, &line, &p_n, &fd);
		if ((bwr < 0) || (bwr == 0 && *line == '\0'))
			return (free(line), NULL);
		if (bwr == 0 && *line != '\0')
			return (line);
		if (bwr > 0)
		{
			if (p_n && !remainder)
				return (free(line), free(remainder), remainder = NULL, NULL);
			if (!line)
				return (free(remainder), remainder = NULL, NULL);
		}
	}
	return (line);
}
