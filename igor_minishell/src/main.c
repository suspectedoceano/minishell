/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:20:43 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/07/21 14:20:48 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ylib.h"
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

static t_global	init_global(char *envp[])
{
	static t_global	lmfao = {
		._initialized = FALSE,
	};

	if (!lmfao._initialized && envp != YNULL)
	{
		lmfao.history = list_new();
		lmfao.envp = envp;
		lmfao._initialized = TRUE;
		lmfao.builtin_programs = map_new((t_hash_func)string_hash,
			(t_equals_func)string_equal);
		lmfao.builtin_sync_programs = map_new((t_hash_func)string_hash,
			(t_equals_func)string_equal);
		lmfao.builtin_names = list_new();
	}
	return (lmfao);
}

t_global	global(void)
{
	return (init_global(YNULL));
}

void	clear_global(void)
{
	list_apply(global().history, (t_apply_func)string_delete);
	list_delete(global().history);
	map_delete(global().builtin_programs);
	map_delete(global().builtin_sync_programs);
	list_apply(global().builtin_names, (t_apply_func)string_delete);
	list_delete(global().builtin_names);
}

void	builtins(void)
{
	register_sync_builtin(string_from_cstr("exit"),
		(t_program_func)exit_builtin);
	register_builtin(string_from_cstr("echo"), (t_program_func)echo_builtin);
	register_sync_builtin(string_from_cstr("thing"), (t_program_func)test_thing);
}

int	main(int argc, char **argv, char *envp[])
{
	t_list_iter	it;
	t_string	*cmd_string;

	cmd_string = YNULL;
	init_global(envp);
	builtins();
	if (argc > 1)
		cmd_string = string_from_cstr(argv[1]);
	while (io_loop(cmd_string))
		;
	it = list_iter(global().history);
	while (list_iter_next(&it))
		yprintf("history entry: %s\n", ((t_string *)it.value)->cstr);
	clear_global();
	clear_history();
	return (0);
}
