/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:14:05 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 13:04:28 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

float	ft_map(float in, t_range from, t_range to)
{
	return (to.x + ((in - from.x) * (to.y - to.x)) / (from.y - from.x));
}

float	vec2_to_screen_space(float x, float z)
{
	return (SCREEN_WIDTH - ((SCREEN_HEIGHT / z) * x) + 15);
}

float	interpolate_points(float x0, float x1, float y0, float y1)
{
	return ((x1 - x0) / (y1 - y0));
}

/*
**	If we define dx = x2 - x1 and dy = y2 - y1,
**	then the normals are (-dy, dx) and (dy, -dx).
*/

t_xy	vec2_normal(t_xy p0, t_xy p1)
{
	return ((t_xy){(p1.y - p0.y), -(p1.x - p0.x)});
}

t_xy	vec2_halfway(t_xy p0, t_xy p1)
{
	return ((t_xy){(p0.x + p1.x) * 0.5, (p0.y + p1.y) * 0.5});
}
