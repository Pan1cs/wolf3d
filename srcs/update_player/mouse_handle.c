/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:24:11 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/10 16:46:14 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	mouse_handle(t_player *plr, t_home *home, SDL_Event *e)
{
	if (e->type == SDL_MOUSEMOTION)
	{
		plr->dir.x += -e->motion.xrel * DEG_TO_RAD * 0.1;
		plr->dir.y += -e->motion.xrel * DEG_TO_RAD * 0.1;
		if (plr->dir.x > TWO_PI)
			plr->dir = (t_xy){0.0f, 0.0f};
		if (plr->dir.x < 0)
			plr->dir = (t_xy){TWO_PI, TWO_PI};
		transform_world_view(home, -e->motion.xrel * DEG_TO_RAD * 0.1);
		plr->pitch = ft_fmin(ft_fmax((plr->pitch - e->motion.yrel), 0), 480);
	}
	else if (e->window.event == SDL_WINDOWEVENT_CLOSE)
		plr->input.quit = 1;
}
