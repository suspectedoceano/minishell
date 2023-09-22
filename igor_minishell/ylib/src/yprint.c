/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:14:40 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:14:41 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yprint.h"
#include "yprint_format.h"
#include "ycstr.h"
#include "ymath.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

// Not sure if this is a good idea yet
static char	*(*g_dispatch_table[FORMAT_TYPE_COUNT])(va_list *, t_pconvdata) = {
	format_unknown,
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

t_pconvdata	parse_format_conversion(const char **str)
{
	t_pconvdata	cdata;

	cdata = make_convdata();
	*str = configure_convdata(&cdata, *str);
	cdata.field_width = cstr_atoi(*str);
	while (**str >= '0' && **str <= '9')
		++(*str);
	if (**str == '.')
	{
		cdata.precision_flag = TRUE;
		cdata.precision = cstr_atoi(++(*str));
		while (**str >= '0' && **str <= '9')
			++(*str);
	}
	cdata.type = get_convtype(**str);
	return (cdata);
}

t_pconvdata	parse_iformat_conversion(const char *str, t_uint *i)
{
	t_pconvdata	cdata;
	const char	*cstrc;

	cdata = make_convdata();
	cstrc = configure_convdata(&cdata, str + *i);
	cdata.field_width = cstr_atoi(cstrc);
	while (*cstrc >= '0' && *cstrc <= '9')
		++cstrc;
	if (*cstrc == '.')
	{
		cdata.precision_flag = TRUE;
		cdata.precision = cstr_atoi(++cstrc);
		while (*cstrc >= '0' && *cstrc <= '9')
			++(cstrc);
	}
	cdata.type = get_convtype(*cstrc);
	*i = cstrc - str;
	return (cdata);
}

static unsigned int	print_str(const char *str, t_pconvdata cdata)
{
	unsigned int	i;
	unsigned int	l;
	char			padding;

	if (cdata.type == CHAR)
		l = 1;
	else if (!cdata.precision_flag || cdata.type != STRING)
		l = cstr_len(str);
	else
		l = int_min(cstr_len(str), cdata.precision);
	if (l >= cdata.field_width)
		return ((void) !write(1, str, l), l);
	padding = cdata.zero_padding * '0' + !cdata.zero_padding * ' ';
	i = cdata.field_width - l;
	if (cdata.left_adjust)
		(void)!write(1, str, l);
	while (i-- > 0)
		(void)!write(1, &padding, 1);
	if (!cdata.left_adjust)
		(void)!write(1, str, l);
	return (l + cdata.field_width - l);
}

static unsigned int	print_argument(va_list *args, t_pconvdata cdata)
{
	char			*str;
	unsigned int	result;

	str = g_dispatch_table[cdata.type](args, cdata);
	if (!str)
		return (0);
	result = print_str(str, cdata);
	free(str);
	return (result);
}

int	yprintf(const char *str, ...)
{
	va_list		argp;
	t_pconvdata	cdata;
	int			print_num;

	va_start(argp, str);
	print_num = 0;
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			cdata = parse_format_conversion(&str);
			print_num += print_argument(&argp, cdata);
		}
		else
		{
			(void)!write(1, str, 1);
			print_num++;
		}
		str++;
	}
	va_end(argp);
	return (print_num);
}
