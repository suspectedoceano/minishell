/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yprint_format_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:14:47 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:14:48 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yprint_format.h"
#include "ydefines.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ycstr.h"
#include "ycmem.h"
#include "ytypes.h"

char	*format_unknown(va_list *args, t_pconvdata cdata)
{
	(void)args;
	(void)cdata;
	(void)!write(1, "Unknown flag specified\n", 24);
	return (YNULL);
}

char	*format_char(va_list *args, t_pconvdata cdata)
{
	unsigned char	c;
	char			*result;

	(void)cdata;
	c = va_arg(*args, int);
	result = (char *)malloc(sizeof (char) * 2);
	result[0] = c;
	result[1] = '\0';
	return (result);
}

char	*format_string(va_list *args, t_pconvdata cdata)
{
	char	*s;

	(void)cdata;
	s = va_arg(*args, char *);
	if (s)
		return (cstr_dup(s));
	else
		return (cstr_dup("(null)"));
}

char	*format_ptr(va_list *args, t_pconvdata cdata)
{
	t_uint_ptr	ptr;
	char		*str;
	char		*result;

	(void)cdata;
	ptr = (t_uint_ptr) va_arg(*args, void *);
	str = ptr_hexstring(ptr, FALSE);
	result = cstr_join("0x", str);
	free(str);
	return (result);
}

//Apparently, according to various SO sources, %d and %i are completely
//equivalent. What the fuck?
char	*format_decimal(va_list *args, t_pconvdata cdata)
{
	int		i;
	char	*str;
	char	sign;

	i = (int) va_arg(*args, int);
	str = cstr_itoa(i);
	sign = (i >= 0) * (cdata.sign_flag * '+' + cdata.space_flag * ' ');
	sign += (i < 0) * '-';
	str = number_padding(str, i, sign, cdata);
	return (str);
}
