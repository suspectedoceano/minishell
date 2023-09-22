/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:43:02 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/10 11:43:04 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YLIST_H
# define YLIST_H
# include "ytypes.h"
# ifndef LIST_C_STEP
#  define LIST_C_STEP 20
# endif

// Allocates and initializes an empty list
t_list		*list_new(void);

// Initializes an empty list
t_bool		list_init(t_list *list);

// Private function! Reallocates the list to the new capacity
void		_list_realloc(t_list *list, unsigned int new_size);

// Deinitializes and deallocates the list itself (but not the elements)
void		list_delete(t_list *list);

// Deinitializes the list itself (but not the elements)
void		list_deinit(t_list *list);

// Insert the element to the back of the list
void		list_insert(t_list *list, void *e);

// Insert the element into the i-th place of the list
void		list_insert_at(t_list *list, unsigned int i, void *e);

// Remove element from the list
void		list_remove(t_list *list, void *e);

// Remove the i-th element from the list
void		list_remove_at(t_list *list, unsigned int i);

// Retrieve a value of i-th element of the list
void		*list_get(t_list *list, unsigned int i);

// Set a value of i-th element of the list
void		list_set(t_list *list, unsigned int i, void *element);

// Perform a shallow copy
t_list		*list_copy(t_list *list);

// Removes and returns the last element from the list 
void		*list_pop(t_list *list);

typedef void	(*t_apply_func)(void *);

// Apply a function to each list element
void		list_apply(t_list *list, t_apply_func f);

typedef void	*(*t_map_func)(void *);

// Build a new list by applying mapping function to a given list
t_list		*list_map(t_list *list, t_map_func f);

typedef t_bool	(*t_filter_func)(void *);

// Retaining-based filter
void		list_filter(t_list *list, t_filter_func f);

// Build a new, filtered list
t_list		*list_filter_new(t_list *list, t_filter_func f);

typedef void	(*t_iapply_func)(void *, unsigned int);

// Apply a function to each list element with indexes
void		list_iapply(t_list *list, t_iapply_func f);

typedef void	*(*t_imap_func)(void *, unsigned int);

// Build a new list by applying mapping function with index to a given list
t_list		*list_imap(t_list *list, t_imap_func f);

// A helper function to quickly free a single element using free from stdlib
// with index
void		free_list_element_i(void *e, unsigned int i);

typedef t_bool	(*t_ifilter_func)(void *, unsigned int);

// Retaining-based filter
void		list_ifilter(t_list *list, t_ifilter_func f);

// Build a new, filtered list
t_list		*list_ifilter_new(t_list *list, t_ifilter_func f);

typedef void	(*t_capply_func)(void *, void *);

// Apply a function to each list element
void		list_capply(t_list *list, t_capply_func f, void *context);

typedef void	*(*t_cmap_func)(void *, void *);

// Build a new list by applying mapping function to a given list
t_list		*list_cmap(t_list *list, t_cmap_func f, void *context);

typedef t_bool	(*t_cfilter_func)(void *, void *);

// Retaining-based filter
void		list_cfilter(t_list *list, t_cfilter_func f, void *context);

// Build a new, filtered list
t_list		*list_cfilter_new(t_list *list, t_cfilter_func f, void *context);

typedef void	(*t_icapply_func)(void *, unsigned int, void *);

// Apply a function to each list element with context
void		list_icapply(t_list *list, t_icapply_func f, void *context);

typedef void	*(*t_icmap_func)(void *, unsigned int, void *);

// Build a new list by applying mapping function to a given list with context
t_list		*list_icmap(t_list *list, t_icmap_func f, void *context);

typedef t_bool	(*t_icfilter_func)(void *, unsigned int, void *);

// Retaining-based filter with context
void		list_icfilter(t_list *list, t_icfilter_func f, void *context);

// Build a new, filtered list with context
t_list		*list_icfilter_new(t_list *list, t_icfilter_func f, void *context);

// Creates a list iterator for the list
t_list_iter	list_iter(t_list *list);

// Creates a list iterator and points it to the first index of the list
t_list_iter	list_iter_first(t_list *list);

// Creates a list iterator and points it to the last index of the list
t_list_iter	list_iter_last(t_list *list);

// Iterates to the next value
t_bool		list_iter_next(t_list_iter *iter);

// Iterates to the previous value
t_bool		list_iter_prev(t_list_iter *iter);

// Sets iteration index to the start of the list
void		list_iter_begin(t_list_iter *iter);

// Sets iteration index to the end of the list
void		list_iter_end(t_list_iter *iter);

#endif
