/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:07:46 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:07:47 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
// #include "ychar.h"
#include "ycstr.h"
// #include <stdlib.h>
#include "ydefines.h"

static int	char_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

t_string	*string_trim_cstr(t_string *str, char const *set)
{
	unsigned int	i;
	unsigned int	c;

	if (!str || !str->cstr)
		return (YNULL);
	if (!set || str->size == 0)
		return (string_copy(str));
	i = 0;
	while (char_in_set(string_get(str, i), set))
		i++;
	c = i;
	i = str->size - 1;
	while (char_in_set(string_get(str, i), set) && i > c)
		i--;
	return (string_substring(str, c, i + 1));
}

// TODO
t_string	*string_map(t_string *str, char (*f)(char, unsigned int))
{
	(void)str;
	(void)f;
	return (YNULL);
}

// TODO
void	string_apply(t_string *str, void (*f)(char, unsigned int))
{
	(void)str;
	(void)f;
}

// TODO
t_string	*string_filter(t_string *str, t_bool (*f)(char, unsigned int))
{
	(void)str;
	(void)f;
	return (YNULL);
}
