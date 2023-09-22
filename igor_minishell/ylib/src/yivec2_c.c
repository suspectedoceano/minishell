/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yivec2_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:28:06 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/05/10 14:28:07 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec2.h"
#include "ytypes.h"

t_ivec2	ivec2_negate(t_ivec2 a)
{
	return ((t_ivec2){.x = -a.x, .y = -a.y});
}

t_ivec2	ivec2_dscale(t_ivec2 a, double scalar)
{
	return ((t_ivec2){.x = (int)(a.x * scalar), .y = (int)(a.y * scalar)});
}

t_dvec2	ivec2_normalized(t_ivec2 a)
{
	return (dvec2_normalized(dvec2_new((double)a.x, (double) a.y)));
}
