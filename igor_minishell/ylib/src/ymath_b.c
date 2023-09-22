/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:00:53 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/15 15:00:54 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ymath.h"

unsigned int	uint_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned int	uint_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

double	double_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	double_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	double_abs(double a)
{
	if (a < 0.0)
		return (-a);
	return (a);
}
