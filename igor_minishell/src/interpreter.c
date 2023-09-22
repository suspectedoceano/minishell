/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:08:58 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/12 15:08:59 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

static int invoke_command(t_pcall program, t_io_pipes pipes)
{
	t_list	*path_list;
	int		fork_result;
	t_list	*arg_list;
	int		wstatus;

	if (try_run_sync_builtin(&program, pipes, &wstatus))
		return (wstatus);
	fork_result = fork();
	if (fork_result == 0)
	{
		if (try_run_builtin(&program, pipes, &wstatus))
			exit(wstatus);
		path_list = get_paths(global().envp);
		arg_list = list_copy(program.params);
		list_insert_at(arg_list, 0, program.pname);
		run_process(arg_list, path_list);
		list_apply(path_list, (t_apply_func)string_delete);
		list_delete(path_list);
		list_apply(arg_list, (t_apply_func)string_delete);
		list_delete(arg_list);
		exit(0);
	}
	waitpid(fork_result, &wstatus, 0);
	return (WEXITSTATUS(wstatus));
}

//TODO: Why does this thing exist?
static int	invoke_command_async(t_pcall program)
{
	(void)program;
	return (0);
}

// The environment variable expansion should happen in this function
static void	eval_exp(t_expression* exp, t_itptr_ctx *ctx)
{
	if (ctx->prev_operator == OP_NONE
		|| (ctx->prev_operator == OP_OR && ctx->status_code != 0)
		|| (ctx->prev_operator == OP_AND && ctx->status_code == 0))
	{
		if (exp->type == PROGRAM_CALL)
		{
			ctx->status_code = invoke_command(exp->pcall, ctx->pipes);
			(void)invoke_command_async;
			//TODO: Update the context status code to be equal to command status code
		}
		else if (exp->type == NESTED_EXPRESSION)
			ctx->status_code = interpret_ast(exp->nested, ctx->pipes);
		else if (exp->type == PIPE_EXPRESSION)
		{
			//TODO
		}
	}
	ctx->prev_operator = exp->op;
}

int	interpret_ast(t_list *ast, t_io_pipes pipes)
{
	t_itptr_ctx	interpreter_context;

	interpreter_context.prev_operator = OP_NONE;
	interpreter_context.status_code = 0;
	interpreter_context.pipes = pipes;
	list_capply(ast, (t_capply_func)eval_exp, &interpreter_context);
	return (interpreter_context.status_code);
}
