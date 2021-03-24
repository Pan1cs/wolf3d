/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   porting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:22:10 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 16:32:08 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORTING_H
# define PORTING_H

/*
** Audio Encode/Decode funtions
*/



/*
** File creation, writing and reading functions
*/

# define WRITE_BREAKER "#"
# define READ_BREAKER '#'

int		create_map_file(t_home *home);
int		open_file(t_home *home, char *path);
int		open_map_file(t_home *home, char *path);

#endif
