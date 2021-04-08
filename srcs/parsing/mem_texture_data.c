/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_texture_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:37:35 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 20:53:38 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			free_pixels(t_texture *tex)
{
	if (tex != NULL)
	{
		free(tex->pixels);
		tex->pixels = NULL;
	}
}

int				free_full_colour_map(t_texture *tex)
{
	int		i;

	i = 0;
	while (i < tex->nbr_of_colours)
	{
		if (tex->colour_map[i])
			free(tex->colour_map[i]);
		i++;
	}
	free(tex->colour_map);
	return (0);
}

t_colour_map	*free_colour_id(t_texture *tex, int n)
{
	while (n--)
		ft_strdel(&(tex->colour_map[n]->id));
	return (NULL);
}

t_texture		*free_colour_map_n(t_texture *tex, int n)
{
	while (n--)
		free(tex->colour_map[n]);
	free(tex->colour_map);
	return (NULL);
}

t_colour_map	**mem_alloc_colour_map(t_texture *tex)
{
	int		i;

	i = 0;
	tex->colour_map = (t_colour_map**)malloc(sizeof(t_colour_map)
		* tex->nbr_of_colours + 1);
	if (!(tex->colour_map))
	{
		free_colour_map_n(tex, i);
		return (NULL);
	}
	while (i < tex->nbr_of_colours)
	{
		tex->colour_map[i] = (t_colour_map*)malloc(sizeof(t_colour_map));
		if (!(tex->colour_map[i]))
		{
			free_colour_map_n(tex, i);
			return (NULL);
		}
		i++;
	}
	return (tex->colour_map);
}
