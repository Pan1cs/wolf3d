/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:40:30 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 15:24:17 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

Uint32		argb_to_hex(t_argb argb)
{
	return ((int)argb.r << 16 | (int)argb.g << 8 | (int)argb.b);
}

t_argb		hex_to_argb(Uint32 rgb)
{
	t_argb colour;

	colour.r = ((rgb >> 16) & 0xFF);
	colour.g = ((rgb >> 8) & 0xFF);
	colour.b = (rgb & 0xFF);
	return (colour);
}

Uint32		colour_scale(Uint32 hex, float scale)
{
	t_argb	argb;

	argb = hex_to_argb(hex);
	argb.r = scale * argb.r;
	argb.g = scale * argb.g;
	argb.b = scale * argb.b;
	return (argb_to_hex(argb));
}
