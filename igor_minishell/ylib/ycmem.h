/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycmem.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:49:22 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/20 13:49:23 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YCMEM_H
# define YCMEM_H

// Set the value of len bytes at b to the value of c
void	*ymem_set(void *b, char c, unsigned int len);

// Copy n bytes from src to dst (the equivalent of memcpy) If memory areas
// overlap, the behavior is undefined.
void	*ymem_copy(void *dst, const void *src, unsigned int n);

#endif
