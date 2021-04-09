/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:58:35 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 12:58:10 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct	s_ray_pt
{
	t_ray			ray_l;
	t_ray			ray_r;
	t_xy			l_pt;
	t_xy			r_pt;
	t_point			*wall;
}				t_ray_pt;

typedef struct	s_frame
{
	int				idx;
	int				max_fov;
	int				offset;
	float			min_step;
	int				old_idx;
	SDL_Surface		*draw_surf;
	SDL_Surface		*ground[4];
	float			pxl_offset;
	t_ray_pt		left;
	t_ray_pt		right;
	t_xyz			top_left;
	t_xyz			top_right;
	t_xyz			bottom_left;
	t_xyz			bottom_right;
	t_xyz			uv_top_left;
	t_xyz			uv_top_right;
	t_xyz			uv_bottom_left;
	t_xyz			uv_bottom_right;
	t_xyz			uv_step;
	t_xyz			step;
	float			full_wall_dist;
	float			visible_wall_dist;
	float			unvisible_l_side;
	float			screen_wall_len;
	float			tex_mult;
	float			ratio;
	int				pitch;
}				t_frame;

enum			e_lines {
	colinear = 0,
	clockwise = 1,
	c_clockwise = 2,
};

enum			e_movement {
	open_space = -9999
};

void			calc_distances(t_frame *frame, t_player *plr);
void			calc_intersection(t_point *pgon, t_ray *ray,
	t_intersection *sect);
void			calc_wall_texels(t_frame *frame, t_texture *tex);
int				check_connection(t_point *point, t_frame *frame);
int				check_if_lseg_intersects(t_point *p0, t_xy *pos, t_xy *dir);
int				check_if_portal(t_point *point);
int				check_if_same_pt(int *current_pxl, t_ray_pt *fov);
void			continue_from_last_sector(t_point *start, t_ray_pt *fov,
	t_frame *frame);
void			draw_frame(t_home *home, t_frame *frame, t_player *plr);
void			draw_segment(t_frame *frame, t_home *home, t_player *plr,
	int wall);
void			draw_wall(t_frame *frame, t_texture *tex, t_home *home,
	t_player *plr);
t_texture		*get_tex(int idx, t_texture **textures);
void			get_wall_pts(t_frame *frame, int walls, int current_pxl);
t_xy			line_intersection(t_intersection *sect);
int				orientation_of_three_points(t_xy a, t_xy b, t_xy c);
int				point_is_on_the_lseg(t_xy a, t_xy c, t_xy b);
void			scan_fov(t_home *home, t_frame *frame, t_player *plr,
	int current_pxl);
void			setup_frame(t_frame *frame, t_frame *new_frame, int current_pxl,
	int idx);
void			step_one(t_xyz *start, t_xyz *bottom, size_t *obj_x,
	t_frame *frame);

#endif
