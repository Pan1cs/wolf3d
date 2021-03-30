/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_line_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:13:01 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/30 13:56:22 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xy	line_intersection(t_intersection *sect)
{
	t_xy point;

	if (sect->neg > 0 && sect->neg <= 1 && sect->pos > 0)
	{
		point.x = (sect->x1 + sect->neg * (sect->x2 - sect->x1));
		point.y = (sect->y1 + sect->neg * (sect->y2 - sect->y1));
		return (point);
	}
	return (vec2(-1, -1));
}

void	calc_intersection(t_point *pgon, t_ray *ray, t_intersection *sect)
{
	sect->y1 = pgon->x0.y;
	sect->x1 = pgon->x0.x;
	sect->x2 = pgon->next->x0.x;
	sect->y2 = pgon->next->x0.y;
	sect->neg = ((sect->x1 - ray->pos.x) * (-ray->dir.y) -
				(sect->y1 - ray->pos.y) * (-ray->dir.x));
	sect->pos = ((sect->x2 - sect->x1) * (sect->y1 - ray->pos.y) -
				(sect->y2 - sect->y1) * (sect->x1 - ray->pos.x));
	if (sect->pos >= 0.0f && sect->pos <= 1.0f &&
		sect->neg >= 0.0f && sect->neg <= 1.0f)
		return ;
	sect->den = ((sect->x1 - sect->x2) * (-ray->dir.y) -
				(sect->y1 - sect->y2) * (-ray->dir.x));
	if (sect->den == 0)
		return ;
	sect->neg /= sect->den;
	sect->pos /= sect->den;
}

t_xy	line_intersection_raw(t_intersection *sect)
{
	t_xy point;

	if (sect->neg > 0 && sect->neg <= 1 && sect->pos > -1)
	{
		point.x = (sect->x1 + sect->neg * (sect->x2 - sect->x1));
		point.y = (sect->y1 + sect->neg * (sect->y2 - sect->y1));
		return (point);
	}
	return (vec2(-1, -1));
}

int		line_intersection_bool(t_intersection *sect)
{
	if (sect->neg > 0 && sect->neg <= 1 && sect->pos > -1)
		return (1);
	else
		return (0);
}

void	calc_intersection_raw(t_point *pgon, t_ray *ray, t_intersection *sect)
{
	sect->y1 = pgon->x0.y;
	sect->x1 = pgon->x0.x;
	sect->x2 = pgon->next->x0.x;
	sect->y2 = pgon->next->x0.y;
	sect->neg = ((sect->x1 - ray->pos.x) * (-ray->dir.y) -
				(sect->y1 - ray->pos.y) * (-ray->dir.x));
	sect->pos = ((sect->x2 - sect->x1) * (sect->y1 - ray->pos.y) -
				(sect->y2 - sect->y1) * (sect->x1 - ray->pos.x));
	sect->den = ((sect->x1 - sect->x2) * (-ray->dir.y) -
				(sect->y1 - sect->y2) * (-ray->dir.x));
	if (sect->den == 0)
		return ;
	sect->neg /= sect->den;
	sect->pos /= sect->den;
}
