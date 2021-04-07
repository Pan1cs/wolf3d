/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:26 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/07 12:08:33 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static int		check_if_corner(t_sector *sector, t_xy *pos)
{
	unsigned int	i;
	t_point			*temp;

	i = 0;
	temp = sector->points;
	while (i < sector->nbr_of_walls)
	{
		if (get_distance(temp->x0, *pos) < 8)
			return (temp->idx);
		temp = temp->next;
		i++;
	}
	return (open_space);
}

static int		check_if_crosses_wall(t_sector *sector, t_xy *dir, t_xy *pos)
{
	unsigned int	i;
	t_point			*temp;

	i = 0;
	temp = sector->points;
	while (i < sector->nbr_of_walls)
	{
		if (check_if_lseg_intersects(temp, pos, dir))
			return (temp->idx);
		temp = temp->next;
		i++;
	}
	return (open_space);
}

static int		check_if_inside(t_sector *sector, t_xy *pos)
{
	unsigned int	i;
	t_xy			dir;
	t_point			*temp;
	int				walls_crossed;

	i = 0;
	walls_crossed = 0;
	temp = sector->points;
	dir = (t_xy){-200000.0f, 0.0f};
	while (i < sector->nbr_of_walls)
	{
		walls_crossed += check_if_lseg_intersects(temp, pos, &dir);
		temp = temp->next;
		i++;
	}
	return (walls_crossed % 2);
}

int				player_move(t_player *plr, t_home *home, t_xy *dir)
{
	int			crossing;
	t_xy		pos;

	pos = (t_xy){0.0f, 0.0f};
	crossing = check_if_crosses_wall(home->sectors[plr->current_sector], dir, &pos);
	if (crossing >= 0)
	{
		if (check_if_corner(home->sectors[crossing], &pos) != open_space)
			return (0);
		translate_world_view(home, *dir);
		plr->current_sector = crossing;
	}
	else if (crossing == open_space)
	{
		pos = vec2_mul(*dir, 80);
		crossing = check_if_crosses_wall(home->sectors[plr->current_sector], dir, &pos);
		if (crossing < 0 && crossing != open_space)
			return (0);
		if (check_if_corner(home->sectors[plr->current_sector], &pos) != open_space)
			return (0);
		if (check_if_inside(home->sectors[plr->current_sector], &(t_xy){0.0f, 0.0f}))
			translate_world_view(home, *dir);
	}
	return (1);
}
