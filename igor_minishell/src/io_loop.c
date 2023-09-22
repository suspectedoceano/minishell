/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:30:01 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/07/25 14:30:02 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ylib.h"
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// Debug function (should be removed in release)
static void	print_token(t_string *str)
{
	yprintf("token: %s\n", str->cstr);
}

// Debug function (should be removed in release)
static void print_exp(t_expression *exp, int *depth)
{
	int i;
	for (i = 0; i < *depth; i++)
		yprintf(" ");
	if (exp->type == PROGRAM_CALL)
	{
		yprintf("pcall(%s ", exp->pcall.pname->cstr);
		t_list_iter it = list_iter(exp->pcall.params);
		while (list_iter_next(&it))
			yprintf("%s ", ((t_string *)it.value)->cstr);
		yprintf(", %d)\n", exp->op);
	}
	else
	{
		yprintf("nested(\n");
		*depth += 4;
		list_capply(exp->nested, (t_capply_func)print_exp, depth);
		*depth -= 4;
		for (i = 0; i < *depth; i++)
			yprintf(" ");
		yprintf(", %d)\n", exp->op);
	}
}

static void	evaluate_command(t_string *cmd_str)
{
	t_list		*tokens;
	t_list_iter	it;

	tokens = tokenize(cmd_str);
	it = list_iter(tokens);
	list_apply(tokens, (t_apply_func)print_token);
	t_list *ast = build_exp_list(&it, FALSE);
	if (ast)
	{
		int	depth = 0;
		list_capply(ast, (t_capply_func)print_exp, &depth);
		yprintf("exit code: %d\n", interpret_ast(ast,(t_io_pipes){
			STDIN_FILENO, STDOUT_FILENO}));
		list_apply(ast, (t_apply_func)expression_delete);
		list_delete(ast);
	}
	else
		yprintf("Parsing error\n");
	list_apply(tokens, (t_apply_func)string_delete);
	list_delete(tokens);
}

	// list_insert(global().history, string_copy(cmd_str[1]));
t_bool	io_loop(t_string *cmd_str)
{
	char		*cstr;
	t_bool		should_continue;

	should_continue = !cmd_str;
	if (!cmd_str)
	{
		cstr = readline("minish> ");
		cmd_str = string_from_cstr(cstr);
		free(cstr);
	}
	yprintf("Entered command: %s\n", cmd_str->cstr);
	add_history(cmd_str->cstr);
	should_continue = cstr_ncmp(cmd_str->cstr, "exit", 4) != 0
		&& should_continue;
	evaluate_command(cmd_str);
	string_delete(cmd_str);
	return (should_continue);
}
