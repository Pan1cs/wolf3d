/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:23:17 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/10 16:13:58 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		action_keys(t_player *plr, SDL_KeyCode *sym)
{
	if (*sym == K_Z && plr->input.wireframe == 1)
		plr->input.wireframe = 0;
	else if (*sym == K_Z && plr->input.wireframe == 0)
		plr->input.wireframe = 1;
	if (*sym == K_X && plr->input.minimap == 1)
		plr->input.minimap = 0;
	else if (*sym == K_X && plr->input.minimap == 0)
		plr->input.minimap = 1;
	if (*sym == K_C && plr->input.info == 1)
		plr->input.info = 0;
	else if (*sym == K_C && plr->input.info == 0)
		plr->input.info = 1;
	if (*sym == K_M && plr->input.mouse == 0)
	{
		SDL_SetRelativeMouseMode(SDL_TRUE);
		plr->input.mouse = 1;
	}
	else if (*sym == K_M && plr->input.mouse == 1)
	{
		SDL_SetRelativeMouseMode(SDL_FALSE);
		plr->input.mouse = 0;
	}
}

void			keys_down(t_player *plr, SDL_KeyCode sym, SDL_Event *e)
{
	if (sym == K_S)
		plr->input.down = 1;
	if (sym == K_W)
		plr->input.up = 1;
	if (sym == K_D)
		plr->input.right = 1;
	if (sym == K_A)
		plr->input.left = 1;
	if (sym == K_Q)
		plr->input.rot_left = 1;
	if (sym == K_E)
		plr->input.rot_right = 1;
	action_keys(plr, &sym);
	if (sym == K_ESC || e->type == SDL_QUIT)
		plr->input.quit = 1;
	if (e->type == SDL_WINDOWEVENT && e->window.event == SDL_WINDOWEVENT_CLOSE)
		ft_putendl_fd("OHNONONO!", 2);
}

void			keys_up(t_player *plr, SDL_KeyCode sym)
{
	if (sym == K_S)
		plr->input.down = 0;
	if (sym == K_W)
		plr->input.up = 0;
	if (sym == K_D)
		plr->input.right = 0;
	if (sym == K_A)
		plr->input.left = 0;
	if (sym == K_Q)
		plr->input.rot_left = 0;
	if (sym == K_E)
		plr->input.rot_right = 0;
}

void			key_input(t_player *plr, SDL_Event *e)
{
	if (e->type == SDL_KEYDOWN)
		keys_down(plr, e->key.keysym.sym, e);
	else if (e->type == SDL_KEYUP)
		keys_up(plr, e->key.keysym.sym);
	else
		return ;
}
