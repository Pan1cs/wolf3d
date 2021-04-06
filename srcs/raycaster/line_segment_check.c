/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_segment_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:03:40 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/06 13:36:39 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

/*
** Point is not in the wall calculation checks that are two vectors colinear.
** If they are not, then the point cannot be in the wall.
** If they are, we check the dot product. If dot product of ab and ac is
** greater than zero and dot product of ac is less than ab, then the point
** is on the wall.
*/

int		point_is_on_the_wall(t_xy a, t_xy c, t_xy b)
{
	t_xy	vec_ab;
	t_xy	vec_ac;
	float	dot_ab_ab;
	float	dot_ab_ac;

	vec_ab = vec2_dec(b, a);
	vec_ac = vec2_dec(c, a);
	if (vec2_cross(vec_ab, vec_ac) != 0)
		return (0);
	dot_ab_ab = vec2_dot(vec_ab, vec_ab);
	dot_ab_ac = vec2_dot(vec_ab, vec_ac);
	if (dot_ab_ac > 0 && dot_ab_ac < dot_ab_ab)
		return (1);
	else
		return (0);
}

int		orientation_of_three_points(t_xy a, t_xy b, t_xy c)
{
	float	slope;

	slope = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	if (slope == 0)
		return (colinear);
	if (slope > 0)
		return (clockwise);
	else
		return (c_clockwise);
}

int		check_if_lseg_intersects(t_point *p0, t_xy pos, t_xy dir)
{
	int		o1;
	int		o2;
	int		o3;
	int		o4;

	o1 = orientation_of_three_points(p0->x0, p0->next->x0, pos);
	o2 = orientation_of_three_points(p0->x0, p0->next->x0, dir);
	o3 = orientation_of_three_points(pos, dir, p0->x0);
	o4 = orientation_of_three_points(pos, dir, p0->next->x0);
	if (o1 != o2 && o3 != o4)
		return (1);
	if (o1 == 0 && point_is_on_the_wall(p0->x0, pos, p0->next->x0))
		return (1);
	if (o2 == 0 && point_is_on_the_wall(p0->x0, dir, p0->next->x0))
		return (1);
	if (o3 == 0 && point_is_on_the_wall(pos, p0->x0, dir))
		return (1);
	if (o4 == 0 && point_is_on_the_wall(pos, p0->next->x0, dir))
		return (1);
	return (0);
}
