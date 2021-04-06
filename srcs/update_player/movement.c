/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:26 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/06 16:54:28 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int				check_if_crosses_wall(t_sector *sector, t_xy *dir, t_xy *pos)
{
	unsigned int	i;
	t_point			*temp;

	i = 0;
	temp = sector->points;
	while (i < sector->nbr_of_walls)
	{
		if (check_if_lseg_intersects(temp, *pos, *dir))
			return (temp->idx);
		temp = temp->next;
		i++;
	}
	return (open_space);
}

int				check_if_inside(t_sector *sector, t_xy *pos)
{
	unsigned int	i;
	t_xy			dir;
	t_point			*temp;
	int				walls_crossed;

	i = 0;
	walls_crossed = 0;
	temp = sector->points;
	dir = (t_xy){-400.0f, 0.0f};
	while (i < sector->nbr_of_walls)
	{
		walls_crossed += check_if_lseg_intersects(temp, *pos, dir);
		temp = temp->next;
		i++;
	}
	return (walls_crossed % 2);
}

static t_xy		check_player_dir(t_player *plr, t_xy *dir)
{
	if (plr->input.up == 1)
	{
		if (plr->input.left == 1)
			return (vec2_rot(*dir, -45 * DEG_TO_RAD));
		else if (plr->input.right == 1)
			return (vec2_rot(*dir, 45 * DEG_TO_RAD));
		else
			return (*dir);
	}
	if (plr->input.down == 1)
	{
		if (plr->input.left == 1)
			return (vec2_rot(*dir, -135 * DEG_TO_RAD));
		else if (plr->input.right == 1)
			return (vec2_rot(*dir, 135 * DEG_TO_RAD));
		else
			return (vec2_rot(*dir, 180 * DEG_TO_RAD));
	}
	if (plr->input.left == 1)
		return (vec2_rot(*dir, -90 * DEG_TO_RAD));
	if (plr->input.right == 1)
		return (vec2_rot(*dir, 90 * DEG_TO_RAD));
	return (vec2(-1, -1));
}

static int			player_move(t_player *plr, t_home *home, float delta_time)
{
	int				crossing;
	t_xy			pos;

	pos = (t_xy){0.0f, 0.0f};
	plr->move_dir = (t_xy){PLR_DIR, PLR_DIR};
	plr->move_dir = check_player_dir(plr, &plr->move_dir);
	plr->move_dir = vec2_mul(plr->move_dir, delta_time * 0.05);
	crossing = check_if_crosses_wall(home->sectors[plr->current_sector], &plr->move_dir, &pos);
	if (crossing != open_space && crossing >= 0 )
	{
		translate_world_view(home, plr->move_dir);
		if (check_if_inside(home->sectors[crossing], &pos))
			plr->current_sector = crossing;
		pos = vec2_mul(plr->move_dir, 100);
		crossing = check_if_crosses_wall(home->sectors[plr->current_sector], &plr->move_dir, &pos);
		if (crossing < 0 && crossing != open_space)
			translate_world_view(home, vec2_reverse(plr->move_dir));
	}
	else if (crossing == open_space)
	{
		pos = vec2_mul(plr->move_dir, 100);
		crossing = check_if_crosses_wall(home->sectors[plr->current_sector], &plr->move_dir, &pos);
		if (crossing < 0 && crossing != open_space)
			return (0);
		if (check_if_inside(home->sectors[plr->current_sector], &(t_xy){0.0f, 0.0f}))
			translate_world_view(home, plr->move_dir);
	}
	return (1);
}

void			movement(t_player *plr, t_home *home)
{
	Uint32			current_time;
	Uint32			delta_time;

	current_time = SDL_GetTicks();
	delta_time = current_time - plr->time;
	if (delta_time < 1)
		return ;
	plr->time = current_time;
	if (plr->input.up == 1 || plr->input.down == 1
		|| plr->input.left == 1 || plr->input.right == 1)
	{
		if (player_move(plr, home, delta_time))
			play_footsteps(plr);
	}
}
