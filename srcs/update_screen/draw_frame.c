/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:59:17 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 12:08:37 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

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

static void		draw_minimap(t_home *home, t_frame *frame)
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

static void		draw_player(t_frame *frame)
{
	draw_rect(center_to_screen((t_xy){0.0f, 0.0f}),
		(t_xy){3.0f, 3.0f}, frame, yellow);
	draw_line(center_to_screen((t_xy){0.0f, 0.0f}),
		center_to_screen(vec2_sum((t_xy){0.0f, 0.0f},
		vec2_mult((t_xy){1.0f, 0.0f}, 400))), lightgreen, frame->draw_surf);
	draw_line(center_to_screen((t_xy){0.0f, 0.0f}),
		center_to_screen(vec2_sum((t_xy){0.0f, 0.0f},
		vec2_mult((t_xy){0.0f, 1.0f}, 400))), lightgreen, frame->draw_surf);
}

static void		draw_info(t_frame *frame, t_player *plr, int nb_fps)
{
	char	*sector;
	char	*compass;
	char	*fps;

	compass = compass_direction(&plr->dir);
	sector = ft_itoa(plr->current_sector);
	fps = ft_itoa(nb_fps);
	str_pxl(frame, (t_xy){SCREEN_WIDTH * 0.5 - 15, 0}, fps);
	str_pxl(frame, (t_xy){0, 50}, "dir: ");
	str_pxl(frame, (t_xy){50, 50}, compass);
	str_pxl(frame, (t_xy){0, 70}, "sector:");
	str_pxl(frame, (t_xy){0, 90}, sector);
	str_pxl(frame, (t_xy){0, 380}, "Press z to switch to wireframe");
	str_pxl(frame, (t_xy){0, 400}, "Press x to close minimap");
	str_pxl(frame, (t_xy){0, 420}, "Press c to close info");
	str_pxl(frame, (t_xy){0, 440}, "Move with wasd, rotate with q and e.");
	str_pxl(frame, (t_xy){0, 460}, "Look with mouse.");
	free(fps);
	free(sector);
	free(compass);
}

void			draw_frame(t_home *home, t_frame *frame, t_player *plr)
{
	frame->idx = plr->current_sector;
	frame->old_idx = -1;
	frame->max_fov = 0;
	frame->offset = 640;
	frame->pxl_offset = 0.0f;
	frame->left.l_pt = (t_xy){-1.0f, -1.0f};
	frame->right.r_pt = (t_xy){-1.0f, -1.0f};
	frame->plr_offset = (t_xy){SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f};
	scan_fov(home, frame, plr, 0);
	if (plr->input.minimap)
	{
		draw_minimap(home, frame);
		draw_player(frame);
	}
	if (plr->input.info)
		draw_info(frame, plr, (int)home->t.fps);
	return ;
}
