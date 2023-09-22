/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycmem_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:49:28 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/20 13:49:29 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ycmem.h"
#include "ydefines.h"

void	*ymem_set(void *b, char c, unsigned int len)
{
	char	*ptr;

	if (!b)
		return (YNULL);
	ptr = (char *)b;
	while (ptr < (char *)(b + len))
	{
		*ptr = c;
		ptr++;
	}
	return (b);
}

void	*ymem_copy(void *dst, const void *src, unsigned int n)
{
	unsigned char	*ptr;
	unsigned char	*src_ptr;

	if (!dst)
		return (YNULL);
	if (!src)
		return (dst);
	ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (n > 0)
	{
		*ptr = *src_ptr;
		ptr++;
		src_ptr++;
		n--;
	}
	return (dst);
}

void	*nil(void)
{
	return (0);
}
