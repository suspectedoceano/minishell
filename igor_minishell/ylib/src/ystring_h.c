/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:24 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:26 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
#include "ydefines.h"
#include "ycstr.h"
#include <stdlib.h>

t_bool	string_init_from_cstr(t_string *str, const char *cstr)
{
	unsigned int	i;

	str->size = cstr_len(cstr);
	i = 0;
	str->cstr = (char *)malloc(sizeof (char) * (str->size + 1));
	while (cstr[i])
	{
		str->cstr[i] = cstr[i];
		i++;
	}
	str->cstr[i] = '\0';
	return (TRUE);
}

t_bool	string_init_from_char_list(t_string *str, t_list *clist)
{
	unsigned int	i;

	str->size = clist->size;
	i = 0;
	str->cstr = (char *)malloc(sizeof (char) * (str->size + 1));
	while (i < clist->size)
	{
		str->cstr[i] = *(char *)list_get(clist, i);
		i++;
	}
	str->cstr[i] = '\0';
	return (TRUE);
}

t_bool	string_copy_from_string(t_string *str, t_string *str2)
{
	unsigned int	i;

	str->size = str2->size;
	str->cstr = (char *)malloc(sizeof (char) * (str->size + 1));
	i = 0;
	while (i < str2->size)
	{
		str->cstr[i] = str2->cstr[i];
		i++;
	}
	str->cstr[i] = '\0';
	return (TRUE);
}
