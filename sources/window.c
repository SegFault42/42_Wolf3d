/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/19 12:27:17 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		init_window(char *win_name, int width, int height, t_win *win)
{
	win->loop = 1;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		ft_putendl("Failed to init SDL Video.");
		return (EXIT_FAILURE);
	}
	win->win = SDL_CreateWindow(win_name, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	if (win->win == NULL)
	{
		ft_putstr("Could not create window : ");
		ft_putendl(SDL_GetError());
		exit(1);
	}
	win->render = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_SOFTWARE);
	return (0);
}

void	close_window(t_win *win)
{
	SDL_DestroyRenderer(win->render);
	SDL_DestroyWindow(win->win);
	system("killall afplay");
	SDL_Quit();
}

void	sdl_clear(t_win *win)
{
	SDL_SetRenderDrawColor(win->render, 0, 0, 0, 0);
	SDL_RenderClear(win->render);
	SDL_RenderPresent(win->render);
}
