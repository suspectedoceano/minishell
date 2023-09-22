/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydvec2_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:22:11 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/05/04 12:22:12 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec2.h"
#include "ytypes.h"
#include <math.h>

t_dvec2	dvec2_scale(t_dvec2 a, double scalar)
{
	return ((t_dvec2){.x = a.x * scalar, .y = a.y * scalar});
}

t_dvec2	dvec2_divide(t_dvec2 a, double scalar)
{
	return ((t_dvec2){.x = a.x / scalar, .y = a.y / scalar});
}

double	dvec2_length(t_dvec2 a)
{
	return (sqrt(dvec2_length_sq(a)));
}

double	dvec2_length_sq(t_dvec2 a)
{
	return ((double)(a.x * a.x + a.y * a.y));
}

t_dvec2	dvec2_negate(t_dvec2 a)
{
	return ((t_dvec2){.x = -a.x, .y = -a.y});
}
