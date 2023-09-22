/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:54:33 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/01 12:54:34 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

void	list_remove(t_list *list, void *e)
{
	unsigned int	i;
	unsigned int	k;

	if (list->size == 0)
		return ;
	i = 0;
	while (i < list->size)
	{
		if (list->data[i] == e)
			break ;
		i++;
	}
	if (i < list->size)
	{
		k = i;
		while (k < list->size - 1)
		{
			list->data[k] = list->data[k + 1];
			k++;
		}
		list->size--;
		if (list->size < list->capacity - LIST_C_STEP)
			_list_realloc(list, list->capacity - LIST_C_STEP);
	}
}

void	list_remove_at(t_list *list, unsigned int i)
{
	unsigned int	k;

	if (i >= list->size)
		return ;
	k = i;
	while (k < list->size - 1)
	{
		list->data[k] = list->data[k + 1];
		k++;
	}
	list->size--;
	if (list->size < list->capacity - LIST_C_STEP)
		_list_realloc(list, list->capacity - LIST_C_STEP);
}

void	*list_get(t_list *list, unsigned int i)
{
	if (i >= list->size)
		return (YNULL);
	return (list->data[i]);
}

void	list_set(t_list *list, unsigned int i, void *element)
{
	if (i >= list->size)
		return ;
	list->data[i] = element;
}

void	list_iapply(t_list *list, void (*f)(void *, unsigned int))
{
	unsigned int	i;

	i = 0;
	while (i < list->size)
	{
		f(list->data[i], i);
		i++;
	}
}
