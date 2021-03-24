/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:58:32 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 14:58:48 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CALCULATIONS_H
# define CALCULATIONS_H

typedef struct		s_time
{
	clock_t			beginfps;
	clock_t			endfps;
	clock_t			delta_time;
	size_t			frames;
	long int		fps;
}					t_time;

typedef	struct		s_intersection
{
	float	x1;
	float	x2;
	float 	y1;
	float	y2;
	float	den;
	float	neg;
	float	pos;
}					t_intersection;

#endif
