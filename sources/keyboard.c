/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 14:58:09 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/19 17:47:28 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	move_w_s(SDL_Event *event, t_init *init, t_wolf *wolf)
{
	if (event->key.keysym.sym == SDLK_w)
	{
		if (world_map((int)(init->pos_x + init->dir_x * init->move_speed),
					(int)init->pos_y) == 0)
			init->pos_x += init->dir_x * init->move_speed;
		if (world_map((int)init->pos_x, ((int)(init->pos_y + init->dir_y *
							init->move_speed))) == 0)
			init->pos_y += init->dir_y * init->move_speed;
		walk(init, wolf);
	}
	if (event->key.keysym.sym == SDLK_s)
	{
		if (world_map((int)(init->pos_x - init->dir_x * init->move_speed),
					(int)init->pos_y) == 0)
			init->pos_x -= init->dir_x * init->move_speed;
		if (world_map((int)init->pos_x, ((int)(init->pos_y - init->dir_y *
							init->move_speed))) == 0)
			init->pos_y -= init->dir_y * init->move_speed;
		walk(init, wolf);
	}
}

void	move_a_d(SDL_Event *event, t_init *init)
{
	if (event->key.keysym.sym == SDLK_d)
	{
		init->dir_x = init->dir_x * cos(-init->rot_speed) - init->dir_y *
			sin(-init->rot_speed);
		init->dir_y = init->old_dir_x * sin(-init->rot_speed) + init->dir_y *
			cos(-init->rot_speed);
		init->plane_x = init->plane_x * cos(-init->rot_speed) - init->plane_y *
			sin(-init->rot_speed);
		init->plane_y = init->old_plane_x * sin(-init->rot_speed) +
			init->plane_y * cos(-init->rot_speed);
	}
	if (event->key.keysym.sym == SDLK_a)
	{
		init->dir_x = init->dir_x * cos(init->rot_speed) - init->dir_y *
			sin(init->rot_speed);
		init->dir_y = init->old_dir_x * sin(init->rot_speed) + init->dir_y *
			cos(init->rot_speed);
		init->plane_x = init->plane_x * cos(init->rot_speed) - init->plane_y *
			sin(init->rot_speed);
		init->plane_y = init->old_plane_x * sin(init->rot_speed) +
			init->plane_y * cos(init->rot_speed);
	}
}

void	keyboard(SDL_Event *event, t_win *win, t_init *init, t_wolf *wolf)
{
	while (SDL_PollEvent(event))
	{
		if (event->type == SDL_QUIT)
			win->loop = 0;
		if (event->key.type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_ESCAPE)
				win->loop = 0;
			init->old_dir_x = init->dir_x;
			init->old_plane_x = init->plane_x;
			move_w_s(event, init, wolf);
			move_a_d(event, init);
		}
		sound_deagle(event, init, win);
	}
	deagle(init, win, event);
}

void	start(t_win *win, SDL_Event *event)
{
	int	loop;

	loop = 1;
	while (loop)
	{
		init_title_screen(win);
		win->g_screen_surface = SDL_GetWindowSurface(win->win);
		win->title_screen = SDL_LoadBMP("./media/pics/Wolf3DTitleScreen.bmp");
		if (win->title_screen == NULL)
			ft_putendl("Failed to open .bmp file");
		SDL_BlitSurface(win->title_screen, &win->srcrect, win->g_screen_surface,
				&win->dstrect);
		SDL_RenderPresent(win->render);
		SDL_FreeSurface(win->title_screen);
		SDL_FreeSurface(win->g_screen_surface);
		sound_start(event, &loop);
	}
}

void	sound_start(SDL_Event *event, int *loop)
{
	while (SDL_PollEvent(event))
		if (SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_ESCAPE || event->type == SDL_QUIT)
				exit(1);
			else if (event->key.keysym.sym == SDLK_SPACE)
			{
				system("afplay ./media/sound/start.mp3&");
				SDL_Delay(1000);
				*loop = 0;
			}
		}
}
