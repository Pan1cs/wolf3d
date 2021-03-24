/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:59:45 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 14:59:52 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct		s_map
{
	int			num_sectors;
	char		*img_buf;
	char		*audio_buf;
	char		*map_buf[1024];
}					t_map;

#endif
