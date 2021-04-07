/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:00:37 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/07 15:45:21 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"


void	fps_timer(t_time *t)
{
	Uint32			frametimes_index;
	Uint32			getticks;
	Uint32			count;
	Uint32			i;

	i = 0;
	frametimes_index = t->frame_count % 10;
	getticks = SDL_GetTicks();
	t->frame_times[frametimes_index] = getticks - t->frame_time_last;
	t->frame_time_last = getticks;
	t->frame_count = t->frame_count + 1;
	if (t->frame_count < 10)
		count = t->frame_count;
	else
		count = 10;
	t->fps = 0;
	while (i < count)
	{
		t->fps += t->frame_times[i];
		i++;
	}
	t->fps /= count;
	t->fps = 1000.0f / t->fps;
}
