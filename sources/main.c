/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/11 16:23:31 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int main(int argc, char **argv)
{
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
	double	pos_x = 2;
	double	pos_y = 2;
	double	dir_x = -1;
	double	dir_y = 0;
	double	plane_x = 0;
	double	plane_y = 0.66;
	double	time = 0;
	double	ols_time = 0;
	int		loop = 1;
	int		w = 512;
	int		h = 384;

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		ft_putstr("Could not create window : ");
		ft_putendl(SDL_GetError());
		return (1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	while (loop)
	{
	SDL_Event	event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			loop = 0;
		if (event.type == SDL_KEYDOWN)
		{
			if (SDLK_ESCAPE)
				loop = 0;
		}
	}
		for (int x = 0; x < w; x++)
		{
			double	camera_x = 2 * x / (double)w - 1;
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
				dist_mur_x = (map_x + 1.0 - ray_pos_x) * dist2mur_x;
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
				dist_mur_y = (map_y = 1.0 - ray_pos_y) * dist2mur_y;
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
					mur_ver_or_hor = 0;
				}
				if (world_map[map_x][map_y] > 0)
					touche = 1;
				if (mur_ver_or_hor == 0)
					longeur_mur = fabs((map_x - ray_pos_x + (1 - etape_x) / 2) / ray_dir_x);
				else
					longeur_mur = fabs((map_y - ray_pos_y + (1 - etape_y) / 2) / ray_dir_y);
				int	hauteur_mur = abs((int)(h / longeur_mur));
				int	draw_start = -hauteur_mur / 2 + h / 2;
				if (draw_start < 0)
					draw_start = 0;
				int	draw_end = hauteur_mur / 2 + h / 2;
				if (draw_end >= h)
					draw_end = h -1;
				Uint8 color_r;
				Uint8 color_g;
				Uint8 color_b;
				switch (world_map[map_x][map_y])
				{
					case 1:
						SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
						break;
					case 2:
						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
						break;
					case 3:
						SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
						break;
					case 4:
						SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
						break;
					default:
						SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
						break;
				}
				if (mur_ver_or_hor == 1)
				{
					color_r /= 2;
					color_g /= 2;
					color_b /= 2;
				}
				/*SDL_RenderDrawPoint(renderer, 500, 500);*/
				/*SDL_RenderClear(renderer);*/
				SDL_RenderPresent(renderer);
				/*printf("start = %d, end = %d\n", draw_start, draw_end);*/
				/*if (draw_end < draw_start)*/
				/*{*/
					/*draw_start += draw_end;*/
					/*draw_end = draw_start - draw_end;*/
					/*draw_start -= draw_end;*/
				/*}*/
				/*if (draw_end < 0 || draw_start >= h  || x < 0 || x >= w)*/
					/*return 0;*/
				/*if (draw_start < 0)*/
					/*draw_start = 0;*/
				/*if (draw_end >= w)*/
					/*draw_end = h - 1;*/
				/*Uint32 colorSDL = SDL_MapRGB(scr->format, color_r, color_g, color_b);*/
				/*Uint32* bufp;*/
				/*bufp = (Uint32*)scr->pixels + draw_start * scr->pitch / 4 + x;*/
				/*for(int y = draw_start; y <= draw_end; y++)*/
				/*{*/
					/**bufp = colorSDL;*/
					/*bufp += scr->pitch / 4;*/
				/*}*/
			}
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}

