/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycstr_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:11:25 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:11:26 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ycstr.h"
#include "ydefines.h"
#include <stdlib.h>

unsigned int	cstr_len(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

unsigned int	cstr_lcat(char *dst, const char *src, unsigned int dsize)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dst_len;

	if (dst == YNULL || src == YNULL)
		return (0);
	i = cstr_len(dst);
	src_len = cstr_len(src);
	dst_len = cstr_len(dst);
	if (i > dsize || dsize == 0)
	{
		return (dsize + src_len);
	}
	while (i < dsize - 1 && *src != '\0')
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

char	*cstr_join(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;
	unsigned int	l;

	if (s1 == YNULL || s2 == YNULL)
		return (YNULL);
	l = cstr_len(s1);
	result = (char *)malloc(sizeof (char) * (l + cstr_len(s2) + 1));
	if (!result)
		return (YNULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		result[i + l] = s2[i];
		i++;
	}
	result[i + l] = '\0';
	return (result);
}

char	*cstr_dup(const char *s1)
{
	unsigned int	i;
	char			*result;

	if (s1 == YNULL)
		return (YNULL);
	i = 0;
	while (s1[i] != '\0')
		i++;
	result = (char *)malloc(sizeof (char) * (i + 1));
	if (result == YNULL)
		return (YNULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	cstr_ncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	counter;

	if (n == 0 || (s1 == YNULL && s2 == YNULL))
		return (0);
	else if (s1 == YNULL)
		return (-(*s2));
	else if (s2 == YNULL)
		return (*s1);
	counter = n - 1;
	while (*s1 == *s2 && counter > 0)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
		counter--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
