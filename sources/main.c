/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/13 19:37:18 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

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

void	dda(t_init *init, t_sdl_win *win)
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
	if (world_map[init->map_x][init->map_y] > 0)
		init->touche = 1;
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

void	close_window(t_sdl_win *win)
{
	SDL_DestroyRenderer(win->render);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
}


void	draw(t_init *init, t_sdl_win *win)
{
	while(init->x < win->width)
	{
		init_map(init);
		init->camera_x = 2 * init->x / (double)win->width - 1;
		calc_dir(init);
		while (init->touche == 0)
		{
			dda(init, win);
			if (world_map[init->map_x][init->map_y] == 1)
			{
				init->red = 255;
				init->green = 0;
				init->blue = 0;
				init->alpha = 255;
			}
			else if (world_map[init->map_x][init->map_y] == 2)
			{
				init->red = 0;
				init->green = 255;
				init->blue = 0;
				init->alpha = 255;
			}
			else if (world_map[init->map_x][init->map_y] == 3)
			{
				init->red = 0;
				init->green = 0;
				init->blue = 255;
				init->alpha = 255;
			}
			else if (world_map[init->map_x][init->map_y] == 4)
			{
				init->red = 255;
				init->green = 255;
				init->blue = 255;
				init->alpha = 255;
			}
			else
			{
				init->red = 0;
				init->green = 0;
				init->blue = 0;
				init->alpha = 255;
			}
			/*if (init->touche == 1)*/
			/*{*/
				/*init->red /= 2;*/
				/*init->green /= 2;*/
				/*init->blue /= 2;*/
			/*}*/
				SDL_SetRenderDrawColor(win->render, init->red, init->green, init->blue, 255);
				SDL_RenderDrawLine(win->render, init->x, init->draw_start, init->x, init->draw_end);
		}
		init->x++;
	}
	init->x = 0;
	init->move_speed = 1;
	init->rot_speed = 0.05;
}

void	sdl_clear(t_sdl_win *win)
{
	SDL_SetRenderDrawColor(win->render, 0, 0, 0, 0);
	SDL_RenderClear(win->render);
	SDL_RenderPresent(win->render);
}

void	move(t_sdl_win *win, t_init *init, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_w)
	{
		draw(init, win);
		if (world_map[(int)(init->pos_x + init->dir_x * init->move_speed)][(int)init->pos_y] == 0)
			init->pos_x += init->dir_x * init->move_speed;
	if (world_map[(int)init->pos_x][(int)(init->pos_y + init->dir_y * init->move_speed)] == 0)
		init->pos_y += init->dir_y * init->move_speed;
		SDL_RenderPresent(win->render);
	}
	if (event->key.keysym.sym == SDLK_s)
	{
		draw(init, win);
		if (world_map[(int)(init->pos_x - init->dir_x * init->move_speed)][(int)init->pos_y] == 0)
			init->pos_x -= init->dir_x * init->move_speed;
		if (world_map[(int)init->pos_x][(int)(init->pos_y - init->dir_y * init->move_speed)] == 0)
			init->pos_y -= init->dir_y * init->move_speed;
		SDL_RenderPresent(win->render);
	}
}

void	rotation(t_sdl_win *win, t_init *init, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_d)
	{
		draw(init, win);
		double old_dir_x = init->dir_x;
		init->dir_x = init->dir_x * cos(-init->rot_speed) - init->dir_y * sin(-init->rot_speed);
		init->dir_y = old_dir_x * sin(-init->rot_speed) + init->dir_y * cos(-init->rot_speed);
		double old_plane_x = init->plane_x;
		init->plane_x = init->plane_x * cos(-init->rot_speed) - init->plane_y *sin(-init->rot_speed);
		init->plane_y = old_plane_x * sin(-init->rot_speed) + init->plane_y * cos(-init->rot_speed);
		SDL_RenderPresent(win->render);
	}
	if (event->key.keysym.sym == SDLK_a)
	{
		draw(init, win);
		double old_dir_x = init->dir_x;
		init->dir_x = init->dir_x * cos(init->rot_speed) - init->dir_y * sin(init->rot_speed);
		init->dir_y = old_dir_x * sin(init->rot_speed) + init->dir_y * cos(init->rot_speed);
		double old_plane_x = init->plane_x;
		init->plane_x = init->plane_x * cos(init->rot_speed) - init->plane_y *sin(init->rot_speed);
		init->plane_y = old_plane_x * sin(init->rot_speed) + init->plane_y * cos(init->rot_speed);
		SDL_RenderPresent(win->render);
	}
}

void	keyboard(t_sdl_win *win, t_init *init)
{
	SDL_Event	event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			win->loop = 0;
		if (SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				win->loop = 0;
			move(win, init, &event);
			rotation(win, init, &event);
		}
	}
}

int main(int argc, char **argv)
{
	t_sdl_win	win;
	SDL_Rect	rectangle;
	t_init		init;

	win.width = 1280;
	win.height = 720;
	init_window("Wolf3d", win.width, win.height, &win);
	init_pos(&init);
	while (win.loop)
	{
		draw(&init, &win);
		keyboard(&win, &init);
		SDL_RenderPresent(win.render);
	}
	close_window(&win);
	return (0);
}
