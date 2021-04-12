/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:00:37 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/12 15:11:12 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	fps_timer(t_time *t)
{
	Uint32	time_index;
	Uint32	current_time;
	Uint32	current_frame_amount;
	Uint32	i;

	i = 0;
	current_frame_amount = 10;
	current_time = SDL_GetTicks();
	time_index = t->frame_count % 10;
	t->frame_times[time_index] = current_time - t->frame_time_last;
	t->frame_time_last = current_time;
	t->frame_count = t->frame_count + 1;
	if (t->frame_count < 10)
		current_frame_amount = t->frame_count;
	t->fps = 0;
	while (i < current_frame_amount)
	{
		t->fps += t->frame_times[i];
		i++;
	}
	t->fps = 1000.0f / (t->fps / current_frame_amount);
}
