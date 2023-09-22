/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yprint_format_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:15:01 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:15:02 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yprint_format.h"
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ycstr.h"
#include "ycmem.h"
#include "ydefines.h"
#include "ytypes.h"

char	*ptr_hexstring(t_uint_ptr v, t_bool uppercase)
{
	char	*str;
	size_t	i;
	size_t	k;

	if (v == 0)
		return (cstr_dup("0"));
	k = v;
	i = 0;
	while (k > 0 && ++i)
		k /= 16;
	str = (char *)malloc(sizeof (char) * (i + 1));
	str[i] = '\0';
	while (i > 0)
	{
		i--;
		if (uppercase)
			str[i] = "0123456789ABCDEF"[v % 16];
		else
			str[i] = "0123456789abcdef"[v % 16];
		v /= 16;
	}
	return (str);
}

char	*uint_hexstring(unsigned int v, t_bool uppercase)
{
	char			*str;
	unsigned int	i;
	unsigned int	k;

	if (v == 0)
		return (cstr_dup("0"));
	k = v;
	i = 0;
	while (k > 0 && ++i)
		k /= 16;
	str = (char *)malloc(sizeof (char) * (i + 1));
	str[i] = '\0';
	while (i > 0)
	{
		i--;
		if (uppercase)
			str[i] = "0123456789ABCDEF"[v % 16];
		else
			str[i] = "0123456789abcdef"[v % 16];
		v /= 16;
	}
	return (str);
}

char	*utoa(unsigned int n)
{
	int				i;
	char			*str;
	unsigned int	temp;

	temp = n;
	i = 0;
	while (++i && temp >= 10)
		temp = temp / 10;
	temp = n;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (YNULL);
	str[i] = '\0';
	while (--i >= 0 && temp >= 10)
	{
		str[i] = (temp % 10) + '0';
		temp /= 10;
	}
	str[i] = (temp % 10) + '0';
	return (str);
}

// TODO: rewrite this horseshit
char	*number_padding(char *str, int i, char s, t_pconvdata c)
{
	unsigned int	ef_length;
	char			*result;
	int				k;
	t_bool			sf;

	sf = s != '\0';
	ef_length = cstr_len(str) - (i < 0);
	if (c.precision_flag && c.precision > ef_length)
		ef_length = c.precision;
	else if (!c.precision_flag && c.zero_padding && c.field_width > ef_length)
		ef_length = c.field_width - (i < 0);
	result = (char *)malloc(sizeof (char) * (ef_length + sf + 1));
	k = ef_length - (cstr_len(str) - (i < 0)) + sf;
	ymem_copy(result + k, str + (i < 0), cstr_len(str) - (i < 0) + 1);
	while (k-- >= 1)
		result[k] = '0';
	if (sf)
		result[0] = s;
	return (free(str), result);
}
