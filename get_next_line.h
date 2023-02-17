/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:48:54 by musenov           #+#    #+#             */
/*   Updated: 2023/02/17 14:53:07 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*

# define BUFF_SIZE 0 -> this will not work as we have to 
first check if BUFF_SIZE was defined before, e.g. among 
others in compilatin flags:

gcc -Wall -Wextra -Werror -D BUFF_SIZE=42 bonus2.c

*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 41
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
// # include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnew(size_t size);
// char	*ft_strchr(const char *s, int c);
char	*ft_strchr(char *s, int c);

char	*ft_strdup(char *s1);
// size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)

char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// char	*ft_strjoin(char *s1, char const *s2);

// char	*check_remainder(char **remainder, char **line);
char	*getstr_remainder(char **remainder, char **line, char **p_n);

// char	*check_nl(char **remainder, char **line, char **p_n);
char	*get_next_line(int fd);

// typedef struct get_next_line
// {
// 	int						fd;
// 	char					*remainder;
// 	struct get_next_line	*next;
// }							t_GNL;

#endif