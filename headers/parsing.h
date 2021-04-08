/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:10:02 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/08 17:52:36 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_point		*new_point(t_xy x0, int idx);
void		add_point(t_point **point, t_point *new);
void		add_points(t_sector *sector, unsigned char *buf,
	unsigned int  **pos);
void		free_points(t_point **head, unsigned int nbr_of_walls);
void		free_sectors(t_home *home);
void		close_linkedlist(t_point **point);
t_sector	*get_sector_data(unsigned char *buf, unsigned int *pos);
void		calc_normal_vectors(t_home *home);
int			parse_xpm_data(unsigned char *buf, t_texture **tex);
int			parse_pixel_data(char *ptr, t_texture *tex);
char		*parse_colour_data(char *ptr, t_texture *tex);
#endif
