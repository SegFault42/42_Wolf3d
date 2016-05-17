/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 14:58:09 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/18 01:27:27 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

/*void	mouse(SDL_Event *event, t_win *win, t_init *init, t_wolf *wolf)*/
/*{*/
	/*[>SDL_MouseMotionEvent *motion;<]*/

	/*[>motion = &event->motion;<]*/
	/*[>if (SDL_MOUSEMOTION > 0 && SDL_MOUSEMOTION < 1280)<]*/
	/*int x = 0;*/
	/*int y = 0;*/

	/*if (event->type == SDL_MOUSEMOTION)*/
	/*{*/
		/*x = event->motion.x;*/
		/*y = event->motion.y;*/
	/*}*/
	/*printf("x = %d, y = %d\n", x, y);*/
/*}*/

void	move_w_s(SDL_Event *event, t_win *win, t_init *init, t_wolf *wolf)
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
		printf("%d\n", wolf->red);
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

void	move_a_d(SDL_Event *event, t_win *win, t_init *init, t_wolf *wolf)
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
		if (SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_ESCAPE)
				win->loop = 0;
			move_w_s(event, win, init, wolf);
			init->old_dir_x = init->dir_x;
			init->old_plane_x = init->plane_x;
			move_a_d(event, win, init, wolf);
		}
		if (event->type == SDL_KEYDOWN && event->key.repeat == 0)
			if (event->key.keysym.sym == SDLK_r)
			{
				system("afplay ./media/sound/deagle_reload.mp3&");
				init->bullet = 0;
			}
		if (init->bullet < 12)
		{
			if(event->type == SDL_MOUSEBUTTONDOWN)
				if (event->button.button == SDL_BUTTON_LEFT)
				{
					flash(win);
					system("afplay ./media/sound/deagle_fire.mp3&");
				}
			init->bullet++;
		}
	}
	printf("bullet = %d\n", init->bullet);
}

void	start(t_win *win, SDL_Event *event)
{
	int loop;

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
		SDL_PollEvent(event);
		if (SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_ESCAPE || event->type == SDL_QUIT)
				exit(1);
			else if (event->key.keysym.sym == SDLK_SPACE)
			{
				system("afplay ./media/sound/start.mp3&");
				SDL_Delay(1000);
				loop = 0;
			}
		}
	}
}

void	deagle(t_win *win)
{
	SDL_Surface *deagle;
	SDL_Rect pos_deagle;

	pos_deagle.x = 0;
	pos_deagle.y = 0;
	deagle = IMG_Load("./media/pics/deagle.png");
	SDL_BlitSurface(deagle, NULL, win->g_screen_surface, &pos_deagle);
}

void	flash(t_win *win)
{
	SDL_Surface *flash;
	SDL_Rect pos_flash;

	pos_flash.x = 0;
	pos_flash.y = 40;
	flash = IMG_Load("./media/pics/fire.png");
	SDL_BlitSurface(flash, NULL, win->g_screen_surface, &pos_flash);
}
