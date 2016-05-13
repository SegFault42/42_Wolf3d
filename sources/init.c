/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/14 00:22:53 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int	init_window(char *win_name, int width, int height, t_sdl_win *win)
{
	win->loop = 1;
	SDL_Init(SDL_INIT_VIDEO);
	win->win = SDL_CreateWindow(win_name, 0, 0, width, height,
			SDL_WINDOW_SHOWN);
	if (win->win == NULL)
	{
		ft_putstr("Could not create window.");
		exit (1);
	}
	win->render = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_SOFTWARE);
	return (0);
}

