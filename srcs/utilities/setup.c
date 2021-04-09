/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:17:33 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 08:22:49 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static t_home	*init_sdl(t_home *home, t_frame *frame)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0)
		error_output_sdl("Fatal: SDL Initalization failed.", home);
	home->win.window = SDL_CreateWindow("Wolf3d", 100, 100,
		home->win.width, home->win.height, 0);
	if (home->win.window == NULL)
		error_output_sdl("Fatal: Failed to create a window.", home);
	SDL_SetWindowPosition(home->win.window,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	frame->draw_surf = SDL_GetWindowSurface(home->win.window);
	if (frame->draw_surf == NULL)
		error_output_sdl("Fatal: Failed to get window surface", home);
	frame->min_step = 0.002454369f;
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
	plr->move_dir.x = 0.785398163f;
	plr->move_dir.y = 0.785398163f;
	plr->input.down = 0;
	plr->input.up = 0;
	plr->input.right = 0;
	plr->input.left = 0;
	plr->input.quit = 0;
	plr->input.z = 1;
	plr->time = 0;
	plr->height = 0.5;
	plr->angle = 0;
	plr->current_sector = 0;
}

void			setup(char *map, t_home *home, t_player *plr, t_frame *frame)
{
	int		ret;

	load_map_file(home, map);
	transform_world_view(home, -PLR_DIR);
	home->win.width = SCREEN_WIDTH;
	home->win.height = SCREEN_HEIGHT;
	home->t.frame_times = (Uint32*)malloc(sizeof(Uint32) * 11);
	home->t.frame_count = 0;
	home->t.fps = 0;
	home->t.frame_time_last = SDL_GetTicks();
	home->offset = vec2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	if ((ret = load_textures(&home->editor_tex, 5)))
		clean_up(home, ret);
	home = init_sdl(home, frame);
	load_audio(&plr->audio);
	if (Mix_PlayingMusic() == 0)
		Mix_PlayMusic(plr->audio.music, -1);
	init_player(plr);
}

void			clean_up(t_home *home, int ret)
{
	free_textures(&home->editor_tex, ret);
	free_sectors(home);
	if (home->t.frame_times)
		free(home->t.frame_times);
	ft_putendl_fd("Shutting down.", 2);
	exit(1);
}
