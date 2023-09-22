/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yio.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:54:35 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 12:54:36 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YIO_H
# define YIO_H
# ifndef GNL_BSIZE
#  define GNL_BSIZE 20
# endif
# ifndef GNL_CSTEP
#  define GNL_CSTEP 30
# endif
# include "ytypes.h"

// Used to store file contents while reading from it
typedef struct s_file_cache_node
{
	char			content[GNL_BSIZE];
	int				fd;
	unsigned int	read_index;
}	t_fcnode;

// Represents a list of file cache nodes
typedef struct s_file_cache
{
	unsigned int	size;
	unsigned int	capacity;
	t_fcnode		*node_array;
}	t_file_cache;

// Private function!
// Creates a new cache node in the cache and returns a pointer to it
t_fcnode		*_new_cache_node(t_file_cache *c, unsigned int fd, char *ct);

// Private function!
// Retrieves cache node from the file descriptor
// Returns NULL if node doesnt exist
t_fcnode		*_get_cache_node(t_file_cache *cache, int fd);

// Private function!
// Stores cache node under a file descriptor fd. Creates fd node if
// it doesn't exist yet. If content is NULL or empty string, removes fd
// node
// Returns 1 if node is not exhausted, otherwise returns 0 and removes node
// from the cache
unsigned int	_update_cache_node(t_file_cache *cache, t_fcnode *node);

// Return the next line from specified file descriptor. Returns NULL/YNULL if
// file descriptor is exhausted
char			*get_next_line(int fd);

// Write cstring to file descriptor
void			write_cstr_fd(int fd, const char *s);

// Try to open file at path str, with specified flags. Returns TRUE upon
// success and sets value of fd to the opened file descriptor. Otherwise
// returns FALSE
t_bool			try_open_file(const t_string *str, int flags, int *fd);

// Same as try_open_file, except the path is specified with cstring instead
// of string
t_bool			try_open_file_cstr(const char *cstr, int flags, int *fd);

// Read file from fd in its entirety into a list of strings. Returns
// NULL/YNULL if file descriptor is invalid
t_list			*read_fd_to_lines(int fd);

// Read file at path str with specified flags into a list of strings.
// Returns NULL/YNULL if file descriptor is invalid
t_list			*read_file_to_lines(const t_string *str, int flags);

// Same as read_file_to_lines, except the path is specified with cstring
// instead of string
t_list			*read_file_to_lines_cstr(const char *str, int flags);

#endif
