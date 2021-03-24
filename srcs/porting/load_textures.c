/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:53:07 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 17:10:34 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		load_textures(SDL_Surface **textures, int nbr_of_textures)
{
	textures = malloc(sizeof(SDL_Surface*) * (nbr_of_textures + 1));
	if (!(textures[0] = SDL_LoadBMP("resources/wall_bricks.bmp")))
		error_output("ERROR: Texture not found.");
	textures[1] = SDL_LoadBMP("resources/wall_bricks.bmp");
	textures[2] = SDL_LoadBMP("resources/wall_bricks.bmp");
	textures[3] = SDL_LoadBMP("resources/wall_bricks.bmp");
	textures[4] = SDL_LoadBMP("resources/floor1.bmp");
	textures[5] = SDL_LoadBMP("resources/tiles1.bmp");
}
