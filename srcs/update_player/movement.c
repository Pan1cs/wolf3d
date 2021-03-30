/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:26 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/30 15:27:28 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int				check_if_inside(t_sector *sector, t_player *plr,
	t_home *home, float delta_time)
{
	unsigned int	i;
	t_ray			ray;
	t_point			*temp;
	t_intersection	isect;
	int				walls_crossed;

	temp = sector->points;
	ray.pos = (t_xy){0.0f, 0.0f};
	ray.dir = (t_xy){-1.0f, 0.0f};
	translate_world_view(home, vec2_mul(plr->move_dir, 40 * delta_time));
	while (i < sector->nbr_of_walls)
	{
		calc_intersection(temp, &ray, &isect);
		walls_crossed += line_intersection_bool(&isect);
		temp = temp->next;
		i++;
	}
	if (walls_crossed % 2 == 0)
	{
		plr->move_dir.x = -plr->move_dir.x;
		plr->move_dir.y = -plr->move_dir.y;
		translate_world_view(home, vec2_mul(plr->move_dir, 40 * delta_time));
		return (0);
	}
	else
		return (1);
}

static t_xy		check_player_dir(t_player *plr)
{
	float		def;

	def = 0.785398163;
	if (plr->input.up == 1)
	{
		if (plr->input.left == 1)
			return (vec2_rot(vec2(def, def), -45 * DEG_TO_RAD));
		else if (plr->input.right == 1)
			return (vec2_rot(vec2(def, def), 45 * DEG_TO_RAD));
		else
			return (vec2(def, def));
	}
	if (plr->input.down == 1)
	{
		if (plr->input.left == 1)
			return (vec2_rot(vec2(def, def), -135 * DEG_TO_RAD));
		else if (plr->input.right == 1)
			return (vec2_rot(vec2(def, def), 135 * DEG_TO_RAD));
		else
			return (vec2_rot(vec2(def, def), 180 * DEG_TO_RAD));
	}
	if (plr->input.left == 1)
		return (vec2_rot(vec2(def, def), -90 * DEG_TO_RAD));
	if (plr->input.right == 1)
		return (vec2_rot(vec2(def, def), 90 * DEG_TO_RAD));
	return vec2(-1, -1);
}

void			player_move(t_player *plr, t_home *home, float delta_time)
{
	int		inside;

	plr->move_dir = check_player_dir(plr);
	inside = check_if_inside(home->sectors[plr->current_sector], plr, home, delta_time);
	play_footsteps(plr);
	if (!inside)
	{
		translate_world_view(home, vec2_mul(plr->move_dir, 40 * delta_time));
		ft_putstr("collision dir x: ");
		ft_putstr(ft_ftoa(inside, 1));
		ft_putchar('\n');
		ft_putstr("col dir y: ");
		ft_putstr(ft_ftoa(inside, 1));
		ft_putchar('\n');
	}
}

void			movement(t_player *plr, t_home *home)
{
	float		delta_time;
	clock_t		ctime;

	ctime = clock();
	delta_time = ((ctime - plr->time) / (float)CLOCKS_PER_SEC);
	if (delta_time < 0.0166667)
		return;
	plr->time = ctime;
	if (plr->input.up == 1 || plr->input.down == 1
		|| plr->input.left == 1 || plr->input.right == 1)
		player_move(plr, home, delta_time);
}
