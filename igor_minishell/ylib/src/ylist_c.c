/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:25:04 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/01 14:25:06 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

t_list	*list_copy(t_list *list)
{
	t_list			*copy;
	unsigned int	i;

	if (!list)
		return (YNULL);
	copy = (t_list *)malloc(sizeof (t_list));
	copy->capacity = list->capacity;
	copy->size = list->size;
	if (list->data)
	{
		copy->data = (void **)malloc(sizeof (void *) * copy->capacity);
		i = 0;
		while (i < copy->size)
		{
			copy->data[i] = list->data[i];
			i++;
		}
	}
	else
		copy->data = YNULL;
	return (copy);
}

t_list	*list_imap(t_list *list, void *(*f)(void *, unsigned int))
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
			result->data[i] = f(list->data[i], i);
			i++;
		}
	}
	else
		result->data = YNULL;
	return (result);
}

void	list_ifilter(t_list *list, t_bool (*f)(void *, unsigned int))
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
		if (!f(list->data[read_i], read_i))
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

t_list	*list_ifilter_new(t_list *list, t_bool (*f)(void *, unsigned int))
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
		if (!f(list->data[i], i))
			list_insert(result, list->data[i]);
		i++;
	}
	return (result);
}

void	free_list_element_i(void *e, unsigned int i)
{
	(void)i;
	free(e);
}
