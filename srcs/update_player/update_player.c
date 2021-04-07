/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:36 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/07 11:43:06 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		check_player_dir(t_player *plr, t_xy *dir)
{
	if (plr->input.up == 1)
	{
		if (plr->input.left == 1)
			*dir = vec2_rot(*dir, -45 * DEG_TO_RAD);
		else if (plr->input.right == 1)
			*dir = vec2_rot(*dir, 45 * DEG_TO_RAD);
	}
	if (plr->input.down == 1)
	{
		if (plr->input.left == 1)
			*dir = vec2_rot(*dir, -135 * DEG_TO_RAD);
		else if (plr->input.right == 1)
			*dir = vec2_rot(*dir, 135 * DEG_TO_RAD);
		else
			*dir = vec2_rot(*dir, 180 * DEG_TO_RAD);
	}
	if (plr->input.left == 1)
		*dir = vec2_rot(*dir, -90 * DEG_TO_RAD);
	if (plr->input.right == 1)
		*dir = vec2_rot(*dir, 90 * DEG_TO_RAD);
}

static void		movement(t_player *plr, t_home *home)
{
	Uint32		current_time;
	Uint32		delta_time;
	t_xy		plr_dir;

	current_time = SDL_GetTicks();
	delta_time = current_time - plr->time;
	if (delta_time < 1)
		return ;
	plr->time = current_time;

	if (plr->input.up == 1 || plr->input.down == 1
		|| plr->input.left == 1 || plr->input.right == 1)
	{
		plr_dir = (t_xy){PLR_DIR, PLR_DIR};
		check_player_dir(plr, &plr_dir);
		plr_dir = vec2_mul(plr_dir, delta_time * 0.05);
		if (player_move(plr, home, &plr_dir))
			play_footsteps(plr);
	}
}

void			update_player(t_player *plr, t_home *home, SDL_Event *e)
{
	while (SDL_PollEvent(e) != 0)
	{
		key_input(plr, e);
		mouse_handle(plr, home, e);
	}
	movement(plr, home);
}
