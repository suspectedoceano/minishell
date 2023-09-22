/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:07:50 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:07:51 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
// #include "ychar.h"
#include "ycstr.h"
#include <stdlib.h>
#include "ydefines.h"

t_string	*string_reverse(t_string *str)
{
	t_string		*rev;
	unsigned int	i;

	rev = (t_string *)malloc(sizeof (t_string));
	rev->size = str->size;
	rev->cstr = (char *)malloc(sizeof (char) * rev->size);
	i = str->size;
	while (i > 0)
	{
		i--;
		rev->cstr[str->size - (i + 1)] = str->cstr[i];
	}
	return (rev);
}

t_string	*string_substring(t_string *str, unsigned int s, unsigned int e)
{
	t_string		*sub;
	unsigned int	i;

	if (s > e || e > str->size)
		return (YNULL);
	i = e - s;
	sub = (t_string *)malloc(sizeof (t_string));
	sub->size = i;
	sub->cstr = (char *)malloc(sizeof (char) * (i + 1));
	i = 0;
	while (s < e)
	{
		sub->cstr[i] = str->cstr[s];
		i++;
		s++;
	}
	sub->cstr[i] = '\0';
	return (sub);
}

static int	next_substring(const char *str, char c, int *start, int *i)
{
	t_bool	str_flag;

	str_flag = FALSE;
	while (str[*i])
	{
		if (str[*i] == c)
		{
			if (str_flag)
			{
				return (1);
			}
		}
		else
		{
			if (!str_flag)
			{
				str_flag = TRUE;
				*start = *i;
			}
		}
		(*i)++;
	}
	return (str_flag);
}

t_list	*string_split(t_string *str, char s)
{
	t_list	*result;
	int		start;
	int		i;

	if (!str)
		return (YNULL);
	result = list_new();
	start = 0;
	i = 0;
	while (next_substring(str->cstr, s, &start, &i))
		list_insert(result, string_substring(str, start, i));
	return (result);
}

void	string_append2(t_string *str2, t_string *str)
{
	string_append(str, str2);
}
