/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:07:38 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:07:40 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
// #include "ychar.h"
// #include "ycstr.h"
#include <stdlib.h>
#include "ydefines.h"

char	string_get(t_string *str, unsigned int i)
{
	if (i < str->size)
		return (str->cstr[i]);
	return ('\0');
}

void	string_set(t_string *str, unsigned int i, char c)
{
	if (i < str->size)
		str->cstr[i] = c;
}

t_list	*string_to_char_list(t_string *str)
{
	unsigned int	i;
	t_list			*list;
	char			*c;

	if (str->size == 0)
		return (YNULL);
	i = 0;
	list = list_new();
	while (i < str->size)
	{
		c = (char *)malloc (sizeof (char));
		*c = str->cstr[i];
		list_insert(list, c);
		i++;
	}
	return (list);
}

void	string_resize(t_string *str, unsigned int new_size)
{
	unsigned int	i;
	char			*old_cstr;

	old_cstr = YNULL;
	if (str->cstr)
		old_cstr = str->cstr;
	i = 0;
	str->cstr = (char *)malloc(sizeof (char) * (new_size + 1));
	if (new_size < str->size)
		str->size = new_size;
	while (i < str->size)
	{
		str->cstr[i] = old_cstr[i];
		i++;
	}
	while (i < new_size)
	{
		str->cstr[i] = '\0';
		i++;
	}
	str->cstr[i] = '\0';
	str->size = new_size;
	if (old_cstr)
		free(old_cstr);
}

char	*string_find_char(t_string *str, char c)
{
	unsigned int	i;

	i = 0;
	while (i < str->size)
	{
		if (str->cstr[i] == c)
			return (str->cstr + i);
		i++;
	}
	return (YNULL);
}
