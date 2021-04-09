/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:00 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 11:40:26 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct		s_input
{
	int				right;
	int				left;
	int				up;
	int				down;
	int				rot_right;
	int				rot_left;
	int				wireframe;
	int				minimap;
	int				info;
	int				quit;
}					t_input;

typedef struct		s_player
{
	t_xy			pos;
	t_xy			dir;
	t_xy			move_dir;
	float			pitch;
	float			z;
	float			height;
	t_input			input;
	Uint32			time;
	t_audio			audio;
	float			angle;
	int				current_sector;
}					t_player;

#endif
