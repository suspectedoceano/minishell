/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist_iter_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:28:11 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 12:28:14 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

t_list_iter	list_iter(t_list *list)
{
	t_list_iter	iter;

	iter.i = 0;
	iter.value = YNULL;
	iter.list = list;
	return (iter);
}

t_list_iter	list_iter_first(t_list *list)
{
	t_list_iter	iter;

	iter = list_iter(list);
	list_iter_next(&iter);
	return (iter);
}

t_list_iter	list_iter_last(t_list *list)
{
	t_list_iter	iter;

	iter = list_iter(list);
	list_iter_end(&iter);
	return (iter);
}

t_bool	list_iter_next(t_list_iter *iter)
{
	void	*value;

	if (!iter || !iter->list)
		return (FALSE);
	if (iter->i < iter->list->size)
	{
		value = iter->list->data[iter->i];
		iter->i++;
		iter->value = value;
		return (TRUE);
	}
	iter->value = YNULL;
	return (FALSE);
}

t_bool	list_iter_prev(t_list_iter *iter)
{
	void	*value;

	if (!iter)
		return (FALSE);
	if (iter->i > 0)
	{
		value = iter->list->data[iter->i - 1];
		iter->i--;
		iter->value = value;
		return (TRUE);
	}
	iter->value = YNULL;
	return (FALSE);
}
