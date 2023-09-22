/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:25:41 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/13 13:25:42 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ylib.h"
#include <stdio.h>
#include <unistd.h>

t_list	*get_paths(char *env[])
{
	t_uint		i;
	t_string	*env_str;
	t_list		*result;

	i = 0;
	while (env[i])
	{
		env_str = string_from_cstr(env[i]);
		if (string_find_cstr(env_str, "PATH") == env_str->cstr)
			break ;
		string_delete(env_str);
		i++;
	}
	result = string_split(env_str, '=');
	string_delete(env_str);
	env_str = string_copy(list_get(result, 1));
	(list_apply(result, (t_apply_func)string_delete), list_delete(result));
	result = string_split(env_str, ':');
	return (result);
}

static void	*to_cstr(void *str, t_uint i)
{
	(void)i;
	if (((t_string *)str)->size == 0)
		return (YNULL);
	return (((t_string *)str)->cstr);
}

static void	append_slash(void *vstr, t_uint i)
{
	t_string	*str;

	(void)i;
	str = vstr;
	if (str && string_get(str, str->size - 1) != '/')
		string_append_cstr(str, "/");
}

t_bool	run_process(t_list *arg_list, t_list *path_list)
{
	t_string	*cmd;
	t_uint		i;
	t_list		*cstr_args;

	list_insert(arg_list, string_from_cstr(""));
	cstr_args = list_map(arg_list, (t_map_func)to_cstr);
	list_apply(path_list, (t_apply_func)append_slash);
	i = 0;
	while (i < path_list->size)
	{
		cmd = string_concat(list_get(path_list, i), list_get(arg_list, 0));
		execve(cmd->cstr, (char **)(cstr_args->data), global().envp);
		string_delete(cmd);
		i++;
	}
	list_delete(cstr_args);
	perror("Command not found");
	return (FALSE);
}
