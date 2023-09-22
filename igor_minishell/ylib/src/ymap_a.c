/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:40:52 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/07 13:40:56 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ytypes.h"
#include "ymap.h"
#include "ydefines.h"
#include <stdlib.h>

static t_bool	ptr_equal(void *p1, void *p2)
{
	return (p1 == p2);
}

t_map	*map_new(t_hash_func hfunc, t_equals_func efunc)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof (t_map));
	if (map_init(map, hfunc, efunc))
		return (map);
	else
		return (YNULL);
}

t_bool	map_init(t_map *map, t_hash_func hfunc, t_equals_func efunc)
{
	if (!map || !hfunc)
		return (FALSE);
	map->hash_func = hfunc;
	map->equals_func = efunc;
	if (!efunc)
		map->equals_func = ptr_equal;
	map->upper_realloc_ratio = MAP_UPPER_REALLOC_RATIO;
	map->upper_realloc_value = MAP_INITIAL_SIZE * MAP_UPPER_REALLOC_RATIO;
	map->lower_realloc_ratio = MAP_LOWER_REALLOC_RATIO;
	map->lower_realloc_value = MAP_INITIAL_SIZE * MAP_LOWER_REALLOC_RATIO;
	map->size = 0;
	map->scaling_ratio = MAP_SCALING_RATIO;
	map->bucket_array_size = 0;
	map->bucket_array = YNULL;
	_map_realloc(map, MAP_INITIAL_SIZE);
	return (TRUE);
}

void	map_delete(t_map *map)
{
	map_deinit(map);
	free(map);
}

void	map_deinit(t_map *map)
{
	t_uint	i;

	i = 0;
	while (i < map->bucket_array_size)
	{
		if (map->bucket_array[i].is_list)
		{
			list_apply(&map->bucket_array[i].items,
				(t_apply_func)_map_item_container_delete);
			list_deinit(&map->bucket_array[i].items);
		}
		i++;
	}
	free(map->bucket_array);
	map->bucket_array_size = 0;
	map->size = 0;
}
