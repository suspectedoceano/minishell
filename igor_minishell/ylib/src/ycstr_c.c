/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycstr_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:38 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:39 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ycstr.h"
#include "ydefines.h"
#include <stdlib.h>
#include <stdarg.h>
#include "yprint_format.h"
#include "ytypes.h"

static char	*(*g_dispatch_table[FORMAT_TYPE_COUNT])(va_list *, t_pconvdata) = {
	format_none,
	format_char,
	format_string,
	format_ptr,
	format_decimal,
	format_int,
	format_unsigned_decimal,
	format_hex,
	format_uhex,
	format_percent,
};

int	cstr_cmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((int)(*s1 - *s2));
}

static char	*join_cstrs(char *cstr1, char *cstr2)
{
	char	*result;

	result = cstr_join(cstr1, cstr2);
	free(cstr1);
	free(cstr2);
	return (result);
}

char	*cstr_format(const char *fmt_cstr, ...)
{
	va_list		argp;
	char		*cstr;

	va_start(argp, fmt_cstr);
	cstr = cstr_vformat(fmt_cstr, &argp);
	va_end(argp);
	return (cstr);
}

char	*cstr_vformat(const char *fmt_cstr, va_list *args)
{
	t_pconvdata	cdata;
	char		*cstr;
	t_uint		i[2];
	char		*sub_cstr;

	cstr = cstr_dup("");
	i[0] = 0;
	i[1] = 0;
	while (fmt_cstr[i[1]])
	{
		if (fmt_cstr[i[1]] == '%')
		{
			sub_cstr = cstr_sub(fmt_cstr, i[0], i[1] - i[0]);
			cstr = join_cstrs(cstr, sub_cstr);
			i[1]++;
			cdata = parse_iformat_conversion(fmt_cstr, &i[1]);
			sub_cstr = g_dispatch_table[cdata.type](args, cdata);
			cstr = join_cstrs(cstr, sub_cstr);
			i[0] = i[1] + 1;
		}
		else
			i[1]++;
	}
	sub_cstr = cstr_sub(fmt_cstr, i[0], i[1] - i[0]);
	return (join_cstrs(cstr, sub_cstr));
}
