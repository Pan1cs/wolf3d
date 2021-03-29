/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:27:22 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 15:44:45 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		draw_tex_pixel(SDL_Surface *tex, t_xyz texel,
	t_xy pixel, t_frame *frame)
{
	Uint32		color;

	SDL_LockSurface(tex);
	color = get_pixel(tex, texel.x * tex->w, texel.y * tex->h);
	color = colour_scale(color, frame->left.wall->wall_facing);
	SDL_UnlockSurface(tex);
	put_pixel(frame->draw_surf, pixel.x, pixel.y, color);
}
