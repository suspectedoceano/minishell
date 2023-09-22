/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yio_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:01:21 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:01:22 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yio.h"
#include "ydefines.h"
#include <stdlib.h>
#include <unistd.h>

static unsigned int	copy_string(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

static unsigned int	copy_string_from_buffer(char *dest, char *buf, int offset)
{
	unsigned int	i;

	i = offset;
	while (i < GNL_BSIZE && buf[i] != '\0' && buf[i] != '\n')
	{
		dest[i - offset] = buf[i];
		i++;
	}
	if (i < GNL_BSIZE && buf[i] == '\n')
	{
		dest[i - offset] = buf[i];
		i++;
	}
	dest[i - offset] = '\0';
	return (i);
}

//Returns true if buffer is exhausted and line is complete
static int	consume_buffer(char **str, t_fcnode *node)
{
	char			*result;
	char			*buf;
	unsigned int	i;
	unsigned int	sz;

	i = node->read_index;
	buf = node->content;
	while (i < GNL_BSIZE && buf[i] != '\0' && buf[i] != '\n')
		i++;
	sz = 0;
	i += (i < GNL_BSIZE && buf[i] == '\n');
	while ((*str)[sz] != '\0')
		sz++;
	result = (char *)malloc(sizeof (char) * (sz + i - node->read_index + 1));
	sz = copy_string(result, *str);
	copy_string_from_buffer(result + sz, buf, node->read_index);
	node->read_index = i;
	free(*str);
	*str = result;
	if (i < GNL_BSIZE && buf[i] == '\0')
	{
		node->read_index = GNL_BSIZE;
		return (0);
	}
	return (node->read_index == GNL_BSIZE && buf[GNL_BSIZE - 1] != '\n');
}

static int	construct_string(int fd, char **str, t_file_cache *cache)
{
	t_fcnode	*node;
	char		buf[GNL_BSIZE];
	int			read_val;
	int			i;

	node = _get_cache_node(cache, fd);
	if (!node)
	{
		read_val = read(fd, buf, GNL_BSIZE);
		if (read_val <= 0 || buf[0] == '\0')
			return (-1);
		i = 0;
		while (i + read_val < GNL_BSIZE)
		{
			buf[i + read_val] = '\0';
			i++;
		}
		node = _new_cache_node(cache, fd, buf);
	}
	read_val = consume_buffer(str, node);
	_update_cache_node(cache, node);
	return (read_val);
}

// BUG: does not add a new line if it exists at the
// intersection between 2 reads. Fix pls
// Hopefully fixed now.
char	*get_next_line(int fd)
{
	char				*result;
	int					construct_result;
	static t_file_cache	cache = (t_file_cache){
		.capacity = 0,
		.size = 0,
		.node_array = (void *)0,
	};

	result = (char *)malloc(sizeof (char));
	result[0] = '\0';
	construct_result = construct_string(fd, &result, &cache);
	while (construct_result > 0)
		construct_result = construct_string(fd, &result, &cache);
	if (construct_result <= 0 && result[0] == '\0')
	{
		free(result);
		return (YNULL);
	}
	return (result);
}
