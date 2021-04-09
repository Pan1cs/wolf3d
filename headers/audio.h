/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:35:03 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 11:06:59 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AUDIO_H
# define AUDIO_H

typedef struct	s_audio
{
	Mix_Music	*music;
	Mix_Chunk	*footstep1;
	Mix_Chunk	*footstep2;
}				t_audio;

void			load_audio(t_audio *audio);
void			cleanup_audio(t_audio *audio);
#endif
