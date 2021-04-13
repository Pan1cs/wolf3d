/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:40:30 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/13 17:34:36 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

Uint32		colour_scale(Uint32 hex, float scale)
{
	t_argb	argb;

	argb.a = (hex & 0xFF000000);
	argb.r = (hex & 0x00FF0000) * scale;
	argb.g = (hex & 0x0000FF00) * scale;
	argb.b = (hex & 0x000000FF) * scale;
	return ((argb.a | (argb.r & 0x00FF0000) | (argb.g & 0x0000FF00) | (argb.b & 0x000000FF)));
}
