/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:21:17 by musenov           #+#    #+#             */
/*   Updated: 2023/02/18 00:48:48 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// char	*bwr_greater_zero(char **line, char **p_buf, char **p_n, char **remainder)
// {
// 	*p_n = ft_strchr(*p_buf, '\n');
// 	if (*p_n)
// 	{
// 		*remainder = ft_strdup(++*p_n);
// 		if (!*remainder)
// 			return (free(*line), free(*remainder), *remainder = NULL, NULL);
// 		**p_n = '\0';
// 	}
// 	*line = ft_strjoin(*line, *p_buf);
// 	if (!*line)
// 		return (free(*remainder), *remainder = NULL, NULL);
// 	return (*line);
// }

char	*read_to_buf(char **remainder, char **line, char **p_n, int *fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		bwr;

	bwr = read(*fd, buf, BUFFER_SIZE);
	if ((bwr < 0) || (bwr == 0 && **line == '\0'))
		return (free(*line), NULL);
	if (bwr == 0 && **line != '\0')
		return (*line);
	if (bwr > 0)
	{
		// buf[bwr] = '\0';
		// p_buf = buf;
		// if (!(bwr_greater_zero(&line, &p_buf, &p_n, &remainder)))
		// 	return (NULL);
		buf[bwr] = '\0';
		*p_n = ft_strchr(buf, '\n');
		if (*p_n)
		{
			*remainder = ft_strdup(++*p_n);
			if (!*remainder)
				return (free(*line), free(*remainder), *remainder = NULL, NULL);
			**p_n = '\0';
		}
		*line = ft_strjoin(*line, buf);
		if (!*line)
			return (free(*remainder), *remainder = NULL, NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char		*remainder;
	// char			buf[BUFFER_SIZE + 1];
	// int				bwr;
	char			*p_n;
	char			*line;
	// char			*p_buf;

	p_n = check_remainder(&remainder, &line);
	if (!line)
		return (NULL);
	while (!p_n)
	{
		// bwr = read(fd, buf, BUFFER_SIZE);
		// if ((bwr < 0) || (bwr == 0 && *line == '\0'))
		// 	return (free(line), NULL);
		// if (bwr == 0 && *line != '\0')
		// 	return (line);
		// if (bwr > 0)
		// {
		// 	buf[bwr] = '\0';
		// 	p_buf = buf;
		// 	if (!(bwr_greater_zero(&line, &p_buf, &p_n, &remainder)))
		// 		return (NULL);
		// }
		
		
		// if (!(read_to_buf(&remainder, &line, &p_n, fd)))
		// 	return (NULL);

		line = read_to_buf(&remainder, &line, &p_n, &fd);
		if (!line)
			return (NULL);
	}
	return (line);
}


			// buf[bwr] = '\0';
			// p_n = ft_strchr(buf, '\n');
			// if (p_n)
			// {
			// 	remainder = ft_strdup(++p_n);
			// 	if (!remainder)
			// 		return (free(line), free(remainder), remainder = NULL, NULL);
			// 	*p_n = '\0';
			// }
			// line = ft_strjoin(line, buf);
			// if (!line)
			// 	return (free(remainder), remainder = NULL, NULL);