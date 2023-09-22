/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:35 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 13:25:36 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
// #include "ychar.h"
#include "ycstr.h"
// #include <stdlib.h>
#include "ydefines.h"

char	*string_find(t_string *str, t_string *sub)
{
	if (!str || !sub)
		return (YNULL);
	return (string_find_cstr(str, sub->cstr));
}

t_string	*string_concat(t_string *str, t_string *str2)
{
	if (!str && str2)
		return (string_copy(str2));
	else if (str && !str2)
		return (string_copy(str));
	else if (!str && !str2)
		return (YNULL);
	return (string_concat_cstr(str, str2->cstr));
}

void	string_append(t_string *str, t_string *str2)
{
	if (!str || !str2)
		return ;
	string_append_cstr(str, str2->cstr);
}

t_string	*string_trim(t_string *str, t_string *set)
{
	if (!set)
		return (YNULL);
	return (string_trim_cstr(str, set->cstr));
}

void	string_delete_as_element(void *str, t_uint i)
{
	(void)i;
	string_delete((t_string *)str);
}
