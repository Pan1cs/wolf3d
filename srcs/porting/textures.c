/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:53:07 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/14 12:38:23 by jnivala          ###   ########.fr       */
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

static int	load_texture(t_texture **texture, char *path)
{
	if (load_xpm_file(texture, path) || !(*texture))
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
	if (load_texture(*(textures) + 4, "resources/loading_bay.xpm"))
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

int			set_to_null(t_texture **tex, int error)
{
	*tex = NULL;
	if (error == 121)
		ft_putendl_fd("ERROR: Wrong extension", 2);
	else if (error == 122)
		ft_putendl_fd("ERROR: Failed to open map", 2);
	else if (error == 123)
		ft_putendl_fd("ERROR: Failed to read bitmap.", 2);
	else if (error == 124)
		ft_putendl_fd("ERROR: File is too large.", 2);
	else if (error == 125)
		ft_putendl_fd("ERROR: Could not close the file.", 2);
	else
		ft_putendl_fd("ERROR: Undefined", 2);
	return (error);
}
