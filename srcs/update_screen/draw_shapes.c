/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:38:35 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 08:54:38 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		draw_line(t_xy p0, t_xy p1, int colour, SDL_Surface *surf)
{
	t_xy		delta;
	t_xy		pixel;
	long int	pixels;

	delta.x = p1.x - p0.x;
	delta.y = p1.y - p0.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	pixel.x = p0.x;
	pixel.y = p0.y;
	while (pixels)
	{
		put_pixel(surf, (int)pixel.x, (int)pixel.y, colour);
		pixel.x += delta.x;
		pixel.y += delta.y;
		--pixels;
	}
	return (TRUE);
}

void	draw_rect(t_xy xy, t_xy wh, t_frame *frame, int color)
{
	float	j;
	float	i;

	i = xy.x;
	j = xy.y;
	while (j < wh.y + xy.y)
	{
		draw_line(vec2(i, j), vec2(i + wh.x, j), color, frame->draw_surf);
		j++;
	}
}

void	draw_rect_center(t_xy xy, t_xy wh, t_frame *frame)
{
	float	j;
	float	i;

	i = -wh.x / 2;
	j = -wh.y / 2;
	while (j < wh.y / 2 && i < SCREEN_WIDTH && j < SCREEN_HEIGHT)
	{
		draw_line(vec2(xy.x + i, xy.y + j),
			vec2(xy.x + fabs(i), xy.y + j), 0x00A000, frame->draw_surf);
		j++;
	}
}

t_xy	center_to_screen(t_xy loc)
{
	loc.x += 0.5 * SCREEN_WIDTH;
	loc.y += 0.5 * SCREEN_HEIGHT;
	return (loc);
}
