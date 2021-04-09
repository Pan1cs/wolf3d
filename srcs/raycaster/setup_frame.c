/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:26:00 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/25 10:33:01 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		setup_frame(t_frame *frame, t_frame *new_frame,
	int current_pxl, int idx)
{
	new_frame->idx = idx;
	new_frame->old_idx = frame->idx;
	new_frame->min_step = frame->min_step;
	if ((frame->offset - current_pxl) < 0)
		new_frame->max_fov = 0.0f;
	else
		new_frame->max_fov = frame->offset - current_pxl;
	new_frame->offset = frame->offset;
	new_frame->draw_surf = frame->draw_surf;
	new_frame->pxl_offset = frame->pxl_offset;
}
