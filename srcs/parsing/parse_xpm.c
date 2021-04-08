/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:45:03 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 13:34:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static int			parse_header_data(char *ptr, t_texture *tex)
{
	ptr++;
	tex->w = ft_atoi(ptr);
	if (tex->w != 128)
		return (2);
	ptr = ptr + ft_nb_len(tex->w, 10) + 1;
	tex->h = ft_atoi(ptr);
	if (tex->h != 128)
		return (2);
	ptr = ptr + ft_nb_len(tex->h, 10) + 1;
	tex->nbr_of_colours = ft_atoi(ptr);
	ptr = ptr + ft_nb_len(tex->nbr_of_colours, 10) + 1;
	tex->cpp = ft_atoi(ptr);
	ptr = ptr + ft_nb_len(tex->cpp, 10);
	if (*ptr == '"')
		return (0);
	else
		return (1);
}

static char		*parse_colour_data(char *ptr, t_texture *tex)
{
	int			i;

	i = 0;
	tex->colour_map = (t_colour_map**)malloc(sizeof(t_colour_map) * tex->nbr_of_colours + 1);
	if (!(tex->colour_map))
		return (NULL);
	while (i < tex->nbr_of_colours)
	{
		ptr++;
		tex->colour_map[i] = (t_colour_map*)malloc(sizeof(t_colour_map));
		tex->colour_map[i]->id = ft_strndup(ptr, tex->cpp);
		ptr += tex->cpp + 1;
		if (*ptr != 'c')
			return (NULL);
		tex->color_type = *ptr;
		ptr += 2;
		if (*ptr == '#')
		{

			tex->colour_map[i]->colour = ft_atoi_base(++ptr, 16);
			ptr += ft_nb_len(tex->colour_map[i]->colour, 16) + 3;
		}
		else if (ft_strncmp(ptr, "None", 4) == 0)
		{
			tex->colour_map[i]->colour = 0;
			ptr += 7;
		}
		else
			return (NULL);
		i++;
	}
	return (ptr);
}

static int 		parse_pixel_data(char *ptr, t_texture *tex)
{
	int			i;
	int			pxl_idx;
	int			h;

	tex->pixels = (Uint32*)malloc(sizeof(Uint32)
		* (tex->w * tex->h + 1));
	pxl_idx = 0;
	h = 0;
	if (*ptr != '"')
		return (1);
	ptr++;
	while (*ptr)
	{
		i = 0;
		while (ft_strncmp(ptr, tex->colour_map[i]->id, tex->cpp))
		{
			i++;
			if (i == tex->nbr_of_colours)
				return (3);
		}
		tex->pixels[pxl_idx] = tex->colour_map[i]->colour;
		ptr += tex->cpp;
		if (!ft_strncmp(ptr, "\",\n", 3))
		{
			if (pxl_idx % (tex->w - 1 + tex->h * h) != 0)
				return (2);
			ptr += 4;
			h++;
		}
		if (!ft_strncmp(ptr, "\"};\n", 4))
			ptr += 4;
		pxl_idx++;
	}
	if (h + 1 != tex->h)
		return (2);
	return (0);
}

int			parse_xpm_data(unsigned char *buf, t_texture **tex)
{
	char	*ptr;
	int		ret;

	*tex = (t_texture*)malloc(sizeof(t_texture));
	if (!*tex || !buf)
		error_output("ERROR: Invalid pointer");
	if (ft_strncmp((const char*)buf, "/* XPM */", 9))
		error_output("ERROR: Malformed xpm header");
	if (!(ptr = ft_strstr((const char*)buf, "static char * ")))
		error_output("ERROR: Malformed static char array header");
	while (*ptr != '[')
		ptr++;
	if (!(ptr = ft_strstr((const char*)buf, "[] = {\n")))
		error_output("ERROR: Malformed data");
	ptr = ptr + 7;
	ret = parse_header_data(ptr, *tex);
	if (ret == 1)
		error_output("ERROR: Malformed header data");
	if (ret == 2)
		error_output("ERROR: Wrong texture size.");
	ptr = strchr((const char*)ptr, '\n') + 1;
	ptr = parse_colour_data(ptr, *tex);
	if (!ptr)
		error_output("ERROR: Malformed colour data.");
	ret = parse_pixel_data(ptr, *tex);
	if (ret == 3)
		error_output("ERROR: Wrong number of colours.");
	if (ret == 2)
		error_output("ERROR: Wrong width or height.");
	return (0);
}
