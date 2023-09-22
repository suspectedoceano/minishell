/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ychar_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:38:52 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:38:54 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ychar.h"

t_bool	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

t_bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

t_bool	is_alnum(char c)
{
	return (is_alpha(c) && is_digit(c));
}

t_bool	is_ascii(unsigned char c)
{
	return (c <= 127);
}

t_bool	is_print(char c)
{
	return (c >= 32 && c <= 126);
}
