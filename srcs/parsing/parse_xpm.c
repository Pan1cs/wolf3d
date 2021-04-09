/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:45:03 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 10:34:39 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static int		parse_header_data(char *ptr, t_texture *tex)
{
	if (*ptr != '"')
		return (1);
	ptr++;
	tex->w = ft_atoi(ptr);
	if (tex->w != 128)
		return (2);
	ptr = ptr + ft_nb_len(tex->w, 10) + 1;
	tex->h = ft_atoi(ptr);
	if (tex->h != 128)
		return (3);
	ptr = ptr + ft_nb_len(tex->h, 10) + 1;
	tex->nbr_of_colours = ft_atoi(ptr);
	if (tex->nbr_of_colours == 0)
		return (4);
	ptr = ptr + ft_nb_len(tex->nbr_of_colours, 10) + 1;
	tex->cpp = ft_atoi(ptr);
	if (tex->cpp == 0)
		return (5);
	ptr = ptr + ft_nb_len(tex->cpp, 10);
	if (*ptr != '"')
		return (1);
	return (0);
}

static char		*validate_header(char *ptr)
{
	if (ft_strncmp((const char*)ptr, "/* XPM */", 9))
		error_output("ERROR: Malformed xpm header");
	if (!(ptr = ft_strstr((const char*)ptr, "static char * ")))
		error_output("ERROR: Malformed static char array header");
	return (ptr);
}

int				parse_xpm_data(unsigned char *buf, t_texture **tex)
{
	char	*ptr;
	int		ret;

	*tex = (t_texture*)malloc(sizeof(t_texture));
	if (!*tex || !buf)
		error_output("ERROR: Invalid pointer");
	ptr = validate_header((char*)buf);
	while (*ptr != '[')
		ptr++;
	if (!(ptr = ft_strstr((const char*)buf, "[] = {\n")))
		error_output("ERROR: Malformed data");
	ptr = ptr + 7;
	if ((ret = parse_header_data(ptr, *tex)))
		return (error_handling(ret, tex));
	ptr = strchr((const char*)ptr, '\n') + 1;
	ptr = parse_colour_data(ptr, *tex);
	if (!ptr)
		return (error_handling(10, tex));
	if ((ret = parse_pixel_data(ptr, *tex)))
		return (error_handling(ret, tex));
	free_full_colour_map(*tex);
	return (0);
}
