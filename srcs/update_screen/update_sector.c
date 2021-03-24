/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:11:24 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 17:39:41 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int				update_sector(t_home *home)
{
	// open_map_file(home, "map_files/map_error_noheader.TEST");
	open_map_file(home, "map_files/map.TEST");
	// assign_sectors(home);
	//print_points(home->sectors[0]);
	return (0);
}
