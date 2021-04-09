/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:10:50 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 09:18:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char **argv)
{
	t_home		home;
	t_player	plr;
	t_frame		frame;
	SDL_Event	e;

	if (argc == 1)
		error_output("usage: .\\wolf3d [map file path]");
	setup(argv[1], &home, &plr, &frame);
	while (!plr.input.quit)
	{
		fps_timer(&home.t);
		update_player(&plr, &home, &e);
		update_screen(&home, &frame, &plr);
		SDL_UpdateWindowSurface(home.win.window);
		clear_surface(frame.draw_surf);
		SDL_FreeSurface(frame.draw_surf);
	}
	free_sectors(&home);
	free_textures(&home.editor_tex, 5);
	free(home.t.frame_times);
	cleanup_audio(&plr.audio);
	SDL_Quit();
	ft_putendl("User closed the window");
	return (0);
}
