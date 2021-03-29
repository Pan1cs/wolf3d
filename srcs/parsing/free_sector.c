/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:05:23 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 14:43:31 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	free_points(t_point **head, unsigned int nbr_of_walls)
{
	t_point *item;

	while (nbr_of_walls--)
	{
		item = *head;
		*head = item->next;
		free(item);
		item = NULL;
	}
}

void	free_sectors(t_home *home)
{
	unsigned int	i;

	i = 0;
	if (home == NULL)
		return ;
	while (i < home->nbr_of_sectors)
	{
		free_points(&home->sectors[i]->points, home->sectors[i]->nbr_of_walls);
		free_points(&home->sectors[i]->orig_points,
			home->sectors[i]->nbr_of_walls);
		free(home->sectors[i]);
		home->sectors[i] = NULL;
		i++;
	}
	free(home->sectors);
	home->sectors = NULL;
}
