/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 00:02:41 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int	init_window(char *win_name, int width, int height, t_sdl_win *win)
{
	win->loop = 1;
	SDL_Init(SDL_INIT_VIDEO);
	win->win = SDL_CreateWindow(win_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	if (win->win == NULL)
	{
		ft_putstr("Could not create window.");
		exit (1);
	}
	win->render = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_SOFTWARE);
	return (0);
}

void	close_window(t_sdl_win *win)
{
	SDL_DestroyRenderer(win->render);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
}

int main(int argc, char **argv)
{
	t_sdl_win	win;
	SDL_Rect	rectangle;
	SDL_Event	event;
	int world_map[MAPWIDTH][MAPHEIGHT]=
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

	win.width = 800;
	win.height = 600;
	double	pos_x = 22;
	double	pos_y = 12;
	double	dir_x = -1;
	double	dir_y = 0;
	double	plane_x = 0;
	double	plane_y = 0.66;
	double	time = 0;
	double	ols_time = 0;
	init_window("Wolf3d", win.width, win.height, &win);
	while (win.loop)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				win.loop = 0;
		}
		for (int x = 0; x < win.width; x++)
		{
			double	camera_x = 2 * x / (double)win.width - 1;
			double	ray_pos_x = pos_x;
			double	ray_pos_y = pos_y;
			double	ray_dir_x = dir_x + plane_x * camera_x;
			double	ray_dir_y = dir_y + plane_y * camera_x;
			int		map_x = (int)ray_pos_x;
			int		map_y = (int)ray_pos_y;
			double	dist_mur_x;
			double	dist_mur_y;
			double	dist2mur_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
			double	dist2mur_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
			double	longeur_mur;
			int		etape_x;
			int		etape_y;
			int		touche = 0;
			int		mur_ver_or_hor;
			if (ray_dir_x < 0)
			{
				etape_x = -1;
				dist_mur_x = (map_x - ray_pos_x) * dist2mur_x;
			}
			else
			{
				etape_x = 1;
				dist_mur_x = (map_x + 1.0 - ray_pos_x) * dist2mur_x;
			}
			if (ray_dir_y < 0)
			{
				etape_y = -1;
				dist_mur_y = (ray_pos_y - map_y) * dist2mur_y;
			}
			else
			{
				etape_y = 1;
				dist_mur_y = (map_y + 1.0 - ray_pos_y) * dist2mur_y;
			}
			while (touche == 0)
			{
				if (dist_mur_x < dist_mur_y)
				{
					dist_mur_x += dist2mur_x;
					map_x += etape_x;
					mur_ver_or_hor = 0;
				}
				else
				{
					dist_mur_y += dist2mur_y;
					map_y += etape_y;
					mur_ver_or_hor = 1;
				}
				if (world_map[map_x][map_y] > 0)
					touche = 1;
				if (mur_ver_or_hor == 0)
					longeur_mur = fabs((map_x - ray_pos_x + (1 - etape_x) / 2) / ray_dir_x);
				else
					longeur_mur = fabs((map_y - ray_pos_y + (1 - etape_y) / 2) / ray_dir_y);
				int	hauteur_mur = abs((int)(win.height / longeur_mur));
				int	draw_start = -hauteur_mur / 2 + win.height / 2;
				if (draw_start < 0)
					draw_start = 0;
				int	draw_end = hauteur_mur / 2 + win.height / 2;
				if (draw_end >= win.height)
					draw_end = win.height -1;
				/*Uint8 color_r;*/
				/*Uint8 color_g;*/
				/*Uint8 color_b;*/
				/*unsigned char red = 255;*/
				/*unsigned char green = 255;*/
				/*unsigned char blue = 255;*/
				/*unsigned char red = 255;*/
				switch (world_map[map_x][map_y])
				{
					case 1:
						SDL_SetRenderDrawColor(win.render, 255, 0, 0, 255);
						break;
					case 2:
						SDL_SetRenderDrawColor(win.render, 0, 255, 0, 255);
						break;
					case 3:
						SDL_SetRenderDrawColor(win.render, 0, 0, 255, 255);
						break;
					case 4:
						SDL_SetRenderDrawColor(win.render, 255, 255, 255, 255);
						break;
					default:
						SDL_SetRenderDrawColor(win.render, 255, 255, 0, 255);
						break;
				}
				/*if (mur_ver_or_hor == 1)*/
				/*{*/
					/*color /= 2;*/
				/*}*/
					SDL_RenderDrawLine(win.render, x, draw_start, x, draw_end);
					SDL_RenderPresent(win.render);
			}
		}
	}
	SDL_RenderFillRect(win.render, &rectangle);
	SDL_RenderPresent(win.render);
	close_window(&win);
	return (0);
}
