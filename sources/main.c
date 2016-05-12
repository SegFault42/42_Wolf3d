/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 19:28:39 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"


void	close_window(t_sdl_win *win)
{
	SDL_DestroyRenderer(win->render);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
}

void	calc_dir(t_init *init)
{
	if (init->ray_dir_x < 0)
	{
		init->etape_x = -1;
		init->dist_mur_x = (init->map_x - init->ray_pos_x) * init->dist2mur_x;
	}
	else
	{
		init->etape_x = 1;
		init->dist_mur_x = (init->map_x + 1.0 - init->ray_pos_x) * init->dist2mur_x;
	}
	if (init->ray_dir_y < 0)
	{
		init->etape_y = -1;
		init->dist_mur_y = (init->ray_pos_y - init->map_y) * init->dist2mur_y;
	}
	else
	{
		init->etape_y = 1;
		init->dist_mur_y = (init->map_y + 1.0 - init->ray_pos_y) * init->dist2mur_y;
	}
}

void	dda_1(t_init *init, t_sdl_win *win)
{
	if (init->dist_mur_x < init->dist_mur_y)
	{
		init->dist_mur_x += init->dist2mur_x;
		init->map_x += init->etape_x;
		init->mur_ver_or_hor = 0;
	}
	else
	{
		init->dist_mur_y += init->dist2mur_y;
		init->map_y += init->etape_y;
		init->mur_ver_or_hor = 1;
	}
}

void	dda_2(t_init *init, t_sdl_win *win)
{
	if (init->mur_ver_or_hor == 0)
		init->longeur_mur = (init->map_x - init->ray_pos_x + (1 - init->etape_x) / 2) / init->ray_dir_x;
	else
		init->longeur_mur = (init->map_y - init->ray_pos_y + (1 - init->etape_y) / 2) / init->ray_dir_y;
	init->hauteur_mur = (int)(win->height / init->longeur_mur);
	init->draw_start = -init->hauteur_mur / 2 + win->height / 2;
	if (init->draw_start < 0)
		init->draw_start = 0;
	init->draw_end = init->hauteur_mur / 2 + win->height / 2;
	if (init->draw_end >= win->height)
		init->draw_end = win->height -1;
}

void	draw(t_init *init, t_sdl_win *win)
{
	int world_map[MAPWIDTH][MAPHEIGHT] =
		{
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
			{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
			{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};
	while(init->x < win->width)
	{
		init_map(init);
		init->camera_x = 2 * init->x / (double)win->width - 1;
		calc_dir(init);
		while (init->touche == 0)
		{
			dda_1(init, win);
			if (world_map[init->map_x][init->map_y] > 0)
				init->touche = 1;
			dda_2(init, win);
			if (world_map[init->map_x][init->map_y] == 1)
				{
					init->red = 255;
					init->green = 0;
					init->blue = 0;
					SDL_SetRenderDrawColor(win->render, init->red, init->green, init->blue, 255);
				}
				else if (world_map[init->map_x][init->map_y] == 2)
				{
					init->red = 0;
					init->green = 255;
					init->blue = 0;
					SDL_SetRenderDrawColor(win->render, init->red, init->green, init->blue, 255);
				}
				else if (world_map[init->map_x][init->map_y] == 3)
				{
					init->red = 0;
					init->green = 0;
					init->blue = 255;
					SDL_SetRenderDrawColor(win->render, init->red, init->green, init->blue, 255);
				}
				else if (world_map[init->map_x][init->map_y] == 4)
				{
					init->red = 255;
					init->green = 255;
					init->blue = 255;
					SDL_SetRenderDrawColor(win->render, init->red, init->green, init->blue, 255);
				}
				else
				{
					init->red = 100;
					init->green = 100;
					init->blue = 100;
					SDL_SetRenderDrawColor(win->render, init->red, init->green, init->blue, 255);
				}
					SDL_RenderDrawLine(win->render, init->x, init->draw_start, init->x, init->draw_end);
					/*SDL_RenderDrawPoint(win.render, init.x, draw_start);*/
					/*SDL_RenderDrawPoint(win.render, init.x, draw_end);*/
			}
		init->x++;
	}
}

int main(int argc, char **argv)
{
	t_sdl_win	win;
	SDL_Rect	rectangle;
	SDL_Event	event;
	t_init		init;
	win.width = 1280;
	win.height = 720;
	init_window("Wolf3d", win.width, win.height, &win);
	while (win.loop)
	{
		draw(&init, &win);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				win.loop = 0;
			if (SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					win.loop = 0;
				if (event.key.keysym.sym == SDLK_UP)
				{
				}
			}
		}
		SDL_RenderPresent(win.render);
		SDL_RenderClear(win.render);
	}
	close_window(&win);
	return (0);
}
