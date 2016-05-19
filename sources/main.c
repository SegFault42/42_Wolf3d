/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/19 17:29:40 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		set_icon(t_win *win)
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

int		check_arg(int argc)
{
	if (argc != 1)
	{
		ft_putendl("Usage : No argument needed.");
		exit(1);
	}
	else
	{
		ft_putendl("\033[32m**********************\033[0m");
		ft_putendl("\033[32m* Wolf3d by Rabougue *\033[0m");
		ft_putendl("\033[32m**********************\033[0m");
		ft_putendl("\033[32m* Move forward = W   *\033[0m");
		ft_putendl("\033[32m* Move backward = S  *\033[0m");
		ft_putendl("\033[32m* Rotate left = A    *\033[0m");
		ft_putendl("\033[32m* Rotate right = D   *\033[0m");
		ft_putendl("\033[32m* Fire = click left  *\033[0m");
		ft_putendl("\033[32m*     Reload = R     *\033[0m");
		ft_putendl("\033[32m*      AK 47 = 1     *\033[0m");
		ft_putendl("\033[32m*     Deagle = 2     *\033[0m");
		ft_putendl("\033[32m*     Quit = Esc     *\033[0m");
		ft_putendl("\033[32m**********************\033[0m");
	}
	return (0);
}

void	split_main(t_init *init, t_wolf *wolf, t_win *win)
{
	while (init->x < init->width)
	{
		init_env(wolf, init);
		calc_step(wolf);
		while (wolf->hit == 0)
		{
			dda(wolf);
			calc_ray(wolf, init);
			color(wolf);
			render(wolf, win, init);
		}
		init->x++;
	}
}

int		main(int argc, char **argv)
{
	t_win		win;
	t_wolf		wolf;
	t_init		init;
	SDL_Event	event;

	check_arg(argc);
	init_pos(&init);
	init_window("Wolf3d", init.width, init.height, &win);
	set_icon(&win);
	start(&win, &event);
	ambient();
	while (win.loop)
	{
		init.x = 0;
		keyboard(&event, &win, &init, &wolf);
		SDL_RenderPresent(win.render);
		split_main(&init, &wolf, &win);
		printf("loop = %d\n", win.loop);
	}
	close_window(&win);
	(void)argv;
	return (0);
}
