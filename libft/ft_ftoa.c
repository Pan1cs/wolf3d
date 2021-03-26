/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:40:50 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/26 13:40:58 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ftoa(float nb, int precision)
{
	char	*integer;
	// char	*decimals;
	// char	*total;

	ft_putstr(ft_itoa(precision));
	integer = ft_itoa((int)nb);
	return (integer);
}
