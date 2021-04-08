/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:27:22 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 12:26:49 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		draw_tex_pixel(t_texture *tex, t_xyz texel,
	t_xy pixel, t_frame *frame)
{
	Uint32		color;

	color = get_texel2(tex, texel.x * tex->w, texel.y * tex->h);
	color = colour_scale(color, frame->left.wall->wall_facing);
	put_pixel(frame->draw_surf, pixel.x, pixel.y, color);
}
