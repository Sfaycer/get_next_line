/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 02:54:26 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/03 03:32:46 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *p;

	if (dst == src || n == 0)
		return (dst);
	p = (unsigned char *)dst;
	while (n--)
		*p++ = *(unsigned char *)src++;
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	char	*str;
	size_t	slen;

	slen = 0;
	while (s1[slen])
		slen++;
	str = (char *)malloc((slen + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s1, slen + 1);
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*join;

	if (!s1 || !s2)
		return (0);
	slen1 = 0;
	while (s1[slen1])
		slen1++;
	slen2 = 0;
	while (s2[slen2])
		slen2++;
	join = (char *)malloc((slen1 + slen2 + 1) * sizeof(char));
	if (!join)
		return (0);
	ft_memcpy(join, s1, slen1);
	ft_memcpy(join + slen1, s2, slen2);
	join[slen1 + slen2] = 0;
	return (join);
}

char		*ft_strchr(const char *s, int c)
{
	const char *str;

	str = s;
	while (*str || c == 0)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (0);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;
	size_t	slen;

	if (!s)
		return (0);
	slen = 0;
	while (s[slen])
		slen++;
	if (start >= slen)
	{
		if (!(sub = (char *)malloc(sizeof(char))))
			return (0);
		sub[0] = 0;
		return (sub);
	}
	sublen = (slen >= (len + start)) ? (len) : (slen - start);
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_memcpy(sub, s + start, sublen);
	sub[sublen] = 0;
	return (sub);
}
