/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:37:06 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/06 14:48:24 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static float	round_angle(float angle, float *pxl_offset)
{
	float			angle_as_pixels;
	int				trunc;

	angle_as_pixels = angle / 0.002454369f;
	trunc = (int)angle_as_pixels;
	*pxl_offset = angle_as_pixels - trunc + *pxl_offset;
	if (*pxl_offset >= 1.0f)
	{
		*pxl_offset = *pxl_offset - 1.0f;
		return ((float)(trunc + 1.0f));
	}
	else
		return ((float)trunc);
}

SDL_Surface		*get_tex(int idx, SDL_Surface **textures)
{
	if (idx >= 0)
		error_output("idx larger or equal to zero\n");
	return (textures[abs(idx)]);
}

void			scan_fov(t_home *home, t_frame *frame, t_player *plr,
	int cur_pxl)
{
	t_frame		new_frame;

	frame->left.wall = home->sectors[frame->idx]->points;
	frame->right.wall = home->sectors[frame->idx]->points;
	continue_from_last_sector(frame->left.wall, &frame->left, frame);
	while (frame->offset > frame->max_fov)
	{
		get_wall_pts(frame, home->sectors[frame->idx]->nbr_of_walls, cur_pxl);
		cur_pxl = round_angle(vec2_ang(frame->left.l_pt, frame->left.r_pt),
					&frame->pxl_offset);
		if (check_if_portal(frame->left.wall) &&
			!check_if_same_pt(&cur_pxl, &frame->left))
		{
			setup_frame(frame, &new_frame, cur_pxl, frame->left.wall->idx);
			scan_fov(home, &new_frame, plr, 0);
			draw_segment(frame, home, plr, 0);
			frame->offset = new_frame.offset;
			frame->pxl_offset = new_frame.pxl_offset;
		}
		else
		{
			draw_segment(frame, home, plr, 1);
			frame->offset = frame->offset - ++cur_pxl;
		}
	}
}
