/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ystring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:54:48 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 13:54:50 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YSTRING_H
# define YSTRING_H
# include "ytypes.h"
# include <stdarg.h>

// Create and initialize a new empty string
t_string	*string_new(void);

// Initialize a new empty string
t_bool		string_init(t_string *str);

// Create a new string from cstring
t_string	*string_from_cstr(const char *cstr);

// Initialize a new string from cstring
t_bool		string_init_from_cstr(t_string *str, const char *cstr);

// Create a string from the list of characters
t_string	*string_from_char_list(t_list *clist);

// Initialize a new string from the list of characters
t_bool		string_init_from_char_list(t_string *str, t_list *clist);

// Copy a string
t_string	*string_copy(t_string *str);

// Initialize a new string as a copy of other string
t_bool		string_copy_from_string(t_string *str, t_string *str2);

// Deinitialize and delete a string
void		string_delete(t_string *str);

// Deinitialize a string
void		string_deinit(t_string *str);

// Return character of string str at i. Returns '\0' if i is out of bounds
char		string_get(t_string *str, unsigned int i);

// Set the character of string str at i to c with a bounds check
void		string_set(t_string *str, unsigned int i, char c);

// Create a list of character pointers of characters from string str. Each
// character is malloced, so freeing is necessary after use
t_list		*string_to_char_list(t_string *str);

// Resize the string buffer to the new_size by reallocating the cstring buffer.
// Fills out the rest of the buffer with '\0', if new_size is larger than the
// string size
void		string_resize(t_string *str, unsigned int new_size);

// Finds the address of first occurence of character c in string str. Returns
// NULL/YNULL if c wasn't found
char		*string_find_char(t_string *str, char c);

// Same as string_find_char, except this function finds the last occurence of
// character c in string str
char		*string_find_last_char(t_string *str, char c);

// Compare 2 strings. Returns the difference of first 2 non-matching characters
// or 0 if all characters are match
int			string_compare(t_string *str1, t_string *str2);

// Returns the address of the substring within a string, or NULL/YNULL if
// string does not contain the substring
char		*string_find(t_string *str, t_string *sub);

// Creates a new string by concatenating 2 strings
t_string	*string_concat(t_string *str, t_string *str2);

// Appends a string to an existing string by reallocating the string buffer
// and writing the other string into it
void		string_append(t_string *str, t_string *str2);

// Creates a new string that is equivalent to the old string with the
// characters from set being trimmed from it
t_string	*string_trim(t_string *str, t_string *set);

// Same as string_find, except this function looks for cstring within a
// string
char		*string_find_cstr(t_string *str, const char *cstr);

// Same as string_concat, except it concatenates the cstring instead of
// a string
t_string	*string_concat_cstr(t_string *str, char const *cstr);

// Same as string_append, except it appends the cstring instead of a
// string
void		string_append_cstr(t_string *str, char const *cstr);

// Same as string_trim, except the set is specified as a cstring instead
// of a string
t_string	*string_trim_cstr(t_string *str, char const *set);

// Splits the string by character c into a list of strings 
t_list		*string_split(t_string *str, char c);

// Map the characters of a string into a new one
t_string	*string_map(t_string *str, char (*f)(char, unsigned int));

// Apply a function over all characters of a string
void		string_apply(t_string *str, void (*f)(char, unsigned int));

// Create a new string by applying filter function to a string
t_string	*string_filter(t_string *str, t_bool (*f)(char, unsigned int));

// Create a reversed string
t_string	*string_reverse(t_string *str);

// Create a substring from a string, starting at s and ending at e
t_string	*string_substring(t_string *str, unsigned int s, unsigned int e);

// Helper function to delete a string from within list_iapply (Deprecated)
void		string_delete_as_element(void *str, t_uint i);

// Same as string_append, except the string in the first argument gets appended
// to the one in the second argument
void		string_append2(t_string *str2, t_string *str);

// String equality check
t_bool		string_equal(t_string *str, t_string *str2);

// String hashing using mewmew hash
t_uint		string_hash(t_string *str);

// Interpolate provided parameters into a template string
t_string	*string_format(t_string *fmt_str, ...);

// Interpolate provided parameter list into a template string
t_string	*string_vformat(t_string *fmt_str, va_list *args);

#endif
