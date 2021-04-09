/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:39 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 12:26:09 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct	s_xy
{
	float		x;
	float		y;
}				t_xy;

typedef t_xy	t_range;

typedef struct	s_xyz
{
	float		x;
	float		y;
	float		z;
}				t_xyz;

typedef struct	s_ray
{
	t_xy		pos;
	t_xy		dir;
	t_xy		cutpoint;
}				t_ray;

typedef struct	s_maxpoints
{
	t_xy		left;
	t_xy		right;
}				t_maxpoints;

float			interpolate_points(float x0, float x1, float y0, float y1);
t_xyz			inv_z(t_xyz a);
t_xy			vec2(float x, float y);
float			vec2_ang(t_xy a, t_xy b);
float			vec2_cross(t_xy a, t_xy b);
float			vec2_dot(t_xy a, t_xy b);
float			vec2_eucl_dist(t_xy p1, t_xy p2);
t_xy			vec2_halfway(t_xy p0, t_xy p1);
float			vec2_mag(t_xy a);
t_xy			vec2_mult(t_xy v, float scalar);
t_xy			vec2_normal(t_xy p0, t_xy p1);
float			vec2_perp_dist(t_xy a);
t_xy			vec2_rot(t_xy v, float angle);
t_xy			vec2_sum(t_xy a, t_xy b);
t_xy			vec2_sub(t_xy a, t_xy b);
t_xy			vec3_to_vec2(t_xyz a);
t_xyz			vec3(float x, float y, float z);

#endif
