/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 02:07:31 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/15 02:20:49 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	walk(t_init *init, t_wolf *wolf)
{
	if (init->nb % 10 == 1)
		system("afplay ./media/default2.mp3&");
	init->nb++;
	wolf->red = init->nb;

}
