/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yio_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:01:15 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:01:16 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yio.h"
#include "ydefines.h"
#include <stdlib.h>
#include <unistd.h>
#include "ycstr.h"

static void	realloc_file_cache(t_file_cache *cache, unsigned int new_size)
{
	t_fcnode		*new_array;
	unsigned int	k;

	if (new_size == 0)
	{
		free(cache->node_array);
		cache->node_array = NULL;
		cache->capacity = 0;
		return ;
	}
	new_array = (t_fcnode *)malloc(sizeof (t_fcnode) * (new_size));
	k = 0;
	while (k < cache->size)
	{
		new_array[k] = cache->node_array[k];
		k++;
	}
	free(cache->node_array);
	cache->node_array = new_array;
	cache->capacity = new_size;
}

t_fcnode	*_new_cache_node(t_file_cache *cache, unsigned int fd, char *ct)
{
	unsigned int	i;
	unsigned int	k;
	t_fcnode		node;

	i = cache->size;
	if (i >= cache->capacity)
		realloc_file_cache(cache, cache->capacity + GNL_CSTEP);
	k = 0;
	while (k < GNL_BSIZE)
	{
		node.content[k] = ct[k];
		k++;
	}
	node.fd = fd;
	node.read_index = 0;
	cache->node_array[i] = node;
	cache->size++;
	return (&(cache->node_array[i]));
}

t_fcnode	*_get_cache_node(t_file_cache *cache, int fd)
{
	unsigned int	k;

	k = 0;
	while (k < cache->size)
	{
		if (cache->node_array[k].fd == fd)
			return (&(cache->node_array[k]));
		k++;
	}
	return (YNULL);
}

unsigned int	_update_cache_node(t_file_cache *cache, t_fcnode *node)
{
	unsigned int	k;
	t_fcnode		temp_node;

	if (!node)
		return (0);
	if (node->read_index < GNL_BSIZE)
		return (1);
	k = 0;
	while (k < cache->size)
	{
		if (cache->node_array[k].fd == node->fd)
			break ;
		k++;
	}
	temp_node = cache->node_array[cache->size - 1];
	cache->node_array[k] = temp_node;
	cache->size--;
	if (cache->size <= cache->capacity - GNL_CSTEP)
		realloc_file_cache(cache, cache->capacity - GNL_CSTEP);
	return (0);
}

void	write_cstr_fd(int fd, const char *s)
{
	if (fd > 0 && s)
		(void)!write(fd, s, cstr_len(s));
}
