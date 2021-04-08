/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   porting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:10 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 19:28:44 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORTING_H
# define PORTING_H

# define READ_BREAKER '#'
# define BUF_SIZE 30000
# define XPM_BUF_SIZE 200000

int				create_map_file(t_home *home);
int				load_map_file(t_home *home, char *path);
int				load_xpm_file(t_texture **texture, char *path);
int				load_textures(t_texture ***textures, int nbr_of_textures);
int				free_textures(t_texture ***textures, int nbr_of_textures);
void			free_pixels(t_texture *tex);
int				free_full_colour_map(t_texture *tex);
t_colour_map	*free_colour_id(t_texture *tex, int n);
t_texture		*free_colour_map_n(t_texture *tex, int n);
t_colour_map	**mem_alloc_colour_map(t_texture *tex);
int				get_texel(int x, int y, SDL_Surface *tex);
Uint32			get_texel2(t_texture *tex, int x, int y);
int				get_next_breaker(unsigned char *buf);
int				get_floor(int floor_colour);

#endif
