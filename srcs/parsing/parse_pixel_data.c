/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pixel_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:41:32 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 17:42:24 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static char	*check_eof_or_eol(int *h, int *pxl_idx, char *ptr, t_texture *tex)
{
	if (!ft_strncmp(ptr, "\",\n", 3))
	{
		if (*pxl_idx % (tex->w - 1 + tex->h * *h) != 0)
			error_handling(8, tex);
		ptr += 3;
		*h = *h + 1;
	}
	if (!ft_strncmp(ptr, "\"};\n", 4))
	{
		if (*(ptr + 4) == '\0')
			ptr += 4;
	}
	return (ptr);
}

static int	check_pixel_data(int i, char *ptr, t_texture *tex)
{
	while (*ptr && ft_strncmp(ptr, tex->colour_map[i]->id, tex->cpp)
			&& *(ptr + tex->cpp) != '\n')
	{
		i++;
		if (i == tex->nbr_of_colours)
			return (-1);
	}
	return (i);
}

int			parse_pixel_data(char *ptr, t_texture *tex)
{
	int			i;
	int			pxl_idx;
	int			h;

	h = 0;
	pxl_idx = 0;
	if (!(tex->pixels = (Uint32*)malloc(sizeof(Uint32)
		* (tex->w * tex->h + 1))))
		return (6);
	while (*ptr)
	{
		i = 0;
		if (*ptr == '"')
			ptr++;
		i = check_pixel_data(i, ptr, tex);
		if (i == -1)
			return (7);
		tex->pixels[pxl_idx] = tex->colour_map[i]->colour;
		ptr += tex->cpp;
		ptr = check_eof_or_eol(&h, &pxl_idx, ptr, tex);
		pxl_idx++;
	}
	if (h + 1 != tex->h)
		return (9);
	return (0);
}
