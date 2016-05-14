/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/14 12:24:10 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int		world_map(int x, int y)
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
	return (world_map[x][y]);
}

int main(int argc, char **argv)
{
	t_win		win;
	t_wolf		wolf;
	t_init		init;
	SDL_Event	event;

	init_pos(&init);
	init_window("Wolf3d", init.width, init.height, &win);
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
				unsigned char	red;
				unsigned char	green;
				unsigned char	blue;
				unsigned char	alpha;
				if (world_map((wolf.map_x), (wolf.map_y)) == 1)
				{
					red = 255;
					green = 0;
					blue = 0;
					alpha = 255;
				}
				else if (world_map((wolf.map_x), (wolf.map_y)) == 2)
				{
					red = 0;
					green = 255;
					blue = 0;
					alpha = 255;
				}
				else if (world_map((wolf.map_x), (wolf.map_y)) == 3)
				{
					red = 0;
					green = 0;
					blue = 255;
					alpha = 255;
				}
				else if (world_map((wolf.map_x), (wolf.map_y)) == 4)
				{
					red = 255;
					green = 255;
					blue = 255;
					alpha = 255;
				}
				else
				{
					red = 0;
					green = 0;
					blue = 0;
					alpha = 255;
				}
				if (wolf.side == 1)
				{
					red /= 2;
					green /= 2;
					blue /= 2;
				}
				SDL_SetRenderDrawColor(win.render, red, green, blue, 255);
				SDL_RenderDrawLine(win.render, init.x, wolf.draw_start, init.x, wolf.draw_end);
			}
			init.x++;
		}
		init.x = 0;
		double	move_speed = 0.2;
		double	rot_speed = 0.1;
		double old_dir_x;
		double old_plane_x;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				win.loop = 0;
			if (SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					win.loop = 0;
				if (event.key.keysym.sym == SDLK_w)
				{
					if (world_map((int)(init.pos_x + init.dir_x * move_speed), (int)init.pos_y) == 0)
						init.pos_x += init.dir_x * move_speed;
					if (world_map((int)init.pos_x, ((int)(init.pos_y + init.dir_y * move_speed))) == 0)
						init.pos_y += init.dir_y * move_speed;
				}
				if (event.key.keysym.sym == SDLK_s)
				{
					if (world_map((int)(init.pos_x - init.dir_x * move_speed), (int)init.pos_y) == 0)
						init.pos_x -= init.dir_x * move_speed;
					if (world_map((int)init.pos_x, ((int)(init.pos_y - init.dir_y * move_speed))) == 0)
						init.pos_y -= init.dir_y * move_speed;
				}
				old_dir_x = init.dir_x;
				old_plane_x = init.plane_x;
				if (event.key.keysym.sym == SDLK_d)
				{
					init.dir_x = init.dir_x * cos(-rot_speed) - init.dir_y * sin(-rot_speed);
					init.dir_y = old_dir_x * sin(-rot_speed) + init.dir_y * cos(-rot_speed);
					init.plane_x = init.plane_x * cos(-rot_speed) - init.plane_y *sin(-rot_speed);
					init.plane_y = old_plane_x * sin(-rot_speed) + init.plane_y * cos(-rot_speed);
				}
				if (event.key.keysym.sym == SDLK_a)
				{
					init.dir_x = init.dir_x * cos(rot_speed) - init.dir_y * sin(rot_speed);
					init.dir_y = old_dir_x * sin(rot_speed) + init.dir_y * cos(rot_speed);
					init.plane_x = init.plane_x * cos(rot_speed) - init.plane_y *sin(rot_speed);
					init.plane_y = old_plane_x * sin(rot_speed) + init.plane_y * cos(rot_speed);
				}
			}
		}
		SDL_RenderPresent(win.render);
	}
	close_window(&win);
	return (0);
}
