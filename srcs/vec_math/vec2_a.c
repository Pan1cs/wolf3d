/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:39:11 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 16:39:13 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xy			vec2(float x, float y)
{
	return ((t_xy){x, y});
}

t_xy			vec2_add(t_xy a, t_xy b)
{
	return ((t_xy)
	{
		a.x + b.x,
		a.y + b.y
	});
}

t_xy			vec2_dec(t_xy a, t_xy b)
{
	return ((t_xy)
	{
		a.x - b.x,
		a.y - b.y
	});
}
