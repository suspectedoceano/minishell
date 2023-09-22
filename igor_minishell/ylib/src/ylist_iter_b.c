/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist_iter_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:35:51 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 12:35:52 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylist.h"
#include "ydefines.h"
#include <stdlib.h>

void	list_iter_begin(t_list_iter *iter)
{
	if (iter)
	{
		iter->i = 0;
		iter->value = YNULL;
	}
}

void	list_iter_end(t_list_iter *iter)
{
	if (iter)
	{
		iter->i = iter->list->size;
		iter->value = YNULL;
	}
}
