/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/11 18:10:59 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int	init_window(char *win_name, t_sdl_win *win)
{
	win->loop = 1;
	SDL_Init(SDL_INIT_VIDEO);
	win->win = SDL_CreateWindow(win_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL);
	if (win->win == NULL)
	{
		ft_putstr("Could not create window : ");
		ft_putendl(SDL_GetError());
		return (1);
	}
	win->renderer = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_SOFTWARE);
	return (0);
}

void	close_window(t_sdl_win *win)
{
	SDL_DestroyWindow(win->win);
	SDL_Quit();
}

int main(int argc, char **argv)
{
	t_sdl_win win;

	init_window("Wolf3d", &win);
	while (win.loop)
	{
		SDL_Event	event;
		SDL_SetRenderDrawColor(win.renderer, 100, 250, 0, 255);
		SDL_Rect	rectangle;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				win.loop = 0;
			else if (event.key.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					win.loop = 0;
				else if (event.key.keysym.sym == SDLK_UP)
					rectangle.y--;
			}
		}
		rectangle.x = 500;
		rectangle.y = 500;
		rectangle.w = 50;
		rectangle.h = 50;

		SDL_RenderFillRect(win.renderer, &rectangle);
		SDL_RenderPresent(win.renderer);
		SDL_SetRenderDrawColor(win.renderer, 0, 0, 0, 255);
		SDL_RenderPresent(win.renderer);
	}
	close_window(&win);
	return (0);
}

