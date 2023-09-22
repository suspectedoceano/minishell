/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yprint_format_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:41:32 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:41:33 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yprint_format.h"
#include "ycstr.h"

char	*format_none(va_list *args, t_pconvdata cdata)
{
	(void)args;
	(void)cdata;
	return (cstr_dup(""));
}
