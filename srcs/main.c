/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:10:50 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/07 15:39:16 by jnivala          ###   ########.fr       */
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
		fps_timer(&home.t);
		update_player(&plr, &home, &e);
		update_screen(&home, &frame, &plr);
		str_pxl(&frame, (t_xy){0, 120}, ft_ftoa(home.t.fps, 7));
		SDL_UpdateWindowSurface(home.win.window);
		clear_surface(frame.draw_surf);
		SDL_FreeSurface(frame.draw_surf);
	}
	free_sectors(&home);
	free_textures(&home.editor_tex, 7);
	cleanup_audio(&plr.audio);
	quit_subsystems();
	ft_putendl("User closed the window");
	return (0);
}
