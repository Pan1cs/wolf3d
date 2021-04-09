/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sectors_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:06:59 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 16:38:43 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void	map_error_output(int i, t_home *home)
{
	if (i == 1)
		ft_putendl_fd("ERROR: Player not within the map.", 2);
	else if (i == 2)
		ft_putendl_fd("ERROR: Same points.", 2);
	else if (i == 3)
		ft_putendl_fd("ERROR: Portal not connected.", 2);
	free_sectors(home);
	exit(0);
}

static int	check_if_sector_has_same_points(t_sector *sector)
{
	unsigned int	i;
	unsigned int	j;
	t_xy			coord;
	t_point			*temp;
	t_point			*test;

	i = 0;
	temp = sector->points;
	while (i < sector->nbr_of_walls)
	{
		coord = temp->x0;
		j = 0;
		test = sector->points;
		while (j < sector->nbr_of_walls)
		{
			if (test->x0.x == coord.x && test->x0.y == coord.y
				&& i != j)
				return (1);
			test = test->next;
			j++;
		}
		temp = temp->next;
		i++;
	}
	return (0);
}

static int	check_valid_connection(t_xy *p0, t_xy *p1, t_sector *sector, int i)
{
	unsigned int	j;
	t_point			*temp;
	t_point			*fast_temp;

	j = 0;
	temp = sector->points;
	fast_temp = sector->points->next;
	while (j < sector->nbr_of_walls)
	{
		if (temp->x0.x == p0->x
			&& temp->x0.y == p0->y
			&& fast_temp->x0.x == p1->x
			&& fast_temp->x0.y == p1->y
			&& temp->idx == i)
				return (1);
		j++;
		temp = temp->next;
		fast_temp = temp->next;
	}
	return (0);
}

static int	check_if_portals_connected(unsigned int i, t_home *home)
{
	unsigned int	j;
	t_point			*temp;

	j = 0;
	temp = home->sectors[i]->points;
	while (j < home->sectors[i]->nbr_of_walls && temp->idx < 0)
	{
		if (temp->idx >= 0)
			if (!(check_valid_connection(&temp->next->x0, &temp->x0,
				home->sectors[temp->idx], (int)i)))
				return (1);
		temp = temp->next;
		j++;
	}
	return (0);
}


int			validate_sectors_data(t_home *home)
{
	unsigned int	i;

	i = 0;
	if (!(plr_inside(home->sectors[i], &(t_xy){0.0f, 0.0f})))
		map_error_output(1, home);
	while (i < home->nbr_of_sectors)
	{
		if (check_if_sector_has_same_points(home->sectors[i]))
			map_error_output(2, home);
		if (check_if_portals_connected(i, home))
			map_error_output(3, home);
		i++;
	}
	return (0);
}
