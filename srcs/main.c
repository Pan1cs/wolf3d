/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:10:50 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/26 12:27:11 by jnivala          ###   ########.fr       */
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
		error_output("usage: .\\play [map file path]");
	setup(argv[1], &home, &plr, &frame);
	while (!plr.input.quit)
	{
		update_player(&plr, &home, &e);
		update_screen(&home, &frame, &plr);
		SDL_UpdateWindowSurface(home.win.window);
		clear_surface(frame.draw_surf);
		SDL_FreeSurface(frame.draw_surf);
	}
	free_textures(&home.editor_tex, 7);
	cleanup_audio(&plr.audio);
	quit_subsystems();
	ft_putendl("User closed the window");
	return (0);
}
