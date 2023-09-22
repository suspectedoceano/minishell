/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:41 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:42 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ylib.h"
#include <stdlib.h>

static t_string	*parse_str(const char *cstr, t_uint *i, char quote)
{
	t_string	*str;
	char		*mcstr;
	t_uint		start;

	start = *i + 1;
	(*i)++;
	while (cstr[*i] && cstr[*i] != quote)
		(*i)++;
	mcstr = cstr_sub(cstr, start, *i - start);
	str = string_from_cstr(mcstr);
	free(mcstr);
	if (cstr[*i] == quote)
		(*i)++;
	return (str);
}

static t_string	*parse_operator(const char *cstr, t_uint *i)
{
	t_string	*str;
	char		*mcstr;
	t_uint		start;

	start = *i;
	while (cstr[*i] == '&' || cstr[*i] == '|')
		(*i)++;
	if (*i == start)
		return (*i = 0, nil());
	mcstr = cstr_sub(cstr, start, *i - start);
	str = string_from_cstr(mcstr);
	free(mcstr);
	return (str);
}

static t_string	*parse_token(const char *cstr, t_uint *i)
{
	t_string	*str;
	char		*mcstr;
	t_uint		start;

	start = *i;
	while (cstr[*i] && cstr[*i] != ' ' && cstr[*i] != '"' && cstr[*i] != '\''
		&& cstr[*i] != '(' && cstr[*i] != ')' && cstr[*i] != '&'
		&& cstr[*i] != '|')
		(*i)++;
	if (*i == start)
		return (*i = 0, nil());
	mcstr = cstr_sub(cstr, start, *i - start);
	str = string_from_cstr(mcstr);
	free(mcstr);
	return (str);
}

static t_string *parse_parens(const char *cstr, t_uint *i)
{
	if (cstr[*i] == '(')
		return (++*i, string_from_cstr("("));
	else
		return (++*i, string_from_cstr(")"));
}

t_list	*tokenize(t_string *cmd_str)
{
	t_list		*tokens;
	t_uint		i;
	t_string	*str;

	tokens = list_new();
	i = 0;
	while (cmd_str->cstr[i])
	{
		str = YNULL;
		if (cmd_str->cstr[i] == ' ')
			i++;
		else if (cmd_str->cstr[i] == '"' || cmd_str->cstr[i] == '\'')
			str = parse_str(cmd_str->cstr, &i, cmd_str->cstr[i]);
		else if (cmd_str->cstr[i] == '(' || cmd_str->cstr[i] == ')')
			str = parse_parens(cmd_str->cstr, &i);
		else if (cmd_str->cstr[i] == '&' || cmd_str->cstr[i] == '|')
			str = parse_operator(cmd_str->cstr, &i);
		else
			str = parse_token(cmd_str->cstr, &i);
		if (i == 0)
			return (list_apply(tokens, (t_apply_func)string_delete),
				list_delete(tokens), nil());
		(void)((str) && (list_insert(tokens, str), 1));
	}
	return (tokens);
}
