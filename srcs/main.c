/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:06:28 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/24 08:28:10 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int  			main(int argc, char **argv)
{
	if (argc == 1)
	 	error_output("usage: ./play [map file name]\n");
	else
	{
		ft_putendl("Great work!");
		ft_putendl(argv[1]);
	}
	return 0;
}
