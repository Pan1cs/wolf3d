/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:58:32 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 12:24:51 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATIONS_H
# define CALCULATIONS_H

typedef struct		s_time
{
	Uint32	*frame_times;
	Uint32	frame_time_last;
	Uint32	frame_count;
	float	fps;
}					t_time;

typedef	struct		s_intersection
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	den;
	float	neg;
	float	pos;
}					t_intersection;

#endif
