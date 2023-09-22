/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yvec2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhrabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:08:16 by ihhrabar          #+#    #+#             */
/*   Updated: 2023/05/04 12:08:17 by ihhrabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YVEC2_H
# define YVEC2_H
# include "ydefines.h"
# include "ytypes.h"

// Create a new integer vector with specified x and y components
t_ivec2	ivec2_new(int x, int y);

// Create a new integer vector with x and y being equal to 0
t_ivec2	ivec2_zero(void);

// Sum of 2 int 2D vectors
t_ivec2	ivec2_add(t_ivec2 a, t_ivec2 b);

// Difference of 2 2D int vectors
t_ivec2	ivec2_sub(t_ivec2 a, t_ivec2 b);

// Dot product of 2 2D int vectors
int		ivec2_dot(t_ivec2 a, t_ivec2 b);

// Int 2D vector scaled by int scalar
t_ivec2	ivec2_scale(t_ivec2 a, int scalar);

// Int 2D vector scaled by 1/scalar
t_ivec2	ivec2_divide(t_ivec2 a, int scalar);

// Int 2D vector scaled by double scalar
t_ivec2	ivec2_dscale(t_ivec2 a, double scalar);

// Length of an int 2D vector
double	ivec2_length(t_ivec2 a);

// Squared length of an int 2D vector
double	ivec2_length_sq(t_ivec2 a);

// Check if 2 int 2D vectors are equal
t_bool	ivec2_eq(t_ivec2 a, t_ivec2 b);

// Inverse of an int 2D vector
t_ivec2	ivec2_negate(t_ivec2 a);

// Normalized vector that points to the same direction as the int 2D vector
t_dvec2	ivec2_normalized(t_ivec2 a);

// Create a new double 2D vector with specified x and y components
t_dvec2	dvec2_new(double x, double y);

// Create a new double 2D vector with x and y being equal to 0.0
t_dvec2	dvec2_zero(void);

// Sum of 2 double 2D vectors
t_dvec2	dvec2_add(t_dvec2 a, t_dvec2 b);

// Difference of 2 double 2D vectors
t_dvec2	dvec2_sub(t_dvec2 a, t_dvec2 b);

// Dot product of 2 double 2D vectors
double	dvec2_dot(t_dvec2 a, t_dvec2 b);

// Double 2D vector scaled by double scalar
t_dvec2	dvec2_scale(t_dvec2 a, double scalar);

// Double 2D vector scaled by 1/scalar
t_dvec2	dvec2_divide(t_dvec2 a, double scalar);

// Length of a double 2D vector
double	dvec2_length(t_dvec2 a);

// Squared length of a double 2D vector
double	dvec2_length_sq(t_dvec2 a);

// Inverse of a double 2D vector
t_dvec2	dvec2_negate(t_dvec2 a);

// Normalized vector that points to the same direction as the double 2D vector
t_dvec2	dvec2_normalized(t_dvec2 a);

#endif
