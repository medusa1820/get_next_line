/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:54:58 by musenov           #+#    #+#             */
/*   Updated: 2023/02/17 15:26:07 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

// rewrite this, it is from other Lib
char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (size > 0)
		*(str + size--) = '\0';
	*(str + 0) = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
// char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (*(s + i) == (char)c)
		return (((char *)s + i));
	return (0);
}

char	*ft_strdup(char *s1)
{
	size_t	s1_len;
	char	*ptr;
	size_t	i;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i_s12;
	size_t	i_s3;

	if (!s1 || !s2)
		return (free ((char *)s1), NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (free ((char *)s1), NULL);
	i_s3 = 0;
	i_s12 = 0;
	while (*(s1 + i_s12) != '\0')
	{
		*(s3 + i_s3++) = *(s1 + i_s12++);
	}
	i_s12 = 0;
	while (*(s2 + i_s12) != '\0')
	{
		*(s3 + i_s3++) = *(s2 + i_s12++);
	}
	*(s3 + i_s3) = '\0';
	free ((char *)s1);
	return (s3);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (!dst && dstsize == 0)
		return (0 + ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dst_len;
	j = 0;
	while (src[j] != '\n' && i < dstsize - 1)
	{
		dst[i++] = src[j++];
	}
	dst[i++] = '\n';
	dst[i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (dst_size > 0)
	{
		while (*(src + i) != '\0' && i < (dst_size - 1))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	while (*(src + i) != '\0')
		i++;
	return (i);
}