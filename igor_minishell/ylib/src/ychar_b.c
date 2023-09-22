/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ychar_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:50:01 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:50:02 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ychar.h"

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}

t_bool	char_in_cstr(char c, const char *l)
{
	while (*l)
	{
		if (c == *l)
			return (TRUE);
		l++;
	}
	return (FALSE);
}
