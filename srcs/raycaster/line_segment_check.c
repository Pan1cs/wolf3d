/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_segment_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:03:40 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/01 09:59:20 by jnivala          ###   ########.fr       */
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

// int		are_points_colinear(t_xy p0, t_xy test_point, t_xy p1)
// {
// 	int		clockwise;

// 	clockwise = (test_point.y - p0.y) * (p1.x - test_point.x) -
// 				(test_point.x - p0.x) * (p1.y - test_point.y);
// 	if (!clockwise)
// 		return (0);
// 	else
// 	{
// 		if (clockwise > 0)
// 			return (1);
// 		else
// 			return (2);
// 	}
// }

// int		check_if_lseg_intersects(t_point *p0, t_xy q1, t_xy q2)
// {
// 	int o1 = are_points_colinear(p0->x0, q1, p0->next->x0);
// 	int o2 = are_points_colinear(p0->x0, q1, p0->next->x0);
// 	int o3 = are_points_colinear(p0->next->x0, q2, p0->x0);
// 	int o4 = are_points_colinear(p0->next->x0, q2, p0->x0);
// 	if (o1 != o2 && o3 != o4)
// 		return (1);
// 	if (o1 == 0 && point_is_on_wall(p0->x0, p0->next->x0, q1))
// 		return (1);
// 	if (o2 == 0 && point_is_on_wall(p0->x0, q2, q1))
// 		return (1);
// 	if (o3 == 0 && point_is_on_wall(p0->next->x0, p0->x0, q2))
// 		return (1);
// 	if (o4 == 0 && point_is_on_wall(p0->next->x0, q1, q2))
// 		return (1);
// 	return (0);
// }

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
