/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:15:19 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 08:25:59 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

// void	error_output_sdl(char *msg, t_home *home)
// {
// 	SDL_DestroyWindow(home->win.window);
// 	ft_putendl_fd(msg, 2);
// 	exit(0);
// }

void	error_output(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}
