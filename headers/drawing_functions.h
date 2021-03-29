/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:58:56 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 15:04:03 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_FUNCTIONS_H
# define DRAWING_FUNCTIONS_H

/*
** Drawing functions
*/

void			clear_surface(SDL_Surface *surface);
int				ft_put_pixel(float x, float y, int color, SDL_Renderer *ren);
int				draw_line(t_xy start, t_xy end, int color, SDL_Surface *surf);
void			draw_rect_center(t_xy xy, t_xy wh, t_frame *frame);
void			draw_rect(t_xy xy, t_xy wh, t_frame *frame, int color);
void			draw_minimap(t_home *home, t_player *plr, t_frame *frame);
void			put_pixel(SDL_Surface *surf, int x, int y, int color);
t_step			*steplen(t_step *ground, int current_y, t_ray_floor hor,
	t_player *plr);
Uint32			get_pixel(SDL_Surface *surface, int x, int y);
void			draw_tex_pixel(SDL_Surface *tex, t_xyz texel,
					t_xy pixel, t_frame *frame);
#endif
