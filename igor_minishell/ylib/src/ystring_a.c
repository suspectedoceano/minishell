/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:07:33 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:07:34 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"
#include "ylist.h"
#include "ycstr.h"
#include <stdlib.h>
#include "ydefines.h"

t_string	*string_new(void)
{
	t_string	*str;

	str = (t_string *)malloc(sizeof (t_string));
	string_init(str);
	return (str);
}

t_string	*string_from_cstr(const char *cstr)
{
	t_string		*str;

	str = (t_string *)malloc(sizeof (t_string));
	string_init_from_cstr(str, cstr);
	return (str);
}

t_string	*string_from_char_list(t_list *clist)
{
	t_string		*str;

	str = (t_string *)malloc(sizeof (t_string));
	string_init_from_char_list(str, clist);
	return (str);
}

t_string	*string_copy(t_string *str)
{
	t_string		*copy;

	copy = (t_string *)malloc(sizeof (t_string));
	string_copy_from_string(copy, str);
	return (copy);
}

void	string_delete(t_string *str)
{
	string_deinit(str);
	free(str);
}
