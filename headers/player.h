/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:00 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/26 11:58:29 by jnivala          ###   ########.fr       */
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
	int				z;
	int				x;
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
	clock_t			time;
	t_audio			audio;
	float			angle;
	int				current_sector;
}					t_player;

#endif
