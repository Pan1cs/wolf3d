/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:24 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 12:32:08 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

typedef struct		s_colour_map
{
	char			*id;
	int				colour;
}					t_colour_map;

typedef	struct		s_texture
{
	Uint32			*pixels;
	unsigned char	*map_pixels;
	int				w;
	int				h;
	int				size;
	int				color_type;
	int				color_depth;
	int				format;
	int				bpp;
	int				pitch;
	int				nbr_of_colours;
	int				cpp;
	t_colour_map	**colour_map;
}					t_texture;

typedef	struct		s_item
{
	float			x;
	float			y;
	float			z;
}					t_item;

typedef struct		s_window
{
	SDL_Window		*window;
	SDL_Surface		*ScreenSurface;
	int				width;
	int				height;
}					t_window;

typedef struct		s_raycast
{
	t_xy			sideDist;
	t_xy			deltaDist;
	t_xy			step;
	int				side;
	float			perpWallDist;
}					t_raycast;

typedef struct		s_ray_floor
{
	t_xy			plane;
	t_xy			left;
	t_xy			right;
}					t_ray_floor;

typedef struct		s_step
{
	t_xy			cur_step;
	t_xy			step_len;
}					t_step;

typedef struct		s_tex_col
{
	int				scr_col;
	int				tex_col;
	int				top;
	int				bot;
	int				line_height;
	float			step;
	SDL_Surface		*tex;
}					t_tex_col;

typedef struct		s_wall
{
	t_xy			hit;
	float			distance;
	int				side;
}					t_wall;

typedef struct		s_home
{
	t_window		win;
	t_sector		**sectors;
	SDL_Surface		**editor_tex;
	t_texture		**editor_tex2;
	t_time			t;
	t_xy			offset;
	unsigned int	nbr_of_sectors;
	int				nbr_of_textures;
}					t_home;

#endif
