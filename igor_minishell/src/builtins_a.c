/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:16:46 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/19 15:16:47 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ylib.h"
#include <unistd.h>

// TODO: Figure out pipes
t_bool	try_run_builtin(t_pcall *program, t_io_pipes pipes, int *exit_code)
{
	t_program_func	program_function;

	program_function = map_get(global().builtin_programs, program->pname);
	if (program_function)
	{
		dup2(pipes.in, STDIN_FILENO);
		dup2(pipes.out, STDOUT_FILENO);
		*exit_code = program_function(program->params, YNULL);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	try_run_sync_builtin(t_pcall *program, t_io_pipes pipes,
	int *exit_code)
{
	t_program_func	program_function;

	program_function = map_get(global().builtin_sync_programs, program->pname);
	if (program_function)
	{
		dup2(pipes.in, STDIN_FILENO);
		dup2(pipes.out, STDOUT_FILENO);
		*exit_code = program_function(program->params, YNULL);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	register_builtin(t_string *name, t_program_func builtin)
{
	if (map_insert(global().builtin_programs, name, builtin))
	{
		list_insert(global().builtin_names, name);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	register_sync_builtin(t_string *name, t_program_func builtin)
{
	if (map_insert(global().builtin_sync_programs, name, builtin))
	{
		list_insert(global().builtin_names, name);
		return (TRUE);
	}
	return (FALSE);
}