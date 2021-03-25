/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:10:50 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/25 09:42:10 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int  			main(int argc, char **argv)
{
	t_home		home;
	t_player	plr;
	t_frame		frame;
	SDL_Event	e;

	if (argc == 1)
	 	error_output("usage: .\\play [map file path]");
	setup(argv[1], &home, &plr, &frame);
	while (1)
	{
		update_player(&plr, &home, &e);
		update_screen(&home, &frame, &plr);
		SDL_UpdateWindowSurface(home.win.window);
		clear_surface(frame.draw_surf);
		SDL_FreeSurface(frame.draw_surf);
	}
	TTF_Quit();
	SDL_Quit();
	return 0;
}
