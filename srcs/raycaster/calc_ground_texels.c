/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:50:43 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/23 14:16:34 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../doom_nukem.h"

static void		calc_dist_traveled(t_sector *sector, t_frame *frame, t_texture *tex)
{
	frame->ground_uv_t_l.x = interpolate_points(sector->floor_top_left.x,
		frame->left.l_pt.x, sector->floor_top_left.x, sector->floor_top_right.x);
	frame->ground_uv_t_l.y = interpolate_points(sector->floor_top_left.y,
		frame->left.l_pt.y, sector->floor_top_left.y, sector->floor_bottom_left.y);
	frame->ground_uv_t_r.x = interpolate_points(sector->floor_top_left.x,
		frame->left.r_pt.x, sector->floor_top_left.x, sector->floor_top_right.x);
	frame->ground_uv_t_r.y = interpolate_points(sector->floor_top_left.y,
		frame->left.r_pt.y, sector->floor_top_left.y, sector->floor_bottom_left.y);
	frame->ground_uv_b_l.x = interpolate_points(0.0f, sector->floor_bottom_left.x,
		sector->floor_top_left.x, sector->floor_top_right.x);
	frame->ground_uv_b_l.y = interpolate_points(0.0f, sector->floor_bottom_left.y,
		sector->floor_top_left.y, sector->floor_bottom_left.y);
	frame->ground_uv_b_r.x = interpolate_points(0.0f, sector->floor_bottom_right.x,
		sector->floor_top_left.x, sector->floor_top_right.x);
	frame->ground_uv_b_r.y = interpolate_points(0.0f, sector->floor_bottom_left.y,
		sector->floor_top_left.y, sector->floor_bottom_left.y);
}


static void		calc_inverse_of_z(t_sector *sector, t_frame *frame, t_texture *tex)
{
	frame->ground_uv_t_l = inv_z((t_xyz){frame->ground_uv_t_l.x, frame->ground_uv_t_l.y, frame->bottom_left.z});
	frame->ground_uv_b_l = inv_z((t_xyz){frame->ground_uv_b_l.x, frame->ground_uv_b_l.y, 1.0f});
	frame->ground_uv_t_r = inv_z((t_xyz){frame->ground_uv_t_r.x, frame->ground_uv_t_r.y, frame->bottom_right.z});
	frame->ground_uv_b_r = inv_z((t_xyz){frame->ground_uv_b_r.x, frame->ground_uv_b_r.y, 1.0f});
}

/*
**	Here we calculate how much we have traversed the given ground texels.
**	Height to the floor is the z that we are traveling.
*/
void			calc_ground_texels(t_sector *sector, t_frame *frame, t_texture *tex)
{
	calc_dist_traveled(sector, frame, tex);
	calc_inverse_of_z(sector, frame, tex);
	frame->ground_uv_step.x = interpolate_points(frame->ground_uv_t_l.x,
		frame->ground_uv_t_r.x, frame->bottom_left.x, frame->bottom_right.x);
	frame->ground_uv_step.y = interpolate_points(frame->ground_uv_t_l.y,
		frame->ground_uv_b_l.y, frame->bottom_left.y, SCREEN_HEIGHT);
	frame->ground_uv_step.z = interpolate_points(frame->ground_uv_t_l.z,
		frame->ground_uv_t_r.z, frame->bottom_left.x, frame->bottom_right.x);
}
