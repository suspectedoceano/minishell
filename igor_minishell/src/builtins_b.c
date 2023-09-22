/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:26 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/19 15:36:27 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylib.h"
#include "minishell.h"
#include <stdlib.h>

int	exit_builtin(t_list *args, void *context)
{
	(void)context;
	(void)args;
	yprintf("Builtin exit\n");
	exit(0);
	return (0);
}

int	echo_builtin(t_list *args, void *context)
{
	t_list_iter	it;
	t_string	*arg;

	(void)context;
	yprintf("Builtin echo: ");
	it = list_iter(args);
	list_iter_next(&it);
	arg = it.value;
	if (arg)
		yprintf("%s", arg->cstr);
	while (list_iter_next(&it))
	{
		arg = it.value;
		if (arg)
			yprintf(" %s", arg->cstr);
	}
	yprintf("\n");
	return (0);
}

int test_thing(t_list *args, void *context)
{
	(void)args;
	(void)context;
	yprintf("This is a test builtin\n");
	return (0);
}
