/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:21:45 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 11:09:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_FUNCTIONS_H
# define PLAYER_FUNCTIONS_H

/*
** Player functions
*/

void			init_player(t_player *plr);
int				player_move(t_player *plr, t_home *home, t_xy *dir);
void			play_footsteps(t_player *plr);
void			update_player(t_player *plr, t_home *home, SDL_Event *e);
#endif
