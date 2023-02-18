#include "get_next_line.h"

int	read_to_buf(char **left, char **line, char **p_n, int *fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_len;

	read_len = read(*fd, buf, BUFFER_SIZE);
	if ((read_len < 0) || (read_len == 0 && **line == '\0'))
		return (read_len);
	if (read_len == 0 && **line != '\0')
		return (read_len);
	if (read_len > 0)
	{
		buf[read_len] = '\0';
		*p_n = ft_strchr(buf, '\n');
		if (*p_n)
		{
			*left = ft_strdup(++*p_n);
			if (!*left)
				return (read_len);
			**p_n = '\0';
		}
		*line = ft_strjoin(*line, buf);
		if (!*line)
			return (read_len);
	}
	return (read_len);
}

char	*check_left(char **left, char **line, char **p_n)
{
	char	*tmp;

	if (*left)
		*p_n = ft_strchr(*left, '\n');
	if (*left && *p_n)
	{
		tmp = ft_strdup(++*p_n);
		if (!tmp)
			return (free(*left), *left = NULL, *line = NULL, NULL);
		**p_n = '\0';
		*line = ft_strdup(*left);
		if (!*line)
			return (free(tmp), tmp = NULL, free(*left), *left = NULL, NULL);
		free(*left);
		*left = tmp;
	}
	else if (*left && !*p_n)
	{
		*line = ft_strdup(*left);
		free(*left);
		*left = NULL;
	}
	else
		*line = ft_strnew(1);
	return (*p_n);
}

char	*get_next_line(int fd)
{
	static char		*left;
	char			*p_n;
	char			*line;
	int				read_len;

	p_n = NULL;
	if (!(check_left(&left, &line, &p_n)) && !line)
		return (NULL);
	while (!p_n)
	{
		read_len = read_to_buf(&left, &line, &p_n, &fd);
		if ((read_len < 0) || (read_len == 0 && *line == '\0'))
			return (free(line), NULL);
		if (read_len == 0 && *line != '\0')
			return (line);
		if (read_len > 0)
		{
			if (p_n && !left)
				return (free(line), free(left), left = NULL, NULL);
			if (!line)
				return (free(left), left = NULL, NULL);
		}
	}
	return (line);
}
