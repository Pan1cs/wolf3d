/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:06:53 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 08:27:29 by jnivala          ###   ########.fr       */
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
#  include "/usr/local/include/SDL2/SDL_mixer.h"
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
#  include "SDL2_mixer_win/include/SDL2/SDL_mixer.h"
#  include <io.h>
#  include <stdio.h>

# endif
# include "../libft/libft.h"


void	error_output(char *msg);
#endif
