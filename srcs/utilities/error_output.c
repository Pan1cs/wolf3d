/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:39:00 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 10:34:32 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	error_output_sdl(char *msg, t_home *home)
{
	SDL_DestroyWindow(home->win.window);
	ft_putendl_fd(msg, 2);
	SDL_Quit();
	exit(0);
}

void	error_output(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

int		error_handling(int error_code, t_texture **tex)
{
	free_full_colour_map(*tex);
	ft_memdel((void**)tex);
	if (error_code == 1)
		ft_putendl_fd("ERROR: Malformed header data", 2);
	else if (error_code == 2)
		ft_putendl_fd("ERROR: Invalid height. Texture has to be 128 x 128", 2);
	else if (error_code == 3)
		ft_putendl_fd("ERROR: Invalid width. Texture has to be 128 x 128", 2);
	else if (error_code == 4)
		ft_putendl_fd("ERROR: Number of colours can't be zero.", 2);
	else if (error_code == 5)
		ft_putendl_fd("ERROR: Memory allocation of pixels failed.", 2);
	else if (error_code == 6)
		ft_putendl_fd("ERROR: Number of chars per pxl can't be zero.", 2);
	else if (error_code == 7)
		ft_putendl_fd("ERROR: Invalid colour id in pixel array.", 2);
	else if (error_code == 8)
		ft_putendl_fd("ERROR: Invalid number of pixels in array.", 2);
	else if (error_code == 9)
		ft_putendl_fd("ERROR: Invalid height in array.", 2);
	else if (error_code == 10)
		ft_putendl_fd("ERROR: Colour mapping failed.", 2);
	else
		ft_putendl_fd("ERROR: Undefined error.", 2);
	return (error_code);
}
