/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:26 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/30 14:43:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

// int				check_if_inside(t_sector *sector, t_player *plr,
// 	t_home *home, float delta_time)
// {
// 	unsigned int	i;
// 	t_ray			ray;
// 	t_point			*temp;
// 	t_intersection	isect;
// 	int				walls_crossed;

// 	temp = sector->points;
// 	ray.pos = (t_xy){0.0f, 0.0f};
// 	ray.dir = (t_xy){-1.0f, 0.0f};
// 	translate_world_view(home, vec2_mul(plr->dir, 40 * delta_time));
// 	plr->pos = vec2_add(plr->pos, vec2_mul(plr->move_dir, 40 * delta_time));
// 	while (i < sector->nbr_of_walls)
// 	{
// 		calc_intersection(temp, &ray, &isect);
// 		walls_crossed += line_intersection_bool(&isect);
// 		temp = temp->next;
// 		i++;
// 	}
// 	if (walls_crossed % 2 == 0)
// 		return (0);
// 	else
// 		return (1);
// }

// int				check_collision(t_sector *sector, t_player *plr, t_home *home)
// {
// 	t_ray			ray;
// 	t_intersection	isect;
// 	t_xy			point;
// 	t_point			*p0;
// 	unsigned int	i;

// 	i = 0;
// 	p0 = &sector->points[0];
// 	ray.pos = plr->pos;
// 	ray.dir = plr->move_dir;
// 	while (i < sector->nbr_of_walls)
// 	{
// 		calc_intersection_raw(p0, &ray, &isect);
// 		point = line_intersection_raw(&isect);
// 		if (point.x >= 0 || point.y >= 0)
// 		{
// 			if (get_distance(vec2(0, 0), point) < 2 && (p0->idx >= 0))
// 			{
// 				plr->current_sector = p0->idx;
// 				plr->pos = vec2_add(plr->pos, vec2_mul(plr->move_dir, 2));
// 				translate_world_view(home, vec2_mul(plr->move_dir, 2));
// 				return (0);
// 			}
// 			else if (get_distance(vec2(0, 0), point) < 5 && (p0->idx < 0))
// 				return ((int)(vec2_ang(p0->x0, p0->next->x0) * RAD_TO_DEG));
// 		}
// 		p0 = p0->next;
// 		i++;
// 	}
// 	return (0);
// }

// static t_xy		check_player_dir(t_player *plr)
// {
// 	float		def;

// 	def = 0.785398163;
// 	if (plr->input.up == 1)
// 	{
// 		if (plr->input.left == 1)
// 			return (vec2_rot(vec2(def, def), -45 * DEG_TO_RAD));
// 		else if (plr->input.right == 1)
// 			return (vec2_rot(vec2(def, def), 45 * DEG_TO_RAD));
// 		else
// 			return (vec2(def, def));
// 	}
// 	if (plr->input.down == 1)
// 	{
// 		if (plr->input.left == 1)
// 			return (vec2_rot(vec2(def, def), -135 * DEG_TO_RAD));
// 		else if (plr->input.right == 1)
// 			return (vec2_rot(vec2(def, def), 135 * DEG_TO_RAD));
// 		else
// 			return (vec2_rot(vec2(def, def), 180 * DEG_TO_RAD));
// 	}
// 	if (plr->input.left == 1)
// 		return (vec2_rot(vec2(def, def), -90 * DEG_TO_RAD));
// 	if (plr->input.right == 1)
// 		return (vec2_rot(vec2(def, def), 90 * DEG_TO_RAD));
// 	return vec2(-1, -1);
// }

// static t_xy		check_player_dir_dur(t_player *plr)
// {
// 	if (plr->input.up == 1)
// 	{
// 		if (plr->input.left == 1)
// 			return (vec2_rot(plr->move_dir, -45 * DEG_TO_RAD));
// 		else if (plr->input.right == 1)
// 			return (vec2_rot(plr->move_dir, 45 * DEG_TO_RAD));
// 		else
// 			return (plr->move_dir);
// 	}
// 	if (plr->input.down == 1)
// 	{
// 		if (plr->input.left == 1)
// 			return (vec2_rot(plr->move_dir, -135 * DEG_TO_RAD));
// 		else if (plr->input.right == 1)
// 			return (vec2_rot(plr->move_dir, 135 * DEG_TO_RAD));
// 		else
// 			return (vec2_rot(plr->move_dir, 180 * DEG_TO_RAD));
// 	}
// 	if (plr->input.left == 1)
// 		return (vec2_rot(plr->move_dir, -90 * DEG_TO_RAD));
// 	if (plr->input.right == 1)
// 		return (vec2_rot(plr->move_dir, 90 * DEG_TO_RAD));
// 	return vec2(-1, -1);
// }

// void			player_move(t_player *plr, t_home *home, float delta_time)
// {
// 	int		collision;
// 	t_xy	col_dir;

// 	col_dir = vec2(1, 1);
// 	col_dir = vec2_rot(col_dir, collision * DEG_TO_RAD);
// 	plr->dir = check_player_dir(plr);
// 	plr->move_dir = check_player_dir_dur(plr);
// 	//collision = check_if_inside(home->sectors[plr->current_sector], plr, home, delta_time);
// 	collision = check_collision(home->sectors[plr->current_sector], plr, home);
// 	play_footsteps(plr);
// 	if (!collision)
// 	{
// 		translate_world_view(home, vec2_mul(plr->dir, 40 * delta_time));
// 		plr->pos = vec2_add(plr->pos, vec2_mul(plr->move_dir, 40 * delta_time));
// 	}
// 	else
// 	{
// 		ft_putstr("collision dir x: ");
// 		ft_putstr(ft_ftoa(collision, 1));
// 		ft_putchar('\n');
// 		ft_putstr("col dir y: ");
// 		ft_putstr(ft_ftoa(collision, 1));
// 		ft_putchar('\n');
// 	}
// }

// void			movement(t_player *plr, t_home *home)
// {
// 	float		delta_time;
// 	clock_t		ctime;

// 	ctime = clock();
// 	delta_time = ((ctime - plr->time) / (float)CLOCKS_PER_SEC);
// 	if (delta_time < 0.0166667)
// 		return;
// 	plr->time = ctime;
// 	if (plr->input.up == 1 || plr->input.down == 1
// 		|| plr->input.left == 1 || plr->input.right == 1)
// 		player_move(plr, home, delta_time);
// }

int				check_collision(t_sector *sector, t_player *plr, t_home *home)
{
	t_ray			ray;
	t_intersection	isect;
	t_xy			point;
	t_point			*p0;
	unsigned int	i;

	i = 0;
	p0 = &sector->points[0];
	ray.pos = plr->pos;
	ray.dir = plr->move_dir;
	while (i < sector->nbr_of_walls)
	{
		calc_intersection_raw(p0, &ray, &isect);
		point = line_intersection_raw(&isect);
		if (point.x >= 0 || point.y >= 0)
		{
			if (get_distance(vec2(0, 0), point) < 2 && (p0->idx >= 0))
			{
				plr->current_sector = p0->idx;
				// plr->pos = vec2_add(plr->pos, vec2_mul(plr->move_dir, 2));
				translate_world_view(home, vec2_mul(plr->move_dir, 2));
				return (0);
			}
			else if (get_distance(vec2(0, 0), point) < 5 && (p0->idx < 0))
				return ((int)(vec2_ang(p0->x0, p0->next->x0) * RAD_TO_DEG));
		}
		p0 = p0->next;
		i++;
	}
	return (0);
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
	int		collision;
	t_xy	col_dir;

	collision = check_collision(home->sectors[plr->current_sector], plr, home);
	col_dir = vec2(1, 1);
	col_dir = vec2_rot(col_dir, collision * DEG_TO_RAD);
	plr->move_dir = check_player_dir(plr);
	play_footsteps(plr);
	if (!collision)
	{
		// plr->pos = vec2_add(plr->pos, vec2_mul(plr->move_dir, 40 * delta_time));
		translate_world_view(home, vec2_mul(plr->move_dir, 40 * delta_time));
	}
	else
	{
		ft_putstr("col dir x: , col dir y: ");
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
