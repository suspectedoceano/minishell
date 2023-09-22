/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:21 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:22 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ytypes.h"
#include "ystring.h"
#include "ycmem.h"

t_bool	string_equal(t_string *str, t_string *str2)
{
	return (string_compare(str, str2) == 0);
}

static t_uint	murmur_32_scramble(t_uint k)
{
	k *= 0xcc9e2d51;
	k = (k << 15) | (k >> 17);
	k *= 0x1b873593;
	return (k);
}

static t_uint	murmur3_32(const t_uchar *key, t_uint len, t_uint seed)
{
	t_uint	h;
	t_uint	k;
	t_uint	i;

	h = seed;
	i = (len >> 2) + 1;
	while (--i)
	{
		ymem_copy(&k, key, sizeof(t_uint));
		key += sizeof(t_uint);
		h ^= murmur_32_scramble(k);
		h = ((h << 13) | (h >> 19)) * 5 + 0xe6546b64;
	}
	k = 0;
	i = (len & 3) + 1;
	while (--i)
	{
		k <<= 8;
		k |= key[i - 1];
	}
	h ^= murmur_32_scramble(k);
	h = (h ^ len) ^ ((h ^ len) >> 16);
	h = (h * 0x85ebca6b) ^ ((h * 0x85ebca6b) >> 13);
	h = (h * 0xc2b2ae35) ^ ((h * 0xc2b2ae35) >> 16);
	return (h);
}

t_uint	string_hash(t_string *str)
{
	return (murmur3_32((t_uchar *)str->cstr, str->size, 3985));
}
