/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycstr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:11:30 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/13 12:11:31 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YCSTR_H
# define YCSTR_H

// Return the length of cstring
# include <stdarg.h>

unsigned int	cstr_len(const char *s);

// Concatenate string src into dst buffer withy the size of dsize (equivalent
// of strlcat)
unsigned int	cstr_lcat(char *dst, const char *src, unsigned int dsize);

// Join 2 cstrings by creating a new one
char			*cstr_join(char const *s1, char const *s2);

// Duplicate a cstring
char			*cstr_dup(const char *s1);

// Convert integer into a cstring
char			*cstr_itoa(int n);

// Convert cstring into a integer
int				cstr_atoi(const char *str);

// Compare 2 strings
int				cstr_cmp(const char *s1, const char *s2);

// Compare up to n characters between 2 strings (equivalent of strncmp)
int				cstr_ncmp(const char *s1, const char *s2, unsigned int n);

// Create a new string that is equivalent to s1 with characters from set
// being trimmed from the beginning and the end
char			*cstr_trim(char const *s1, char const *set);

// Create a new cstring that is a substring of cstring s, starting at st and
// being len characters long
char			*cstr_sub(char const *s, unsigned int st, unsigned int len);

// Interpolate provided parameters into a template cstring
char			*cstr_format(const char *fmt_cstr, ...);

// Interpolate provided parameter list into a template cstring
char			*cstr_vformat(const char *fmt_cstr, va_list *args);

#endif
