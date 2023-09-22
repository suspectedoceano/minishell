/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yivec2_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:21:44 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/05/04 12:21:46 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yvec2.h"
#include "ytypes.h"

t_ivec2	ivec2_new(int x, int y)
{
	return ((t_ivec2){.x = x, .y = y});
}

t_ivec2	ivec2_zero(void)
{
	return ((t_ivec2){.x = 0, .y = 0});
}

t_ivec2	ivec2_add(t_ivec2 a, t_ivec2 b)
{
	return ((t_ivec2){.x = a.x + b.x, .y = a.y + b.y});
}

t_ivec2	ivec2_sub(t_ivec2 a, t_ivec2 b)
{
	return ((t_ivec2){.x = a.x - b.x, .y = a.y - b.y});
}

int	ivec2_dot(t_ivec2 a, t_ivec2 b)
{
	return (a.x * b.x + a.y * b.y);
}
