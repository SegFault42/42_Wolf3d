/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/13 13:59:33 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int	init_window(char *win_name, int width, int height, t_sdl_win *win)
{
	win->loop = 1;
	SDL_Init(SDL_INIT_VIDEO);
	win->win = SDL_CreateWindow(win_name, 0, 0, width, height, SDL_WINDOW_OPENGL);
	if (win->win == NULL)
	{
		ft_putstr("Could not create window.");
		exit (1);
	}
	win->render = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_SOFTWARE);
	return (0);
}

void	init_pos(t_init *init)
{
	init->pos_x = 22;
	init->pos_y = 12;
	init->dir_x = -1;
	init->dir_y = 0;
	init->plane_x = 0;
	init->plane_y = 0.6;
	init->time = 0;
	init->old_time = 0;
}

void	init_map(t_init *init)
{
	init->ray_pos_x = init->pos_x;
	init->ray_pos_y = init->pos_y;
	init->ray_dir_x = init->dir_x + init->plane_x * init->camera_x;
	init->ray_dir_y = init->dir_y + init->plane_y * init->camera_x;
	init->map_x = (int)init->ray_pos_x;
	init->map_y = (int)init->ray_pos_y;
	init->dist2mur_x = sqrt(1 + (init->ray_dir_y * init->ray_dir_y) /
			(init->ray_dir_x * init->ray_dir_x));
	init->dist2mur_y = sqrt(1 + (init->ray_dir_x * init->ray_dir_x) /
			(init->ray_dir_y * init->ray_dir_y));
	init->touche = 0;
}

void	init_map_2(t_init *init)
{
}
