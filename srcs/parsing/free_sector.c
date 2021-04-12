/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:05:23 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/12 10:57:52 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		free_points(t_point **head, unsigned int nbr_of_walls)
{
	t_point *item;

	while (nbr_of_walls--)
	{
		item = *head;
		*head = item->next;
		free(item);
		item = NULL;
	}
	return (1);
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
		free(home->sectors[i]);
		home->sectors[i] = NULL;
		i++;
	}
	free(home->sectors);
	home->sectors = NULL;
}

void	free_sectors_n(t_home *home, size_t n)
{
	size_t	i;

	i = 0;
	if (home == NULL)
		return ;
	while (i < n)
	{
		free(home->sectors[i]);
		home->sectors[i] = NULL;
		i++;
	}
	free(home->sectors);
	home->sectors = NULL;
}
