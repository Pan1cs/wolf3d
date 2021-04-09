/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sectors_data_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:09:10 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 19:23:27 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"
int			check_if_lines_cut(t_sector *sector)
{
	unsigned int	i;
	t_point			*temp;

	i = 0;
	temp = sector->points;
	if (sector->nbr_of_walls < 4)
		return (0);
	while (i < sector->nbr_of_walls)
	{
		if (check_if_lseg_intersects(temp,
			&temp->next->next->x0, &temp->next->next->next->x0))
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}
