/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/16 18:50:42 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int	main(int argc, char **argv)
{
	t_win		win;
	t_wolf		wolf;
	t_init		init;
	SDL_Event	event;

	init_pos(&init);
	init_window("Wolf3d", init.width, init.height, &win);
	start(&win, &event);
	ambient();
	while (win.loop)
	{
		while (init.x < init.width)
		{
			init_env(&wolf, &init);
			calc_step(&wolf);
			while (wolf.hit == 0)
			{
				dda(&wolf);
				calc_ray(&wolf, &init);
				color(&wolf);
				render(&wolf, &win, &init);
			}
			init.x++;
		}
		init.x = 0;
		keyboard(&event, &win, &init, &wolf);
		SDL_RenderPresent(win.render);
	}
	close_window(&win);
	return (0);
}
