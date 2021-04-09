/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:38:48 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 08:11:53 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static t_pxl_c letter_logic(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (pxl_alphabet(c, black, white));
	if (c >= '0' && c <= '9')
		return (pxl_numbers(c, black, white));
	if (c == ':' || c == '\'' || c == '!' || c == '?' || c == ' '
		|| c == '.' || c == ',' || c == '(' || c == ')' || c == '%')
		return (pxl_numbers(c, black, white));
	return (pxl_numbers(' ', black, white));
}

static void	handle_letter(t_frame *frame, t_xy coord, int c)
{
	t_xy	cur;
	t_pxl_c	letter;
	t_xy	mod;
	int		m;

	cur.y = 0;
	m = TEXT_SIZE;
	letter = letter_logic(c);
	c = 0;
	while (cur.y < 7)
	{
		cur.x = 0;
		while (cur.x < 5)
		{
			c = letter.c[(int)(cur.x + cur.y * 5)];
			mod.x = cur.x * m + coord.x;
			mod.y = cur.y * m + coord.y;
			draw_rect(mod, vec2(TEXT_SIZE, TEXT_SIZE), frame, c);
			cur.x++;
		}
		cur.y++;
	}
}

void		str_pxl(t_frame *frame, t_xy coord, char *str)
{
	int		c;

	while (*str != '\0')
	{
		c = ft_toupper(*str);
		handle_letter(frame, coord, c);
		coord.x += 5 * TEXT_SIZE;
		str++;
	}
}
