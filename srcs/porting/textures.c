/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:53:07 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 19:01:21 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int			get_floor(int floor_colour)
{
	if (floor_colour == -1)
		return (darkolivegreen);
	else if (floor_colour == -2)
		return (steelblue);
	else if (floor_colour == -3)
		return (darkturquoise);
	else if (floor_colour == -4)
		return (snow);
	else if (floor_colour == -5)
		return (dimgray);
	else
		return (green);
}

int			get_texel(int x, int y, SDL_Surface *tex)
{
	int		offset_x;
	int		offset_y;
	int		bpp;
	Uint32	*p;

	offset_x = x % tex->w;
	offset_y = y % tex->h;
	bpp = tex->format->BytesPerPixel;
	p = (Uint32*)((Uint8*)tex->pixels + offset_y * tex->pitch + offset_x * bpp);
	return (*p);
}

static int	load_texture(t_texture **texture, char *path)
{
	load_xpm_file(texture, path);
	if (!(*texture))
	{
		ft_putendl("ERROR: Texture loading failed.");
		return (1);
	}
	return (0);
}

int			load_textures(t_texture ***textures, int nbr_of_textures)
{
	*textures = malloc(sizeof(t_texture*) * (nbr_of_textures + 1));
	if (load_texture(*(textures) + 0, "resources/hull.xpm"))
		return (1);
	if (load_texture(*(textures) + 1, "resources/hull2.xpm"))
		return (2);
	if (load_texture(*(textures) + 2, "resources/armory.xpm"))
		return (3);
	if (load_texture(*(textures) + 3, "resources/door.xpm"))
		return (4);
	if (load_texture(*(textures) + 4, "resources/door.xpm"))
		return (5);
	return (0);
}

int			free_textures(t_texture ***textures, int nbr_of_textures)
{
	while (nbr_of_textures--)
	{
		free_pixels(*(*(textures) + nbr_of_textures));
		free(*(*(textures) + nbr_of_textures));
	}
	free(*textures);
	return (0);
}
