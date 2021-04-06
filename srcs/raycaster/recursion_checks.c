/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 08:51:30 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/06 12:02:13 by jnivala          ###   ########.fr       */
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

int		check_if_same_pt(int current_pxl, t_ray_pt *fov)
{
	float	left_z;
	float	right_z;
	float	left_x;
	float	right_x;


	if (current_pxl == 0)
	{
		left_z = vec2_perp_dist(fov->l_pt); 
		right_z = vec2_perp_dist(fov->r_pt);
		left_x = SCREEN_WIDTH - ((SCREEN_HEIGHT / left_z) * fov->l_pt.x) + 15;
		right_x = SCREEN_WIDTH - ((SCREEN_HEIGHT / right_z) * fov->r_pt.x) + 15;
		if (right_x - left_x < 1.0f)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

int		check_connection(t_point *point, t_frame *frame)
{
	return ((point->idx == frame->old_idx) ? TRUE : FALSE);
}
