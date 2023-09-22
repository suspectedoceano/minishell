/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydefines.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:07 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/03/20 13:41:08 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YDEFINES_H
# define YDEFINES_H
# ifndef YNULL
#  define YNULL 0
// #  define YNULL (void *)0
// #  define YNULL (0)

// A function call replacement for a proper YNULL macro
void	*nil(void);
# endif
#endif
