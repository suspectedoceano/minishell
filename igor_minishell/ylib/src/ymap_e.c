/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:22:58 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 14:23:00 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include "ymath.h"
#include <stdlib.h>

t_bool	map_has(t_map *map, void *key)
{
	t_uint				hash;
	struct s_map_bucket	*bucket;

	hash = map->hash_func(key);
	bucket = &map->bucket_array[hash % map->bucket_array_size];
	if (_map_item_container_find_item_by_hash(bucket, hash, key,
			map->equals_func))
		return (TRUE);
	return (FALSE);
}

void	map_set_realloc_threshold(t_map *map,
			double upper_realloc_ratio,
			double lower_realloc_ratio,
			double scaling_percent)
{
	t_uint	new_size;

	map->upper_realloc_ratio = upper_realloc_ratio;
	map->lower_realloc_ratio = lower_realloc_ratio;
	map->scaling_ratio = scaling_percent;
	map->upper_realloc_value = upper_realloc_ratio * map->bucket_array_size;
	map->lower_realloc_value = lower_realloc_ratio * map->bucket_array_size;
	if (map->size > map->upper_realloc_value)
	{
		new_size = get_next_prime(map->bucket_array_size * map->scaling_ratio);
		_map_realloc(map, new_size);
	}
	if (map->size < map->lower_realloc_value
		&& map->bucket_array_size > MAP_INITIAL_SIZE)
	{
		new_size = get_next_prime(map->bucket_array_size / map->scaling_ratio);
		_map_realloc(map, new_size);
	}
}
