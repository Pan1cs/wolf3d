/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:04:06 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/21 10:05:43 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}