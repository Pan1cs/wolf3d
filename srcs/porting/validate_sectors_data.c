/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sectors_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:06:59 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 15:35:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void	map_error_output(int i, t_home *home)
{
	if (i == 1)
		ft_putendl_fd("ERROR: Player not within the map.", 2);
	else if (i == 2)
	free_sectors(home);
	exit(0);
}

int			validate_sectors_data(t_home *home)
{
	int		i;

	i = 0;
	if (!(plr_inside(home->sectors[i], &(t_xy){0.0f, 0.0f})))
		map_error_output(1, home);

	return (0);
}
