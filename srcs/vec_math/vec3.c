/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:39:14 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/25 11:55:23 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xyz	vec3(float x, float y, float z)
{
	return ((t_xyz){x, y, z});
}

t_xyz	vec3_add(t_xyz a, t_xyz b)
{
	return ((t_xyz){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_xy	vec3_to_vec2(t_xyz a)
{
	return ((t_xy){a.x, a.y});
}

t_xyz	inv_z(t_xyz a)
{
	a.z = 1.0f / a.z;
	a.x = a.x * a.z;
	a.y = a.y * a.z;
	return (a);
}
