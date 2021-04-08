/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colour_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:51:48 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 19:41:40 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static char		*get_id(char *ptr, int *i, t_texture *tex)
{
	if (!ptr)
		return (NULL);
	ptr++;
	tex->colour_map[*i]->id = ft_strndup(ptr, tex->cpp);
	if (!(tex->colour_map[*i]->id))
		return (NULL);
	ptr += tex->cpp + 1;
	return (ptr);
}

static char		*get_colour_type(char *ptr, int *i, t_texture *tex)
{
	if (!ptr && *ptr != 'c')
		return (NULL);
	tex->colour_map[*i]->colour_type = *ptr;
	ptr += 2;
	return (ptr);
}

static char		*get_colour(char *ptr, int *i, t_texture *tex)
{
	if (*ptr == '#')
	{
		tex->colour_map[*i]->colour = ft_atoi_base(++ptr, 16);
		ptr += ft_nb_len(tex->colour_map[*i]->colour, 16) + 3;
	}
	else if (ft_strncmp(ptr, "None", 4) == 0)
	{
		tex->colour_map[*i]->colour = 0;
		ptr += 7;
	}
	else
		return (NULL);
	return (ptr);
}

static char		*clean_up_colour_map(int i, t_texture **tex)
{
	free_colour_id(*tex, i);
	free_full_colour_map(*tex);
	return (NULL);
}

char			*parse_colour_data(char *ptr, t_texture *tex)
{
	int			i;

	i = 0;
	tex->colour_map = mem_alloc_colour_map(tex);
	if (!(tex->colour_map))
		return (NULL);
	while (i < tex->nbr_of_colours)
	{
		if (!(ptr = get_id(ptr, &i, tex)))
			return (clean_up_colour_map(i, &tex));
		if (!(ptr = get_colour_type(ptr, &i, tex)))
		{
			i++;
			return (clean_up_colour_map(i, &tex));
		}
		if (!(ptr = get_colour(ptr, &i, tex)))
		{
			i++;
			return (clean_up_colour_map(i, &tex));
		}
		i++;
	}
	return (ptr);
}
