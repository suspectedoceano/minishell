/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:51:10 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 11:51:12 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

void	*list_pop(t_list *list)
{
	void	*element;

	if (list->size > 0)
	{
		element = list_get(list, list->size - 1);
		return (list_remove_at(list, list->size - 1), element);
	}
	return (YNULL);
}

void	list_apply(t_list *list, t_apply_func f)
{
	unsigned int	i;

	i = 0;
	while (i < list->size)
	{
		f(list->data[i]);
		i++;
	}
}

t_list	*list_map(t_list *list, t_map_func f)
{
	t_list			*result;
	unsigned int	i;

	if (!list || !f)
		return (YNULL);
	result = (t_list *)malloc(sizeof (t_list));
	result->capacity = list->capacity;
	result->size = list->size;
	if (list->data)
	{
		result->data = (void **)malloc(sizeof (void *) * result->capacity);
		i = 0;
		while (i < result->size)
		{
			result->data[i] = f(list->data[i]);
			i++;
		}
	}
	else
		result->data = YNULL;
	return (result);
}

void	list_filter(t_list *list, t_filter_func f)
{
	unsigned int	read_i;
	unsigned int	write_i;
	unsigned int	removed_count;

	if (!list || !f || list->size == 0)
		return ;
	read_i = 0;
	write_i = 0;
	removed_count = 0;
	while (read_i < list->size)
	{
		if (!f(list->data[read_i]))
		{
			list->data[write_i] = list->data[read_i];
			write_i++;
		}
		else
			removed_count++;
		read_i++;
	}
	list->size -= removed_count;
	_list_realloc(list, (1 + list->size / LIST_C_STEP) * LIST_C_STEP);
}

t_list	*list_filter_new(t_list *list, t_filter_func f)
{
	unsigned int	i;
	t_list			*result;

	if (!list || !f)
		return (YNULL);
	if (list->size == 0)
		return (list_new());
	i = 0;
	result = list_new();
	while (i < list->size)
	{
		if (!f(list->data[i]))
			list_insert(result, list->data[i]);
		i++;
	}
	return (result);
}
