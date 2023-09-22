/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:30:08 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/07/25 14:30:10 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "ytypes.h"

typedef enum e_exp_type {
	PROGRAM_CALL,
	NESTED_EXPRESSION,
	PIPE_EXPRESSION,
}	t_exp_type;

typedef enum s_operator {
	OP_NONE,
	OP_OR,
	OP_AND,
}	t_operator;

typedef struct s_pcall {
	t_string	*pname;
	t_list		*params;
}	t_pcall;

typedef struct s_expression {
	t_exp_type			type;
	t_list				*nested;
	t_operator			op;
	t_pcall				pcall;
}	t_expression;

typedef struct s_io_pipes {
	int	in;
	int	out;
}	t_io_pipes;

typedef struct s_interpreter_context {
	t_operator	prev_operator;
	int			status_code;
	t_io_pipes	pipes;
}	t_itptr_ctx;

typedef struct s_global {
	t_list	*history;
	char	**envp;
	t_map	*builtin_programs;
	t_map	*builtin_sync_programs;
	t_list	*builtin_names;
	t_bool	_initialized;
}	t_global;

// Utilities
t_bool			is_operator(t_string *token);
t_operator		get_op(t_string *token);
t_bool			is_parens_op(t_string *token);
t_bool			is_parens_cl(t_string *token);
t_bool			is_parens(t_string *token);
t_expression	*expression_new(t_exp_type type, t_string *pname);
void 			expression_delete(t_expression *exp);
t_list			*get_paths(char *env[]);

// Built-in programs
typedef int		(*t_program_func)(t_list *, void *);
t_bool			register_builtin(t_string *name, t_program_func builtin);
t_bool			register_sync_builtin(t_string *name, t_program_func builtin);
t_bool			try_run_builtin(t_pcall *program, t_io_pipes pipes,
		int *exit_code);
t_bool			try_run_sync_builtin(t_pcall *program, t_io_pipes pipes,
		int *exit_code);

int				exit_builtin(t_list *args, void *context);
int				echo_builtin(t_list *args, void *context);
int 			test_thing(t_list *args, void *context);

// Main stuff
t_global		global(void);
t_list			*tokenize(t_string *cmd_str);
t_list			*build_exp_list(t_list_iter *it, t_bool nested);
int				interpret_ast(t_list *ast, t_io_pipes pipes);
t_bool			io_loop(t_string *cmd_str);
t_bool			run_process(t_list *arg_list, t_list *path_list);

#endif
