/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yprint_convdata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:15:15 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:15:16 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yprint_format.h"

t_pconvdata	make_convdata(void)
{
	t_pconvdata	data;

	data.type = UNKNOWN;
	data.alt_form = FALSE;
	data.left_adjust = FALSE;
	data.sign_flag = FALSE;
	data.space_flag = FALSE;
	data.zero_padding = FALSE;
	data.precision_flag = FALSE;
	data.precision = 0;
	data.field_width = 0;
	return (data);
}

const char	*configure_convdata(t_pconvdata *data, const char *str)
{
	t_bool	next;

	next = TRUE;
	while (next)
	{
		if (*str == '#')
			data->alt_form = TRUE;
		else if (*str == '-')
			data->left_adjust = TRUE;
		else if (*str == '+')
			data->sign_flag = TRUE;
		else if (*str == ' ')
			data->space_flag = TRUE;
		else if (*str == '0')
			data->zero_padding = TRUE;
		else
			next = FALSE;
		if (next)
			str++;
	}
	return (str);
}

t_pconvtype	get_convtype(const char c)
{
	if (c == 'c')
		return (CHAR);
	else if (c == 's')
		return (STRING);
	else if (c == 'p')
		return (HEXPTR);
	else if (c == 'd')
		return (DECIMAL);
	else if (c == 'i')
		return (INTEGER);
	else if (c == 'u')
		return (UDECIMAL);
	else if (c == 'x')
		return (HEX);
	else if (c == 'X')
		return (UHEX);
	else if (c == '%')
		return (PERCENT);
	return (UNKNOWN);
}
