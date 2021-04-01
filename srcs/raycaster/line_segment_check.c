/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_segment_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:03:40 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/01 11:40:41 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

/*
** Point is not in the wall calculation checks that are two vectors colinear.
** If they are not, then the point cannot be in the wall.
** If they are, we check the dot product. If it is less than zero, or greater
** than the dot product of the wall points, it means that point is either
** left or right side of the wall and does not cut it.
*/

int		point_is_not_in_the_wall(t_xy a, t_xy c, t_xy b)
{
	t_xy	vec_ab;
	t_xy	vec_ac;
	float	dot_ab_ab;
	float	dot_ab_ac;

	vec_ab = vec2_dec(b, a);
	vec_ac = vec2_dec(c, a);
	if (vec2_cross(vec_ab, vec_ac) != 0)
		return (1);
	dot_ab_ab = vec2_dot(vec_ab, vec_ab);
	dot_ab_ac = vec2_dot(vec_ab, vec_ac);
	if (dot_ab_ac < 0 || dot_ab_ac > dot_ab_ab)
		return (1);
	else
		return (0);
}

int		check_if_lseg_intersects(t_point *p0, t_xy pos, t_xy dir)
{
	t_xy	v1;
	t_xy	v2;
	t_xy	v3;
	float	t1;
	float	t2;

	v1 = vec2_dec(pos, p0->x0);
	v2 = vec2_dec(p0->next->x0, p0->x0);
	v3 = vec2(-dir.y, dir.x);
	t1 = fabs(vec2_cross(v2, v1)) / vec2_dot(v2, v3);
	t2 = vec2_dot(v1, v3) / vec2_dot(v2, v3);
	if (t1 >= 0 && t2 >= 0 && t2 <= 1)
		return (1);
	return (0);
}
