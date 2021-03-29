/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:47:19 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 11:11:20 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			draw_2d_fov(t_frame *frame, t_player *plr)
{
	t_xy	offset;
	char	*dir_x;
	char	*pos_x;
	char	*pos_y;

	// plr_pos = plr->pos;
	offset = vec2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	// fov_left = vec2_rot(plr->dir, -FOV * 0.5);
	// fov_right = vec2_rot(plr->dir, FOV * 0.5);
	draw_rect_center(vec2_add(vec2(0,0), offset), vec2(5, 5), frame);
	dir_x = ft_ftoa(plr->dir.x, 7);
	pos_x = ft_ftoa(plr->pos.x, 5);
	pos_y = ft_ftoa(plr->pos.y, 5);
	str_pxl(frame, (t_xy){0, 10}, "x: ");
	str_pxl(frame, (t_xy){50, 10}, pos_x);
	str_pxl(frame, (t_xy){0, 30}, "y: ");
	str_pxl(frame, (t_xy){50, 30}, pos_y);
	str_pxl(frame, (t_xy){0, 50}, "dir: ");
	str_pxl(frame, (t_xy){50, 50}, dir_x);
	free(dir_x);
	free(pos_x);
	free(pos_y);
	// ft_draw_line(vec2_add(plr_pos, offset), vec2_add(vec2_add(plr_pos,
	// 	vec2_mul(fov_left, 400)), offset), lightgreen, frame->draw_surf);
	// ft_draw_line(vec2_add(plr_pos, offset), vec2_add(vec2_add(plr_pos,
	// 	vec2_mul(fov_right, 400)), offset), lightgreen, frame->draw_surf);
	// ft_draw_line(vec2_add(plr_pos, offset), vec2_add(vec2_add(plr_pos,
	// 	vec2_mul(plr->dir, 400)), offset), lightgreen, frame->draw_surf);
}

void			draw_2d(t_home *home, t_frame *frame, t_player *plr)
{
	frame->idx = plr->current_sector;
	frame->old_idx = -1;
	frame->max_fov = 0;
	frame->offset = 640;
	frame->left.l_pt = vec2(-1,-1);
	frame->right.r_pt = vec2(-1,-1);
	frame->plr_offset = vec2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	frame->pxl_offset = 0.0f;
	scan_fov(home, frame, plr, 0);
	draw_2d_fov(frame, plr);


}
