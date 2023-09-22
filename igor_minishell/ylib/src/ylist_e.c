/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:18:47 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:18:49 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

void	list_icapply(t_list *list, t_icapply_func f, void *context)
{
	unsigned int	i;

	i = 0;
	while (i < list->size)
	{
		f(list->data[i], i, context);
		i++;
	}
}

t_list	*list_icmap(t_list *list, t_icmap_func f, void *context)
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
			result->data[i] = f(list->data[i], i, context);
			i++;
		}
	}
	else
		result->data = YNULL;
	return (result);
}

void	list_icfilter(t_list *list, t_icfilter_func f, void *context)
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
		if (!f(list->data[read_i], read_i, context))
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

t_list	*list_icfilter_new(t_list *list, t_icfilter_func f, void *context)
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
		if (!f(list->data[i], i, context))
			list_insert(result, list->data[i]);
		i++;
	}
	return (result);
}
