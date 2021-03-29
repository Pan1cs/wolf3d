/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:08:38 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 15:34:26 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECTOR_H
# define SECTOR_H

typedef struct		s_point
{
	t_xy			x0;
	t_xy			normal;
	float			wall_facing;
	int				idx;
	struct s_point	*next;
}					t_point;

typedef struct		s_sector
{
	t_point			*points;
	t_point			*orig_points;
	unsigned int	nbr_of_walls;
	int				idx_sector;
	int				tex_floor;
	int				tex_ceil;
	float			ceiling;
	float			ground;
	t_xyz			floor_top_left;
	t_xyz			floor_top_right;
	t_xyz			floor_bottom_left;
	t_xyz			floor_bottom_right;
}					t_sector;

#endif
