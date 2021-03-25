/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:53:07 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/25 09:04:25 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int			get_texel(int x, int y, SDL_Surface *tex)
{
	int		offset_x;
	int		offset_y;
	int		bpp;
	Uint32 *p;

	offset_x = x % tex->w;
	offset_y = y % tex->h;
	bpp = tex->format->BytesPerPixel;
	p = (Uint32*)((Uint8*)tex->pixels + offset_y * tex->pitch + offset_x * bpp);
	return (*p);
}

static int	load_texture(SDL_Surface **texture, char *path)
{
	*texture = SDL_LoadBMP(path);
	if (!(*texture))
		error_output("ERROR: Texture not found.");
	return (0);
}


int			load_textures(SDL_Surface ***textures, int nbr_of_textures)
{
	*textures = malloc(sizeof(SDL_Surface*) * (nbr_of_textures + 1));
	load_texture(*(textures) + 0, "resources/wall_bricks.bmp");
	load_texture(*(textures) + 1, "resources/wall_dark.bmp");
	load_texture(*(textures) + 2, "resources/wall_skulls.bmp");
	load_texture(*(textures) + 3, "resources/tiles1.bmp");
	load_texture(*(textures) + 4, "resources/paving1.bmp");
	load_texture(*(textures) + 5, "resources/floor1.bmp");
	load_texture(*(textures) + 6, "resources/tiles1.bmp");
	return (0);
}
