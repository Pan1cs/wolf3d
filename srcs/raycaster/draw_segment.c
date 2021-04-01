/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:50:43 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/31 15:59:32 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		draw_vertical_floor_strip(t_xyz offset, size_t height,
							int colour, t_frame *frame)
{
	size_t	cur_y;
	// float	scale;

	if (offset.x < 0 || offset.x > SCREEN_WIDTH)
		return ;
	cur_y = 0;
	while (cur_y < height)
	{
		//scale = (height / (2.0 * cur_y - height)) / offset.z;
		// scale = SCREEN_HEIGHT / ((cur_y + height) - SCREEN_HEIGHT) / offset.z;
		// scale = 1.0f - scale;
		if (cur_y + offset.y >= 0 && cur_y + offset.y < SCREEN_HEIGHT)
			// put_pixel(frame->draw_surf, offset.x,
			// 	cur_y + offset.y, colour_scale(colour, scale));
			put_pixel(frame->draw_surf, offset.x,
				cur_y + offset.y, colour);
		cur_y++;
	}
}

static void		draw_vertical_wall_strip(t_xy offset, size_t height,
							SDL_Surface *tex, t_frame *frame)
{
	size_t	cur_y;
	t_xyz	corr_texel;
	t_xyz	texel;
	int		i;

	if (offset.x < 0 || offset.x > SCREEN_WIDTH)
		return ;
	cur_y = 0;
	i = 0;
	texel = frame->uv_top_left;
	corr_texel = texel;
	while (cur_y < height)
	{
		if (i++ % 16)
			corr_texel = inv_z(texel);
		if (cur_y + offset.y >= 0 && cur_y + offset.y < SCREEN_HEIGHT)
			draw_tex_pixel(tex, corr_texel,
				(t_xy){offset.x, cur_y + offset.y}, frame);
		cur_y++;
		texel.y += frame->uv_step.y;
	}
}

void			step_one(t_xyz *start, t_xyz *bottom,
	size_t *obj_x, t_frame *frame)
{
	start->y -= frame->step.y;
	bottom->y += frame->step.y;
	start->z -= frame->step.z;
	frame->uv_top_left.x += frame->uv_step.x;
	frame->uv_top_left.z += frame->uv_step.z;
	*obj_x = *obj_x + 1;
}

void			draw_vertically(t_frame *frame, t_home *home,
	SDL_Surface *wall_tex, int wall)
{
	size_t		obj_x;
	t_xyz		start;
	t_xyz		end;
	t_xyz		bottom;
	int			tex_floor;

	obj_x = 0;
	start = frame->top_left;
	end = frame->top_right;
	bottom = frame->bottom_left;
	tex_floor = get_floor(home->sectors[frame->idx]->tex_floor);
	while (obj_x + start.x < end.x)
	{
		if (wall)
			draw_vertical_wall_strip(
				vec2(start.x + obj_x, start.y), (bottom.y - start.y),
				wall_tex, frame);
		draw_vertical_floor_strip(
			vec3(start.x + obj_x, bottom.y, bottom.z),
			((SCREEN_HEIGHT - bottom.y) < 0 ? 0 : SCREEN_HEIGHT - bottom.y),
			tex_floor, frame);
		step_one(&start, &bottom, &obj_x, frame);
	}
}

void			draw_segment(t_frame *frame, t_home *home,
	t_player *plr, int wall)
{
	SDL_Surface	*wall_tex;

	if (wall)
		wall_tex = get_tex(frame->left.wall->idx, home->editor_tex);
	else
		wall_tex = get_tex(-1, home->editor_tex);
	calc_distances(frame, plr);
	calc_wall_texels(frame, wall_tex);
	draw_vertically(frame, home, wall_tex, wall);
}
