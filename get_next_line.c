/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:21:17 by musenov           #+#    #+#             */
/*   Updated: 2023/02/17 15:31:54 by musenov          ###   ########.fr       */
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





////////// TRY USE p_nl - separate pointer inside getstr_remainder()

// char	*getstr_remainder(char **remainder, char **line, char **p_n)
// {
// 	char	*tmp;
// 	char

// 	if (*remainder)
// 	{
// 		*p_n = ft_strchr(*remainder, '\n');
// 		if (*p_n)
// 		{
// 			tmp = ft_strdup(++*p_n);
// 			if (!tmp)
// 				return (free(*remainder), *remainder = NULL, *line = NULL, NULL);
// 			**p_n = '\0';
// 			*line = ft_strdup(*remainder);
// 			if (!*line)
// 				return (free(tmp), tmp = NULL, free(*remainder), *remainder = NULL, NULL);
// 			free(*remainder);
// 			*remainder = tmp;
// 		}
// 		else
// 		{
// 			*line = ft_strdup(*remainder);
// 			free(*remainder);
// 			*remainder = NULL;
// 			if (!*line)
// 				return (NULL);
// 		}
// 	}
// 	return (*line);
// }

// char	*bwr_minor(int bwr, char **line)
// {
// 	if ((bwr < 0) || (bwr == 0 && **line == '\0'))
// 		return (free(*line), NULL);
// 	if (bwr == 0 && **line != '\0')
// 		return (*line);
// 	return (*line);
// }

// char	*bwr_greater_zero(char **line, char **buf, char **bwr, )
// {
// 	buf[bwr] = '\0';
// 	p_n = ft_strchr(buf, '\n');
// 	if (p_n)
// 	{
// 		remainder = ft_strdup(++p_n);
// 		if (!remainder)
// 			return (free(line), free(remainder), remainder = NULL, NULL);
// 		*p_n = '\0';
// 	}
// 	line = ft_strjoin(line, buf);
// 	if (!line)
// 		return (free(remainder), remainder = NULL, NULL);
// 	return (p_n);
// }


char	*get_next_line(int fd)
{
	static char		*remainder;
	char			buf[BUFFER_SIZE + 1];
	int				bwr;
	char			*p_n;
	char			*line;

	p_n = check_remainder(&remainder, &line);
	if (!line)
		return (NULL);
	while (!p_n)
	{
		bwr = read(fd, buf, BUFFER_SIZE);
		if ((bwr < 0) || (bwr == 0 && *line == '\0'))
			return (free(line), NULL);
		if (bwr == 0 && *line != '\0')
			return (line);
		else
		{
			buf[bwr] = '\0';
			p_n = ft_strchr(buf, '\n');
			if (p_n)
			{
				remainder = ft_strdup(++p_n);
				if (!remainder)
					return (free(line), free(remainder), remainder = NULL, NULL);
				*p_n = '\0';
			}
			line = ft_strjoin(line, buf);
			if (!line)
				return (free(remainder), remainder = NULL, NULL);
		}
	}
	return (line);
}









// char	*get_next_line(int fd)
// {
// 	static char		*remainder;
// 	char			buf[BUFFER_SIZE + 1];
// 	int				bwr;
// 	char			*p_n;
// 	char			*tmp;
// 	char			*line;

// 	// p_n = check_remainder(&remainder, &line);
// 	// if (!line)
// 	// 	return (NULL);

// 	// if (remainder)
// 	// 	return (getstr_remainder(&remainder, &line, &p_n));
// 	p_n = NULL;
// 	if (remainder)
// 	{
// 		if (!getstr_remainder(&remainder, &line, &p_n))
// 			return (NULL);
// 	}
// 	line = ft_strnew(1);
// 	if (!line)
// 		return (NULL);
// 	while (!p_n)
// 	{
// 		bwr = read(fd, buf, BUFFER_SIZE);
// 		if (bwr < 0)
// 		{
// 			free(line);
// 			return (NULL);
// 		}
// 		else if (bwr == 0)
// 		{
// 			if (*line != '\0')
// 				return (line);
// 			free (line);
// 			return (NULL);
// 		}
// 		else
// 		{
// 			buf[bwr] = '\0';
// 			p_n = ft_strchr(buf, '\n');
// 			if (p_n)
// 			{
// 				remainder = ft_strdup(++p_n);
// 				if (!remainder)
// 					return (free(line), free(remainder), remainder = NULL, NULL);
// 				*p_n = '\0';
// 			}
// 			tmp = ft_strjoin(line, buf);
// 			free(line);
// 			line = NULL;
// 			if (!tmp)
// 				return (free(remainder), remainder = NULL, NULL);
// 				// return (remainder = NULL, NULL);
// 			line = tmp;
// 		}
// 	}
// 	return (line);
// }
