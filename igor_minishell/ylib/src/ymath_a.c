/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:58:24 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/15 14:58:25 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ymath.h"

int	int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	int_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	int_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	int_sign(int a)
{
	if (a < 0)
		return (-1);
	else if (a > 0)
		return (1);
	return (0);
}
