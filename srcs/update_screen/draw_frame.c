/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:47:19 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 21:05:14 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xy			center_to_screen(t_xy loc)
{
	loc.x += 0.5 * SCREEN_WIDTH;
	loc.y += 0.5 * SCREEN_HEIGHT;
	return (loc);
}

static char		*compass_direction(t_xy *dir)
{
	if (dir->x <= NW && dir->x > 0)
		return (ft_strdup("North"));
	else if (dir->x <= N && dir->x > NE)
		return (ft_strdup("North"));
	else if (dir->x <= SW && dir->x > NW)
		return (ft_strdup("West"));
	else if (dir->x <= SE && dir->x > SW)
		return (ft_strdup("South"));
	else if (dir->x <= NE && dir->x > SE)
		return (ft_strdup("East"));
	else
		return (ft_strdup("NO DIR"));
}

void			draw_minimap(t_home *home, t_frame *frame)
{
	unsigned int	i;
	unsigned int	j;
	t_point			*temp;

	i = 0;
	while (i < home->nbr_of_sectors)
	{
		j = 0;
		temp = home->sectors[i]->points;
		while (j < home->sectors[i]->nbr_of_walls)
		{
			draw_line(center_to_screen(temp->x0),
				center_to_screen(temp->next->x0),
				greenyellow, frame->draw_surf);
			temp = temp->next;
			j++;
		}
		i++;
	}
}

void			draw_2d_fov(t_frame *frame, t_player *plr)
{
	char	*sector;
	char	*compass;

	compass = compass_direction(&plr->dir);
	sector = ft_itoa(plr->current_sector);
	str_pxl(frame, (t_xy){0, 50}, "dir: ");
	str_pxl(frame, (t_xy){50, 50}, compass);
	str_pxl(frame, (t_xy){0, 70}, "sector:");
	str_pxl(frame, (t_xy){0, 90}, sector);
	str_pxl(frame, (t_xy){0, 400}, "Press z to switch to wireframe");
	draw_rect(center_to_screen((t_xy){0.0f, 0.0f}),
		(t_xy){3.0f, 3.0f}, frame, yellow);
	draw_line(center_to_screen((t_xy){0.0f, 0.0f}),
		center_to_screen(vec2_add((t_xy){0.0f, 0.0f},
		vec2_mul((t_xy){1.0f, 0.0f}, 400))), lightgreen, frame->draw_surf);
	draw_line(center_to_screen((t_xy){0.0f, 0.0f}),
		center_to_screen(vec2_add((t_xy){0.0f, 0.0f},
		vec2_mul((t_xy){0.0f, 1.0f}, 400))), lightgreen, frame->draw_surf);
	free(sector);
	free(compass);
}

void			draw_frame(t_home *home, t_frame *frame, t_player *plr)
{
	frame->idx = plr->current_sector;
	frame->old_idx = -1;
	frame->max_fov = 0;
	frame->offset = 640;
	frame->left.l_pt = vec2(-1, -1);
	frame->right.r_pt = vec2(-1, -1);
	frame->plr_offset = vec2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	frame->pxl_offset = 0.0f;
	scan_fov(home, frame, plr, 0);
	draw_2d_fov(frame, plr);
	draw_minimap(home, frame);
}
