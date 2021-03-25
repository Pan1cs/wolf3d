/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:28:46 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/25 09:28:41 by jnivala          ###   ########.fr       */
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
	if (!(home->sectors = (t_sector**)malloc(sizeof(t_sector*) *
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
	unsigned char	*buf;
	unsigned int	size;

	if ((fd = OPEN_FILE(path, READ_ONLY)) < 0)
		error_output("Failed to open file\n");
	else
	{
		if (!(buf = (unsigned char *)malloc(sizeof(unsigned char) * BUF_SIZE + 1)))
			error_output("Memory allocation of source buffer failed\n");
		size = READ_FILE(fd, buf, BUF_SIZE);
		if (size <= 0)
			error_output("Failed to read file\n");
		else if (size >= BUF_SIZE)
			error_output("File is too large\n");
		if (CLOSE_FILE(fd) == -1)
			error_output("Could not close file\n");
		buf[BUF_SIZE] = '\0';
		parse_sector_data(buf, home);
		free(buf);
	}
	return (0);
}
