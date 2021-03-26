/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:28:46 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/25 10:39:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		get_next_breaker(unsigned char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == READ_BREAKER)
			return (i);
		i++;
	}
	return (-1);
}

void	parse_sector_data(unsigned char *buf, t_home *home)
{
	unsigned int	pos;
	unsigned int	i;

	i = 0;
	pos = 0;
	if (!(buf = (unsigned char*)ft_strstr((const char*)buf, "wolf3d_sectors")))
		error_output("ERROR: No sector dataheader found");
	pos += get_next_breaker(buf + pos) + 1;
	home->nbr_of_sectors = ft_atoi((const char*)buf + pos);
	pos += ft_nb_len(home->nbr_of_sectors, 10);
	if (!(home->sectors = (t_sector**)malloc(sizeof(t_sector) *
		(home->nbr_of_sectors + 1))))
		error_output("ERROR: Failed to allocate memory for game sectors\n");
	while (i < home->nbr_of_sectors)
	{
		home->sectors[i] = get_sector_data(buf, &pos);
		i++;
	}
	home->sectors[i] = NULL;
}

int		load_map_file(t_home *home, char *path)
{
	int				fd;
	unsigned char	buf[BUF_SIZE + 1];
	unsigned int	size;

	if ((fd = OPEN_FILE(path, READ_ONLY)) < 0)
		error_output("ERROR: Failed to open map");
	else
	{
		size = READ_FILE(fd, buf, BUF_SIZE);
		if (size <= 0)
			error_output("ERROR: Failed to read map.");
		else if (size >= BUF_SIZE)
			error_output("ERROR: Map is too large.");
		if (CLOSE_FILE(fd) == -1)
			error_output("ERROR: Could not close the file.");
		buf[BUF_SIZE] = '\0';
		ft_putendl("Mapdata read to buffer, proceeding.");
		parse_sector_data(buf, home);
	}
	return (0);
}
