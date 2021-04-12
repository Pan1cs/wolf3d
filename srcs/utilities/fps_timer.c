/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:00:37 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/11 18:31:29 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	fps_timer(t_time *t)
{
	Uint32	time_index;
	Uint32	current_time;
	Uint32	count;
	Uint32	i;

	i = 0;
	time_index = t->frame_count % 10;
	current_time = SDL_GetTicks();
	t->frame_times[time_index] = current_time - t->frame_time_last;
	t->frame_time_last = current_time;
	t->frame_count = t->frame_count + 1;
	count = 10;
	if (t->frame_count < 10)
		count = t->frame_count;
	t->fps = 0;
	while (i < count)
	{
		t->fps += t->frame_times[i];
		i++;
	}
	t->fps /= count;
	t->fps = 1000.0f / t->fps;
}
