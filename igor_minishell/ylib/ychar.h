/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ychar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:39:02 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:39:04 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YCHAR_H
# define YCHAR_H
# include "ytypes.h"

// Tests if c is alphabetic character
t_bool	is_alpha(char c);

// Tests if c is a digit character
t_bool	is_digit(char c);

// Tests if c is alphanumeric character
t_bool	is_alnum(char c);

// Tests if c is an ascii character
t_bool	is_ascii(unsigned char c);

// Tests if c is a printable character
t_bool	is_print(char c);

// Returns uppercase variant of character c if it exists, otherwise returns c
char	to_upper(char c);

// Returns lowercase variant of character c if it exists, otherwise returns c
char	to_lower(char c);

// Returns true if string l contains at least one character c
t_bool	char_in_cstr(char c, const char *l);

#endif
