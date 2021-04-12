/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:28:46 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/12 14:35:01 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int			get_next_breaker(unsigned char *buf)
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

void		free_sectors_and_exit(int error_code, t_home *home, size_t n)
{
	if (error_code == 1)
	{
		free_sectors_n(home, n);
		ft_putendl_fd("ERROR: Memory allocation for a sector failed.", 2);
	}
	else if (error_code == 2)
	{
		free_sectors(home);
		ft_putendl_fd("ERROR: Still data in buffer after reading.", 2);
	}
	exit(0);
}

void		parse_sector_data(unsigned char *buf, t_home *home)
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
		if (home->sectors[i] == NULL)
			free_sectors_and_exit(1, home, i + 1);
		i++;
	}
	if (*(buf + pos) != '\0')
		free_sectors_and_exit(2, home, home->nbr_of_sectors);
	home->sectors[i] = NULL;
}

int			load_map_file(t_home *home, char *path)
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
		buf[size] = '\0';
		ft_putendl("Mapdata read to buffer, proceeding.");
		parse_sector_data(buf, home);
		validate_sectors_data(home);
		calc_normal_vectors(home);
	}
	return (0);
}

int			load_xpm_file(t_texture **tex, char *path)
{
	int				fd;
	unsigned char	buf[XPM_BUF_SIZE + 1];
	unsigned int	size;
	char			*ptr;

	ptr = ft_strstr(path, ".xpm");
	if (!ptr || *(ptr + 4) != '\0')
		error_output("ERROR: Not a correct extension");
	if ((fd = OPEN_FILE(path, READ_ONLY)) < 0)
		error_output("ERROR: Failed to open map");
	else
	{
		size = READ_FILE(fd, buf, XPM_BUF_SIZE);
		if (size <= 0)
			error_output("ERROR: Failed to read bitmap.");
		else if (size >= XPM_BUF_SIZE)
			error_output("ERROR: Bitmap is too large.");
		if (CLOSE_FILE(fd) == -1)
			error_output("ERROR: Could not close the file.");
		buf[size] = '\0';
		ft_putstr(path);
		ft_putendl(" read to the buffer, proceeding.");
		parse_xpm_data(buf, tex);
	}
	return (0);
}
