/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydvec2_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:22:07 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/05/04 12:22:08 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec2.h"
#include "ytypes.h"

t_dvec2	dvec2_new(double x, double y)
{
	return ((t_dvec2){.x = x, .y = y});
}

t_dvec2	dvec2_zero(void)
{
	return ((t_dvec2){.x = 0.0, .y = 0.0});
}

t_dvec2	dvec2_add(t_dvec2 a, t_dvec2 b)
{
	return ((t_dvec2){.x = a.x + b.x, .y = a.y + b.y});
}

t_dvec2	dvec2_sub(t_dvec2 a, t_dvec2 b)
{
	return ((t_dvec2){.x = a.x - b.x, .y = a.y - b.y});
}

double	dvec2_dot(t_dvec2 a, t_dvec2 b)
{
	return (a.x * b.x + a.y * b.y);
}
