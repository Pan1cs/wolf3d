/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:21:00 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/07 14:05:16 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define BUFF_SIZE 16
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

# define WALL_HEIGHT 0.5f
# define TEX_SIZE 128
# define FOV 1.57079616f
# define MAP_MAX_LINES 128
# define MINIMAP_SIZE 10

# define NUM_TEX 8

# define PLR_DIR 0.785398163f

# define MAX_INT (2147483647)
# define MIN_INT (-MAX_INT - 1)
# define MAX_UINT ((unsigned int)-1)
# define MAX_ULONG ((unsigned long)-1)
# define MAX_ULLONG ((unsigned long long)-1)

# define PI (3.1415926535f)
# define PI_BY_TWO (1.570796326f)
# define TWO_PI (6.283185307f)
# define RAD_TO_DEG (57.29577951f)
# define DEG_TO_RAD (0.0174532925f)
# define SQR2 (0.7071067812)

# define TRUE (1)
# define FALSE (0)
# define AND (&&)
# define OR (||)

/*
**
*** Keyboard and Mouse macros
**
*/

# define K_ESC SDLK_ESCAPE
# define K_SPACE SDLK_SPACE
# define K_CTRL SDLK_LCTRL
# define K_SHIFT SDLK_LSHIFT

# define K_UP SDLK_UP
# define K_DOWN SDLK_DOWN
# define K_LEFT SDLK_LEFT
# define K_RIGHT SDLK_RIGHT

# define K_W SDLK_w
# define K_S SDLK_s
# define K_A SDLK_a
# define K_D SDLK_d
# define K_Q SDLK_q
# define K_E SDLK_e
# define K_Z SDLK_z
# define K_X SDLK_x
# define N 6.28318530718f
# define NW 0.7853981634f
# define W 1.5707963268f
# define SW 2.3561944902f
# define S 3.14159265359f
# define SE 3.926990817f
# define E 4.71238898039f
# define NE 5.49778714378f

#endif
