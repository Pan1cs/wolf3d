/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:38:16 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 11:14:00 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xy			vec2_rot(t_xy v, float angle)
{
	return ((t_xy){
		v.x * cosf(angle) - v.y * sinf(angle),
		v.x * sinf(angle) + v.y * cosf(angle)
	});
}

float			vec2_dot(t_xy a, t_xy b)
{
	return (a.x * b.x + a.y * b.y);
}

float			vec2_mag(t_xy a)
{
	return (sqrtf(a.x * a.x + a.y * a.y));
}

float			vec2_ang(t_xy a, t_xy b)
{
	return (acosf(vec2_dot(a, b) / (vec2_mag(a) * vec2_mag(b))));
}
