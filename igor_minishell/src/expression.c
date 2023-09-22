/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:07:02 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/12 15:07:04 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ylib.h"
#include <stdlib.h>

t_expression	*expression_new(t_exp_type type, t_string *pname)
{
	t_expression	*exp;

	exp = malloc(sizeof (t_expression));
	exp->type = type;
	if (pname)
		exp->pcall = (t_pcall){.pname = string_copy(pname), 
			.params = list_new()};
	else
		exp->pcall = (t_pcall){YNULL, YNULL};
	exp->op = OP_NONE;
	exp->nested = YNULL;
	return (exp);
}

void expression_delete(t_expression *exp)
{
	if (exp->nested)
	{
		list_apply(exp->nested, (t_apply_func)expression_delete);
		list_delete(exp->nested);
	}
	if (exp->pcall.pname)
		string_delete(exp->pcall.pname);
	if (exp->pcall.params)
	{
		list_apply(exp->pcall.params, (t_apply_func)string_delete);
		list_delete(exp->pcall.params);
	}
	free(exp);
}
