/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:00:22 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/12 15:00:23 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ylib.h"
#include <unistd.h>
#include <stdlib.h>

static void	*ast_cleanup(t_list *exp_list)
{
	list_apply(exp_list, (t_apply_func)expression_delete);
	list_delete(exp_list);
	return (nil());
}

t_list	*build_exp_list(t_list_iter *it, t_bool nested)
{
	t_list			*elist;
	t_expression	*exp;

	exp = YNULL;
	elist = list_new();
	while (list_iter_next(it) && !(nested && is_parens_cl(it->value)))
	{
		if (is_operator(it->value) && exp)
			(list_insert(elist, exp), exp->op = get_op(it->value), exp = 0);
		else if (!exp && !is_operator(it->value) && !is_parens(it->value))
			exp = expression_new(PROGRAM_CALL, it->value);
		else if (exp && !is_operator(it->value) && !is_parens(it->value))
			list_insert(exp->pcall.params, string_copy(it->value));
		else if (!exp && is_parens_op(it->value))
		{
			exp = expression_new(NESTED_EXPRESSION, YNULL);
			exp->nested = build_exp_list(it, TRUE);
			if (!exp->nested)
				return (ast_cleanup(elist));
		}
		else
			return (ast_cleanup(elist));
	}
	if (nested && !it->value)
		return (ast_cleanup(elist));
	return (list_insert(elist, exp), elist);
}
