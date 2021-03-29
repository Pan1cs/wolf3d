/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:38:48 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 11:02:20 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void	draw_letter(t_frame *frame, int x, int y, int *letter)
{
	t_xy	cur;
	int		c;
	int		m;
	t_xy	mod;

	cur.y = 0;
	m = TEXT_SIZE;
	while (cur.y < 7)
	{
		cur.x = 0;
		while (cur.x < 5)
		{
			c = letter[(int)(cur.x + cur.y * 5)];
			mod.x = cur.x * m + x;
			mod.y = cur.y * m + y;
			draw_rect(mod, vec2(TEXT_SIZE,TEXT_SIZE), frame, c);
			cur.x++;
		}
		cur.y++;
	}
}

static void	handle_letter(t_frame *frame, int **tab, t_xy coord, int c)
{
	t_pxl_c	letter;
	int		i;

	i = 0;
	if (c >= 'A' && c <= 'Z')
		letter = pxl_alphabet(c, black, white);
	if (c >= '0' && c <= '9')
		letter = pxl_numbers(c, black, white);
	if (c == ':' || c == '\'' || c == '!' || c == '?' || c == ' '
		|| c == '.' || c == ',' || c == '(' || c == ')' || c == '%')
		letter = pxl_numbers(c, black, white);
	while (i < 36)
	{
		*(*(tab) + i) = letter.c[i];
		i++;
	}
	draw_letter(frame, coord.x, coord.y, *tab);
}

void		str_pxl(t_frame *frame, t_xy coord, char *str)
{
	int		c;
	int		*letter;

	letter = (int*)malloc(sizeof(*letter) * 36);
	while (*str != '\0')
	{
		c = ft_toupper(*str);
		handle_letter(frame, &letter, coord, c);
		coord.x += 5 * TEXT_SIZE;
		str++;
	}
	ft_memdel((void*)&letter);
}
