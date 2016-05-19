/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 02:07:31 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/19 12:27:10 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	walk(t_init *init, t_wolf *wolf)
{
	if (init->nb % 20 == 2)
		system("afplay ./media/sound/walk_wood_1.mp3&");
	else if (init->nb % 10 == 2)
		system("afplay ./media/sound/walk_wood_2.mp3&");
	init->nb++;
	wolf->red = init->nb;
}

void	ambient(void)
{
	system("afplay ./media/sound/ambient.mp3&");
}
