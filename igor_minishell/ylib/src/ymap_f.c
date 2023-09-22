/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:34:43 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/14 14:34:44 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ymap.h"
#include "ytypes.h"
#include "ymath.h"

void	_map_try_grow(t_map *map)
{
	t_uint	new_size;

	if (map->size > map->upper_realloc_value)
	{
		new_size = get_next_prime(map->bucket_array_size * map->scaling_ratio);
		_map_realloc(map, new_size);
	}
}

void	_map_try_shrink(t_map *map)
{
	t_uint	new_size;

	if (map->size < map->lower_realloc_value
		&& map->bucket_array_size > MAP_INITIAL_SIZE)
	{
		new_size = get_next_prime(map->bucket_array_size / map->scaling_ratio);
		_map_realloc(map, new_size);
	}
}
