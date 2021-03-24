/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:36:50 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 14:38:13 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	update_screen(t_home *home, t_frame *frame, t_player *plr)
{
	//draw_fov(home, plr);
	//draw_minimap(home->map.size, plr->pos, plr->dir, home);
	draw_2d(home, frame, plr);
}
