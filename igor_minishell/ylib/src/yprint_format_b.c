/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yprint_format_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:14:52 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:14:54 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yprint_format.h"
// #include "yprint.h"
#include <unistd.h>
#include <stdarg.h>
// #include <ctype.h>
#include <stdlib.h>
#include "ycstr.h"
#include "ycmem.h"

char	*format_int(va_list *args, t_pconvdata cdata)
{
	return (format_decimal(args, cdata));
}

char	*format_unsigned_decimal(va_list *args, t_pconvdata cdata)
{
	unsigned int	i;
	char			*str;
	char			*temp;

	(void)cdata;
	i = (unsigned int) va_arg(*args, unsigned int);
	temp = utoa(i);
	if (cstr_len(temp) < cdata.precision)
	{
		i = cdata.precision - cstr_len(temp);
		str = (char *)malloc(sizeof (char) * (cdata.precision + 1));
		str[i] = '\0';
		while (i > 0)
		{
			i--;
			str[i] = '0';
		}
		cstr_lcat(str, temp, cdata.precision + 1);
		free(temp);
	}
	else
		str = temp;
	return (str);
}

char	*format_hex(va_list *args, t_pconvdata cdata)
{
	unsigned int	h;
	char			*temp;
	char			*str;

	h = (unsigned int) va_arg(*args, unsigned int);
	temp = uint_hexstring(h, FALSE);
	if (cdata.alt_form && h != 0)
	{
		str = cstr_join("0x", temp);
		(free(temp), temp = str);
	}
	if (cstr_len(temp) < cdata.precision)
	{
		h = cdata.precision - cstr_len(temp);
		str = (char *)malloc(sizeof (char) * (cdata.precision + 1));
		(ymem_set(str, '0', h), str[h] = '\0');
		(cstr_lcat(str, temp, cdata.precision + 1), free(temp));
	}
	else
		str = temp;
	return (str);
}

char	*format_uhex(va_list *args, t_pconvdata cdata)
{
	unsigned int	h;
	char			*temp;
	char			*str;

	h = (unsigned int) va_arg(*args, unsigned int);
	temp = uint_hexstring(h, TRUE);
	if (cdata.alt_form && h != 0)
	{
		str = cstr_join("0X", temp);
		(free(temp), temp = str);
	}
	if (cstr_len(temp) < cdata.precision)
	{
		h = cdata.precision - cstr_len(temp);
		str = (char *)malloc(sizeof (char) * (cdata.precision + 1));
		str[h] = '\0';
		(ymem_set(str, '0', h), str[h] = '\0');
		(cstr_lcat(str, temp, cdata.precision + 1), free(temp));
	}
	else
		str = temp;
	return (str);
}

char	*format_percent(va_list *args, t_pconvdata cdata)
{
	(void)args;
	(void)cdata;
	return (cstr_dup("%"));
}
