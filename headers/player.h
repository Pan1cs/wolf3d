/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:00 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/12 14:49:41 by jnivala          ###   ########.fr       */
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
	int				mouse;
}					t_input;

typedef struct		s_player
{
	t_xy			pos;
	t_xy			dir;
	float			pitch;
	t_input			input;
	Uint32			time;
	t_audio			audio;
	int				current_sector;
}					t_player;


enum				e_movement {
	open_space = -9999
};

#endif
