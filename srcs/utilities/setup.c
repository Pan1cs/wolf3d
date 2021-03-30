/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:17:33 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/30 14:24:57 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static t_home	*init_sdl(t_home *home, t_frame *frame)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0)
		error_output_sdl("Fatal: SDL Initalization failed.", home);
	home->win.window = SDL_CreateWindow("Wolf3d", 100, 100,
		home->win.width, home->win.height, 0);
	if (!home->win.window)
		error_output_sdl("Fatal: Failed to create a window.", home);
	SDL_SetWindowPosition(home->win.window,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	frame->draw_surf = SDL_GetWindowSurface(home->win.window);
	if (!frame->draw_surf)
		error_output_sdl("Fatal: Failed to get window surface", home);
	frame->min_step = .002454369f;
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
		error_output_sdl("Fatal: SDL_mixer could not initialize!", home);
	return (home);
}

void			init_player(t_player *plr)
{
	plr->pos = vec2(0, 0);
	plr->z = 0;
	plr->pitch = 240;
	plr->dir.x = 0.0f;
	plr->dir.y = 1.0f;
	plr->move_dir.x = 0.0f;
	plr->move_dir.y = 1.0f;
	plr->input.down = 0;
	plr->input.up = 0;
	plr->input.right = 0;
	plr->input.left = 0;
	plr->input.quit = 0;
	plr->time = 0;
	plr->height = 0.5;
	plr->angle = 0;
	plr->current_sector = 0;
}

void			quit_subsystems(void)
{
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_Quit();
}

void			setup(char *map, t_home *home, t_player *plr, t_frame *frame)
{
	load_map_file(home, map);
	home->win.width = SCREEN_WIDTH;
	home->win.height = SCREEN_HEIGHT;
	home->t.fps = 0;
	home->t.frames = 0;
	home->offset = vec2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	home = init_sdl(home, frame);
	load_audio(&plr->audio);
	if (Mix_PlayingMusic() == 0)
		Mix_PlayMusic(plr->audio.music, -1);
	load_textures(&home->editor_tex, 7);
	init_player(plr);
}
