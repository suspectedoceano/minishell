/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:48:10 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/06/05 14:48:11 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ymath.h"

int	int_clamp(int v, int min, int max)
{
	if (v > max)
		return (max);
	else if (v < min)
		return (min);
	return (v);
}

unsigned int	uint_clamp(int v, int min, int max)
{
	if (v > max)
		return (max);
	else if (v < min)
		return (min);
	return (v);
}

double	double_clamp(double v, double min, double max)
{
	if (v > max)
		return (max);
	else if (v < min)
		return (min);
	return (v);
}
