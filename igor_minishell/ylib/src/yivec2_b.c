/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yivec2_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:21:54 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/05/04 12:21:56 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec2.h"
#include "ytypes.h"
#include <math.h>

t_ivec2	ivec2_scale(t_ivec2 a, int scalar)
{
	return ((t_ivec2){.x = a.x * scalar, .y = a.y * scalar});
}

t_ivec2	ivec2_divide(t_ivec2 a, int scalar)
{
	return ((t_ivec2){.x = a.x / scalar, .y = a.y / scalar});
}

double	ivec2_length(t_ivec2 a)
{
	return (sqrt(ivec2_length_sq(a)));
}

double	ivec2_length_sq(t_ivec2 a)
{
	return ((double)(a.x * a.x + a.y * a.y));
}

t_bool	ivec2_eq(t_ivec2 a, t_ivec2 b)
{
	return (a.x == b.x && a.y == b.y);
}
