/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <joonas.hj.nivala@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:27:48 by tmaarela          #+#    #+#             */
/*   Updated: 2021/03/19 14:29:33 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../doom_nukem.h"

void			draw_2d_fov(t_frame *frame, t_player *plr)
{
	// t_xy fov_left;
	// t_xy fov_right;
	t_xy offset;
	// t_xy plr_pos;

	// plr_pos = plr->pos;
	offset = vec2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	// fov_left = vec2_rot(plr->dir, -FOV * 0.5);
	// fov_right = vec2_rot(plr->dir, FOV * 0.5);
	draw_rect_center(vec2_add(vec2(0,0), offset), vec2(5, 5), frame);
	// ft_draw_line(vec2_add(plr_pos, offset), vec2_add(vec2_add(plr_pos,
	// 	vec2_mul(fov_left, 400)), offset), lightgreen, frame->draw_surf);
	// ft_draw_line(vec2_add(plr_pos, offset), vec2_add(vec2_add(plr_pos,
	// 	vec2_mul(fov_right, 400)), offset), lightgreen, frame->draw_surf);
	// ft_draw_line(vec2_add(plr_pos, offset), vec2_add(vec2_add(plr_pos,
	// 	vec2_mul(plr->dir, 400)), offset), lightgreen, frame->draw_surf);
}

void			draw_text(t_home *home, char *text, t_frame *frame, t_xy pos)
{
	SDL_Rect	rect;

	SDL_Color color = {255, 255, 255, 255};
	home->text_surf = TTF_RenderText_Solid(home->font, text, color);
	rect.x = pos.x;
	rect.y = pos.y;
	SDL_BlitSurface(home->text_surf, NULL, frame->draw_surf, &rect);
	SDL_FreeSurface(home->text_surf);
}

void			draw_2d(t_home *home, t_frame *frame, t_player *plr)
{
	static t_xy	prev_pos;

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
	draw_text(home, "x:", frame, (t_xy){10.0f, 10.0f});
	draw_text(home, ft_ftoa(plr->pos.x, 7, 1), frame, (t_xy){10.0f, 30.0f});
	draw_text(home, "y:", frame, (t_xy){10.0f, 50.0f});
	draw_text(home, ft_ftoa(plr->pos.y, 7, 1), frame, (t_xy){10.0f, 70.0f});
	draw_text(home, "dir:", frame, (t_xy){10.0f, 90.0f});
	draw_text(home, ft_ftoa(plr->dir.x, 7, 1), frame, (t_xy){10.0f, 110.0f});

}
