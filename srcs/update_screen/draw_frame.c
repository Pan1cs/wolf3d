/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:47:19 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/31 13:55:45 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xy			center_to_screen(t_xy loc)
{
	loc.x += 0.5 * SCREEN_WIDTH;
	loc.y += 0.5 * SCREEN_HEIGHT;
	return (loc);
}

/*
** 			if (i == 0)
**			{
**				str = ft_itoa((int)j);
**				str_pxl(frame, center_to_screen(temp->x0), str);
**				free(str);
**				str = ft_ftoa(temp->wall_facing, 7);
**				str_pxl(frame, center_to_screen(temp->normal), str);
**				free(str);
**			}
**			draw_line(center_to_screen(vec2_halfway(temp->x0, temp->next->x0)),
**			center_to_screen(temp->normal), red, frame->draw_surf);
**
*/

void			draw_minimap(t_home *home, t_frame *frame)
{
	unsigned int	i;
	unsigned int	j;
	t_point			*temp;
	t_xy			fov_left;
	t_xy			fov_right;

	i = 0;
	fov_right = vec2(0.0f, 1.0f);
	fov_left = vec2(1.0f, 0.0f);
	while (i < home->nbr_of_sectors)
	{
		j = 0;
		temp = home->sectors[i]->points;
		while (j < home->sectors[i]->nbr_of_walls)
		{
			draw_rect(center_to_screen((t_xy){0.0f, 0.0f}),
				(t_xy){3.0f, 3.0f}, frame, yellow);
			draw_line(center_to_screen(temp->x0),
				center_to_screen(temp->next->x0), greenyellow, frame->draw_surf);
			draw_line(center_to_screen((t_xy){0.0f, 0.0f}),
				center_to_screen(vec2_add((t_xy){0.0f, 0.0f},
	 			vec2_mul(fov_left, 400))), lightgreen, frame->draw_surf);
			draw_line(center_to_screen((t_xy){0.0f, 0.0f}),
				center_to_screen(vec2_add((t_xy){0.0f, 0.0f},
	 			vec2_mul(fov_right, 400))), lightgreen, frame->draw_surf);
			temp = temp->next;
			j++;
		}
		i++;
	}
}

void			draw_2d_fov(t_frame *frame, t_player *plr)
{
	char	*dir_x;
	char	*pos_x;
	char	*pos_y;
	char	*sector;

	dir_x = ft_ftoa(plr->dir.x, 7);
	pos_x = ft_ftoa(plr->pos.x, 5);
	pos_y = ft_ftoa(plr->pos.y, 5);
	sector = ft_itoa(plr->current_sector);
	str_pxl(frame, (t_xy){0, 10}, "x: ");
	str_pxl(frame, (t_xy){50, 10}, pos_x);
	str_pxl(frame, (t_xy){0, 30}, "y: ");
	str_pxl(frame, (t_xy){50, 30}, pos_y);
	str_pxl(frame, (t_xy){0, 50}, "dir: ");
	str_pxl(frame, (t_xy){50, 50}, dir_x);
	str_pxl(frame, (t_xy){0, 70}, "sector:");
	str_pxl(frame, (t_xy){0, 90}, sector);
	free(dir_x);
	free(pos_x);
	free(pos_y);
	free(sector);
}

void			draw_frame(t_home *home, t_frame *frame, t_player *plr)
{
	frame->idx = plr->current_sector;
	frame->old_idx = -1;
	frame->max_fov = 0;
	frame->offset = 640;
	frame->left.l_pt = vec2(-1,-1);
	frame->right.r_pt = vec2(-1,-1);
	frame->plr_offset = vec2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	frame->pxl_offset = 0.0f;
	scan_fov(home, frame, plr, 0);
	draw_2d_fov(frame, plr);
	draw_minimap(home, frame);
}
