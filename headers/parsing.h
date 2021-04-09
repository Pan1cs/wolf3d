/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:10:02 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 12:26:28 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void		add_point(t_point **point, t_point *new);
void		add_points(t_sector *sector, unsigned char *buf,
	unsigned int **pos);
void		calc_normal_vectors(t_home *home);
void		close_linkedlist(t_point **point);
void		free_points(t_point **head, unsigned int nbr_of_walls);
void		free_sectors(t_home *home);
t_sector	*get_sector_data(unsigned char *buf, unsigned int *pos);
t_point		*new_point(t_xy x0, int idx);
char		*parse_colour_data(char *ptr, t_texture *tex);
int			parse_pixel_data(char *ptr, t_texture *tex);
int			parse_xpm_data(unsigned char *buf, t_texture **tex);
#endif
