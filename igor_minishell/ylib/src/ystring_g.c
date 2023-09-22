/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:28 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:29 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ydefines.h"
#include "ystring.h"
#include "ycstr.h"
#include "ytypes.h"
#include <stdarg.h>
#include <stdlib.h>

t_string	*string_format(t_string *fmt_str, ...)
{
	va_list		argp;
	t_string	*str;

	va_start(argp, fmt_str);
	str = string_vformat(fmt_str, &argp);
	va_end(argp);
	return (str);
}

t_string	*string_vformat(t_string *fmt_str, va_list *args)
{
	char		*formatted;
	t_string	*str;

	formatted = cstr_vformat(fmt_str->cstr, args);
	str = string_from_cstr(formatted);
	free(formatted);
	return (str);
}

t_bool	string_init(t_string *str)
{
	str->cstr = (char *)malloc(sizeof (char));
	str->cstr[0] = '\0';
	str->size = 0;
	return (TRUE);
}

void	string_deinit(t_string *str)
{
	str->size = 0;
	if (str->cstr)
		free(str->cstr);
	str->cstr = YNULL;
}
