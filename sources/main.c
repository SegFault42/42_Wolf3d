/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 13:58:45 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"


void	close_window(t_sdl_win *win)
{
	SDL_DestroyRenderer(win->render);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
}

void	key_event(t_sdl_win *win, t_sdl_event *event)
{

}

int main(int argc, char **argv)
{
	t_sdl_win	win;
	SDL_Rect	rectangle;
	SDL_Event	event;
	t_init		init;
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
	win.width = 1280;
	win.height = 720;
	double	frame_time = (init.time - init.old_time) / 1000;
	double	move_speed = frame_time * 5.0;
	double	rot_speed = frame_time * 3.0;
	init_window("Wolf3d", win.width, win.height, &win);
	while (win.loop)
	{
		/*printf("dir_y = %f\n", init.dir_y);*/
		while(init.x < win.width)
		{
			init_map(&init);
			init.camera_x = 2 * init.x / (double)win.width - 1;
			if (init.ray_dir_x < 0)
			{
				init.etape_x = -1;
				init.dist_mur_x = (init.map_x - init.ray_pos_x) * init.dist2mur_x;
			}
			else
			{
				init.etape_x = 1;
				init.dist_mur_x = (init.map_x + 1.0 - init.ray_pos_x) * init.dist2mur_x;
			}
			if (init.ray_dir_y < 0)
			{
				init.etape_y = -1;
				init.dist_mur_y = (init.ray_pos_y - init.map_y) * init.dist2mur_y;
			}
			else
			{
				init.etape_y = 1;
				init.dist_mur_y = (init.map_y + 1.0 - init.ray_pos_y) * init.dist2mur_y;
			}
			while (init.touche == 0)
			{
				if (init.dist_mur_x < init.dist_mur_y)
				{
					init.dist_mur_x += init.dist2mur_x;
					init.map_x += init.etape_x;
					init.mur_ver_or_hor = 0;
				}
				else
				{
					init.dist_mur_y += init.dist2mur_y;
					init.map_y += init.etape_y;
					init.mur_ver_or_hor = 1;
				}
				if (world_map[init.map_x][init.map_y] > 0)
					init.touche = 1;
				if (init.mur_ver_or_hor == 0)
					init.longeur_mur = (init.map_x - init.ray_pos_x + (1 - init.etape_x) / 2) / init.ray_dir_x;
				else
					init.longeur_mur = (init.map_y - init.ray_pos_y + (1 - init.etape_y) / 2) / init.ray_dir_y;
				int	hauteur_mur = (int)(win.height / init.longeur_mur);
				int	draw_start = -hauteur_mur / 2 + win.height / 2;
				if (draw_start < 0)
					draw_start = 0;
				int	draw_end = hauteur_mur / 2 + win.height / 2;
				if (draw_end >= win.height)
					draw_end = win.height -1;
				unsigned char red;
				unsigned char green;
				unsigned char blue;
				switch (world_map[init.map_x][init.map_y])
				{
					case 1:
						red = 255;
						green = 0;
						blue = 0;
						SDL_SetRenderDrawColor(win.render, red, green, blue, 255);
						break;
					case 2:
						red = 0;
						green = 255;
						blue = 0;
						SDL_SetRenderDrawColor(win.render, red, green, blue, 255);
						break;
					case 3:
						red = 0;
						green = 0;
						blue = 255;
						SDL_SetRenderDrawColor(win.render, red, green, blue, 255);
						break;
					case 4:
						red = 255;
						green = 255;
						blue = 255;
						SDL_SetRenderDrawColor(win.render, red, green, blue, 255);
						break;
					default:
						red = 100;
						green = 100;
						blue = 100;
						SDL_SetRenderDrawColor(win.render, red, green, blue, 255);
						break;
				}
				if (init.mur_ver_or_hor == 1)
				{
					ft_debug();
					red /= 2;
					green /= 2;
					blue /= 2;
				}
					SDL_RenderDrawLine(win.render, init.x, draw_start, init.x, draw_end);
			}
			init.x++;
		}
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
					if (world_map[(int)(init.pos_x + init.dir_x *move_speed)][(int)init.pos_y] == 1)
						init.pos_x += init.dir_x * move_speed;
					if (world_map[(int)init.pos_x][(int)(init.pos_y + init.dir_y * move_speed)] == 1)
						init.pos_y += init.dir_y * move_speed;
				}
			}
		}
			SDL_RenderPresent(win.render);
	}
	close_window(&win);
	return (0);
}
