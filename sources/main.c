/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/16 15:20:04 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int		world_map(int x, int y)
{
	static int	world_map[MAPWIDTH][MAPHEIGHT] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 0, 2, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	return (world_map[x][y]);
}

/*
** srcrect.x = rognage de l'image x
** srcrect.y = rognage de l'image y
** dstrect.x = position x de l'image.
** dstrect.y = position y de l'image.
*/

void	load_media(t_win *win, SDL_Event *event)
{
	int loop = 1;

	while (loop)
	{
	win->srcrect.x = 0;
	win->srcrect.y = 0;
	win->srcrect.w = 800;
	win->srcrect.h = 600;
	win->dstrect.x = 0;
	win->dstrect.y = 0;
	win->dstrect.w = 32;
	win->dstrect.h = 32;
	win->g_screen_surface = SDL_GetWindowSurface(win->win);
	win->hand = SDL_LoadBMP("./media/Wolf3DTitleScreen.bmp");
	if (win->hand == NULL)
		ft_putendl("Failed to open .png file");
	SDL_BlitSurface(win->hand, &win->srcrect, win->g_screen_surface, &win->dstrect);
	SDL_RenderPresent(win->render);
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT)
			exit(1);
		if (SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_ESCAPE)
				exit(1);
			else if (event->key.keysym.sym ==SDLK_SPACE)
				loop = 0;
		}
	}
}
}

int main(int argc, char **argv)
{
	t_win		win;
	t_wolf		wolf;
	t_init		init;
	SDL_Event	event;

	init_pos(&init);
	init_window("Wolf3d", init.width, init.height, &win);
	load_media(&win, &event);
	ambient();
	while (win.loop)
	{
		while(init.x < init.width)
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
		/*mouse(&event, &win, &init, &wolf);*/
		SDL_RenderPresent(win.render);
	}
	close_window(&win);
	return (0);
}
