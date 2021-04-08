/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:39:00 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 18:35:26 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	error_output_sdl(char *msg, t_home *home)
{
	SDL_DestroyWindow(home->win.window);
	ft_putendl_fd(msg, 2);
	exit(0);
}

void	error_output(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

void	error_handling(int error_code, t_texture *tex)
{
	free_full_colour_map(tex);
	free_pixels(tex);
	free(tex);
	if (error_code == 1)
		error_output("ERROR: Malformed header data");
	else if (error_code == 2)
		error_output("ERROR: Invalid height. Texture has to be 128 x 128");
	else if (error_code == 3)
		error_output("ERROR: Invalid width. Texture has to be 128 x 128");
	else if (error_code == 4)
		error_output("ERROR: Number of colours can't be zero.");
	else if (error_code == 5)
		error_output("ERROR: Memory allocation of pixels failed.");
	else if (error_code == 6)
		error_output("ERROR: Number of chars per pxl can't be zero.");
	else if (error_code == 7)
		error_output("ERROR: Invalid colour id in pixel array.");
	else if (error_code == 8)
		error_output("ERROR: Invalid number of pixels in array.");
	else if (error_code == 9)
		error_output("ERROR: Invalid height in array.");
	else
		error_output("ERROR: Undefined error.");
}
