/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/18 17:14:46 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int	set_icon(t_win *win)
{
	win->icon = IMG_Load("./media/pics/icon.png");
	if (win->icon == NULL)
	{
		ft_putendl("Cannot load icon.png");
		return (EXIT_FAILURE);
	}
	SDL_SetWindowIcon(win->win, win->icon);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_win		win;
	t_wolf		wolf;
	t_init		init;
	SDL_Event	event;

	init_pos(&init);
	init_window("Wolf3d", init.width, init.height, &win);
	set_icon(&win);
	start(&win, &event);
	ambient();
	deagle(&win);
	/*init_joystick(&init);*/
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
		deagle(&win);
		SDL_RenderPresent(win.render);
		/*mouse(&event, &win, &init, &wolf);*/
	}
	close_window(&win);
	return (0);
}
