/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:53:28 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/01 12:54:28 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

t_list	*list_new(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof (t_list));
	list_init(list);
	return (list);
}

void	_list_realloc(t_list *list, unsigned int new_size)
{
	void			**new_array;
	unsigned int	k;

	if (list->capacity == new_size)
		return ;
	if (new_size == 0)
	{
		free(list->data);
		list->data = YNULL;
		list->capacity = 0;
		return ;
	}
	new_array = (void **)malloc(sizeof (void *) * new_size);
	if (list->data)
	{
		k = 0;
		while (k < list->size)
		{
			new_array[k] = list->data[k];
			k++;
		}
		free(list->data);
	}
	list->data = new_array;
	list->capacity = new_size;
}

void	list_delete(t_list *list)
{
	list_deinit(list);
	free(list);
}

void	list_insert(t_list *list, void *e)
{
	unsigned int	size;

	size = list->size;
	if (size >= list->capacity)
		_list_realloc(list, list->capacity + LIST_C_STEP);
	list->data[size] = e;
	list->size++;
}

void	list_insert_at(t_list *list, unsigned int i, void *e)
{
	unsigned int	k;

	if (i > list->size)
		return ;
	if (list->size >= list->capacity)
		_list_realloc(list, list->capacity + LIST_C_STEP);
	k = list->size;
	while (k > i)
	{
		list->data[k] = list->data[k - 1];
		k--;
	}
	list->data[i] = e;
	list->size++;
}
