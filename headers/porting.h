/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   porting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:10 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/30 11:13:21 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORTING_H
# define PORTING_H

# define READ_BREAKER '#'
# define BUF_SIZE 10000

int			create_map_file(t_home *home);
int			load_map_file(t_home *home, char *path);
int			load_textures(SDL_Surface ***textures, int nbr_of_textures);
int			free_textures(SDL_Surface ***textures, int nbr_of_textures);
int			get_texel(int x, int y, SDL_Surface *tex);
int			get_next_breaker(unsigned char *buf);
int			get_floor(int floor_colour);

#endif
