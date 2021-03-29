/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:23:17 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 11:40:05 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		keys_down(t_player *plr, SDL_KeyCode sym, SDL_Event *e)
{
	if (sym == k_s)
		plr->input.down = 1;
	if (sym == k_w)
		plr->input.up = 1;
	if (sym == k_d)
		plr->input.right = 1;
	if (sym == k_a)
		plr->input.left = 1;
	if (sym == k_esc || e->type == SDL_QUIT)
		plr->input.quit = 1;
}

void		keys_up(t_player *plr, SDL_KeyCode sym)
{
	if (sym == k_s)
		plr->input.down = 0;
	if (sym == k_w)
		plr->input.up = 0;
	if (sym == k_d)
		plr->input.right = 0;
	if (sym == k_a)
		plr->input.left = 0;
}

void		key_input(t_player *plr, SDL_Event *e)
{
	if (e->type == SDL_KEYDOWN)
		keys_down(plr, e->key.keysym.sym, e);
	else if (e->type == SDL_KEYUP)
		keys_up(plr, e->key.keysym.sym);
	else
		return ;
}
