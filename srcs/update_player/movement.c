/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:26 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/03 20:40:07 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int				check_if_crosses_wall(t_sector *sector, t_player *plr)
{
	unsigned int	i;
	t_point			*temp;

	i = 0;
	temp = sector->points;
	while (i < sector->nbr_of_walls)
	{
		if (check_if_lseg_intersects(temp, (t_xy){0.0f, 0.0f}, plr->move_dir))
			return (temp->idx);
		temp = temp->next;
		i++;
	}
	return (-999);
}

int				check_if_inside(t_sector *sector, t_player *plr)
{
	unsigned int	i;
	t_ray			ray;
	t_point			*temp;
	t_intersection	isect;
	int				walls_crossed;

	i = 0;
	walls_crossed = 0;
	temp = sector->points;
	ray.pos = (t_xy){0.0f, 0.0f};
	ray.dir = plr->move_dir;
	while (i < sector->nbr_of_walls)
	{
		calc_intersection(temp, &ray, &isect);
		walls_crossed += line_intersection_bool(&isect);
		temp = temp->next;
		i++;
	}
	return (walls_crossed % 2);
}

static t_xy		check_player_dir(t_player *plr)
{
	if (plr->input.up == 1)
	{
		if (plr->input.left == 1)
			return (vec2_rot(plr->move_dir, -45 * DEG_TO_RAD));
		else if (plr->input.right == 1)
			return (vec2_rot(plr->move_dir, 45 * DEG_TO_RAD));
		else
			return (plr->move_dir);
	}
	if (plr->input.down == 1)
	{
		if (plr->input.left == 1)
			return (vec2_rot(plr->move_dir, -135 * DEG_TO_RAD));
		else if (plr->input.right == 1)
			return (vec2_rot(plr->move_dir, 135 * DEG_TO_RAD));
		else
			return (vec2_rot(plr->move_dir, 180 * DEG_TO_RAD));
	}
	if (plr->input.left == 1)
		return (vec2_rot(plr->move_dir, -90 * DEG_TO_RAD));
	if (plr->input.right == 1)
		return (vec2_rot(plr->move_dir, 90 * DEG_TO_RAD));
	return (vec2(-1, -1));
}

void			player_move(t_player *plr, t_home *home, float delta_time)
{
	int				crossing;

	plr->move_dir = vec2(0.785398163f, 0.785398163f);
	plr->move_dir = check_player_dir(plr);
	plr->move_dir = vec2_mul(plr->move_dir, delta_time * 0.05);
	crossing = check_if_crosses_wall(home->sectors[plr->current_sector], plr);
	play_footsteps(plr);
	if (crossing >= 0)
	{
		translate_world_view(home, plr->move_dir);
		plr->current_sector = crossing;
	}
	else
	{
		if (crossing == -999)
			translate_world_view(home, plr->move_dir);
	}
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
		player_move(plr, home, delta_time);
}
