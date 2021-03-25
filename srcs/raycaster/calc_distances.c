/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distances.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:50:43 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/25 09:54:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	calc_distances(t_frame *frame, t_player *plr)
{
	float	left_z;
	float	right_z;

	left_z = vec2_perp_dist(frame->left.l_pt);
	right_z = vec2_perp_dist(frame->left.r_pt);
	frame->top_left.x = SCREEN_WIDTH - ((SCREEN_HEIGHT /
		left_z) * frame->left.l_pt.x) + 15;
	frame->top_right.x = SCREEN_WIDTH - ((SCREEN_HEIGHT /
		right_z) * frame->left.r_pt.x) + 15;
	frame->top_left.z = left_z;
	frame->top_right.z = right_z;
	frame->bottom_left = frame->top_left;
	frame->bottom_right = frame->top_right;
	frame->top_left.y = plr->pitch - SCREEN_HEIGHT / left_z * 20;
	frame->top_right.y = plr->pitch - SCREEN_HEIGHT / right_z * 20;
	frame->bottom_left.y = plr->pitch + SCREEN_HEIGHT / left_z * 20;
	frame->bottom_right.y = plr->pitch + SCREEN_HEIGHT / right_z * 20;
	frame->step.y = interpolate_points(frame->top_right.y, frame->top_left.y,
		frame->top_left.x, frame->top_right.x);
	frame->step.z = interpolate_points(frame->top_left.y, frame->top_right.y,
		frame->top_left.x, frame->top_right.x);
}
