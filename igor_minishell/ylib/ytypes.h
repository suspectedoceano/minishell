/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ytypes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:27 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 11:38:28 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YTYPES_H
# define YTYPES_H

// Because "unsigned int" is too long
typedef unsigned int	t_uint;
typedef long int		t_uint_ptr;
typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;

// A structure representing the list of pointers to the data.
// s_list does not own the values themselves
typedef struct s_list
{
	unsigned int	size;
	unsigned int	capacity;
	void			**data;
}	t_list;

// List iterator
typedef struct s_list_iter
{
	void			*value;
	unsigned int	i;
	t_list			*list;
}	t_list_iter;

// Represents a boolean value
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// Represents a mutable, null-termintated string
typedef struct s_string
{
	char			*cstr;
	unsigned int	size;
}	t_string;

// 2D vector of integers
typedef struct s_ivec2
{
	int	x;
	int	y;
}	t_ivec2;

// 2D vector of doubels
typedef struct s_dvec2
{
	double	x;
	double	y;
}	t_dvec2;

// Hash function for hash maps and sets
typedef t_uint			(*t_hash_func)(void *);

// Equals function for hash maps and sets
typedef t_bool			(*t_equals_func)(void *, void *);

// Hash Map item container (is private/not meant to be used outside of yLib)
struct s_map_item_container
{
	t_uint	hash;
	void	*key;
	void	*item;
};

// Hash Map bucket container (is private/not meant to be used outside of yLib)
struct	s_map_bucket
{
	t_bool						is_list;
	t_list						items;
	struct s_map_item_container	container;
};

// Hash Map container
typedef struct s_map
{
	t_hash_func			hash_func;
	t_equals_func		equals_func;
	struct s_map_bucket	*bucket_array;
	t_uint				bucket_array_size;
	double				upper_realloc_ratio;
	double				lower_realloc_ratio;
	t_uint				upper_realloc_value;
	t_uint				lower_realloc_value;
	double				scaling_ratio;
	t_uint				size;
}	t_map;

// TODO: Map key-value pair iterator
typedef struct s_map_iter
{
	void	*value;
	void	*key;
	t_uint	i;
	t_map	*map;
}	t_map_iter;

#endif
