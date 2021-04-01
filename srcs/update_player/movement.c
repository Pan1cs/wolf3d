/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:26 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/01 11:38:42 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

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
	if (walls_crossed % 2)
		return (1);
	else
		return (0);
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
	unsigned int	i;
	int				inside;

	i = 0;
	plr->move_dir = vec2(0.785398163f, 0.785398163f);
	plr->move_dir = check_player_dir(plr);
	translate_world_view(home, vec2_mul(plr->move_dir, delta_time * 0.15));
	inside = check_if_inside(home->sectors[plr->current_sector], plr);
	play_footsteps(plr);
	if (!inside)
	{
		while (i < home->nbr_of_sectors
			&& !(check_if_inside(home->sectors[i], plr)))
			i++;
		if (i >= home->nbr_of_sectors)
			translate_world_view(home,
				vec2_mul(vec2_reverse(plr->move_dir), delta_time * 0.15));
		else
			plr->current_sector = i;
	}
	else
		translate_world_view(home,
			vec2_mul(vec2_reverse(plr->move_dir), delta_time * 0.1));
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
