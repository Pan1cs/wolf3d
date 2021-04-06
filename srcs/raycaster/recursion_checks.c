/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:51:30 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/06 14:48:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	continue_from_last_sector(t_point *start, t_ray_pt *fov, t_frame *frame)
{
	t_point *p0;

	p0 = start;
	if (frame->old_idx != -1)
	{
		while (p0)
		{
			if (check_connection(p0, frame))
			{
				fov->wall = p0->next;
				return ;
			}
			p0 = p0->next;
		}
	}
}

int		check_if_portal(t_point *p0)
{
	if (p0->idx >= 0)
		return (TRUE);
	else
		return (FALSE);
}

/*
**
**	Checking in the else statement if our angle is neglible compared to a pixel so that
**	we will 100% enter the next sextor.
**
** 	(still needs fine tuning, we need to find a way to fix the 1 pixel black bars.)'
**
*/

int		check_if_same_pt(int *current_pxl, t_ray_pt *fov)
{
	if (*current_pxl > 0
		&& get_distance(fov->l_pt, fov->r_pt) < 0.001)
		return (TRUE);
	else
	{
		if (*current_pxl == 0)
		{
			*current_pxl = 1;
		}
		return (FALSE);
	}
}

// int		check_if_same_pt(int current_pxl, t_ray_pt *fov)
// {
// 	float	left_z;
// 	float	right_z;
// 	float	left_x;
// 	float	right_x;

// 	if (current_pxl == 0)
// 	{
// 		left_z = vec2_perp_dist(fov->l_pt);
// 		right_z = vec2_perp_dist(fov->r_pt);
// 		left_x = SCREEN_WIDTH - ((SCREEN_HEIGHT / left_z) * fov->l_pt.x) + 15;
// 		right_x = SCREEN_WIDTH - ((SCREEN_HEIGHT / right_z) * fov->r_pt.x) + 15;
// 		if (right_x - left_x < 1.0f)
// 			return (TRUE);
// 		else
// 			return (FALSE);
// 	}
// 	else
// 		return (FALSE );
// }

int		check_connection(t_point *point, t_frame *frame)
{
	return ((point->idx == frame->old_idx) ? TRUE : FALSE);
}
