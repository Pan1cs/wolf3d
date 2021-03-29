/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_norm_vectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:13:37 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 15:43:59 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		calc_normal_vectors(t_home *home)
{
	unsigned int	i;
	unsigned int	j;
	t_point			*temp;
	float			inv_pi;

	i = 0;
	inv_pi = 1 / (2 * PI);
	while (i < home->nbr_of_sectors)
	{
		j = 0;
		temp = home->sectors[i]->points;
		while (j < home->sectors[i]->nbr_of_walls)
		{
			temp->normal = vec2_normal(temp->x0, temp->next->x0);
			if (temp->normal.x < 0)
				temp->wall_facing = vec2_ang(temp->normal, (t_xy){0, 1}) + PI;
			else
				temp->wall_facing = vec2_ang(temp->normal, (t_xy){0, 1});
			if (temp->wall_facing == 0.0f)
				temp->wall_facing = 2 * PI;
			temp->wall_facing = inv_pi * temp->wall_facing;
			temp = temp->next;
			j++;
		}
		i++;
	}
}
