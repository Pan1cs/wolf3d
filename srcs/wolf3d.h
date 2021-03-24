/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:06:53 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 16:28:58 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
**	Non-standard includes
*/

# include "../SDL2/include/SDL2/SDL.h"
# include "../SDL2/include/SDL2/SDL_ttf.h"
# include <time.h>
# include <fcntl.h>
# include <dirent.h>

# ifdef __unix__
#  define OPEN_FILE open
#  define READ_FILE read
#  define CLOSE_FILE close
#  define READ_ONLY O_RDONLY
#  define WRITE_ONLY O_WRONLY
#  define APPEND_FILE O_APPEND
#  define CHECK_EXIST O_EXCL
#  define CREATE_FILE O_CREAT
#  define TRUNCATE O_TRUNC
#  include <math.h>
#  include <SDL2/SDL_mixer.h>
#  include <string.h>
#  include <unistd.h>
# elif __APPLE__
#  define OPEN_FILE open
#  define READ_ONLY O_RDONLY
#  include <string.h>
#  include <unistd.h>
# elif defined(_WIN32) || defined(WIN32)
#  define OPEN_FILE _open
#  define READ_FILE _read
#  define CLOSE_FILE _close
#  define READ_ONLY _O_BINARY
#  define WRITE_ONLY _O_WRONLY
#  define CHECK_EXIST _O_EXCL
#  define APPEND_FILE _O_APPEND
#  define CREATE_FILE _O_CREAT
#  define TRUNCATE _O_TRUNC
#  include "../SDL2_mixer_win/include/SDL2/SDL_mixer.h"
#  include <io.h>
#  include <stdio.h>

# endif
# include "../libft/libft.h"
# include "../headers/macros.h"
# include "../headers/vectors.h"
# include "../headers/entity.h"
# include "../headers/sector.h"
# include "../headers/calculations.h"
# include "../headers/colours.h"
# include "../headers/program.h"
# include "../headers/audio.h"
# include "../headers/player.h"
# include "../headers/player_functions.h"
# include "../headers/raycast.h"
# include "../headers/drawing_functions.h"
# include "../headers/events.h"
# include "../headers/porting.h"
# include "../headers/parsing.h"
# include "../headers/map.h"

/*
** Miscellanious
*/

void			update_screen(t_home *home, t_frame *frame, t_player *plr);
void			setup(char *mapname, t_home *home, t_player *plr, t_frame *frame);
void			error_output_sdl(char *msg, t_home *home);
void			error_output(char *msg);
void			load_audio(t_audio *audio);
void			cleanup_audio(t_audio *audio);
void			play_footsteps(t_player *plr);

/*
** Minimap
*/

t_xy			scale(t_xy a);
void			draw_minimap(t_xy size, t_xy pos, t_xy dir, t_home *home);
void			draw_grid(t_frame *frame);
int				update_sector(t_home *home);
void			translate_world_view(t_home *home, t_xy step);
void			transform_world_view(t_home *home, float delta_dir);

void			draw_text(t_home *home, char *text, t_frame *frame, t_xy pos);


void	error_output(char *msg);
#endif
