/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:08:38 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 15:17:35 by jnivala          ###   ########.fr       */
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
