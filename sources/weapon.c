/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 12:44:02 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/19 12:52:36 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	weapon(t_win *win)
{
	SDL_Surface	*deagle;
	SDL_Rect	pos_deagle;

	pos_deagle.x = 0;
	pos_deagle.y = 0;
	deagle = IMG_Load("./media/pics/deagle.png");
	SDL_BlitSurface(deagle, NULL, win->g_screen_surface, &pos_deagle);
	SDL_FreeSurface(deagle);
}

void	deagle(t_init *init, t_win *win, SDL_Event *event)
{
	SDL_Surface	*deagle;
	SDL_Rect	pos_deagle;

	pos_deagle.x = 0;
	pos_deagle.y = 0;
	if (event->button.button == SDL_SCANCODE_1)
	{
		init->weapon = 0;
		init->bullet = 0;
	}
	if (event->button.button == SDL_SCANCODE_2)
	{
		init->weapon = 1;
		init->bullet = 0;
	}
	if (init->weapon == 0)
		deagle = IMG_Load("./media/pics/ak_47.png");
	if (init->weapon == 1)
		deagle = IMG_Load("./media/pics/deagle.png");
	SDL_BlitSurface(deagle, NULL, win->g_screen_surface, &pos_deagle);
	SDL_FreeSurface(deagle);
}

void	flash(t_win *win)
{
	SDL_Surface	*flash;
	SDL_Rect	pos_flash;

	pos_flash.x = 0;
	pos_flash.y = 40;
	flash = IMG_Load("./media/pics/fire.png");
	SDL_BlitSurface(flash, NULL, win->g_screen_surface, &pos_flash);
	SDL_FreeSurface(flash);
}

void	sound_deagle(SDL_Event *event, t_init *init, t_win *win)
{
	if (event->type == SDL_KEYDOWN && event->key.repeat == 0)
		if (event->key.keysym.sym == SDLK_r && init->bullet != 0)
		{
			system("afplay ./media/sound/reload.mp3&");
			init->bullet = 0;
		}
	if (init->bullet < 12 && event->type == SDL_MOUSEBUTTONDOWN)
	{
		if (event->button.button == SDL_BUTTON_LEFT && init->weapon == 1)
		{
			system("afplay ./media/sound/deagle_fire.wav&");
			init->bullet++;
			flash(win);
		}
		else if (event->button.button == SDL_BUTTON_LEFT && init->weapon == 0)
		{
			system("afplay ./media/sound/ak47_fire.wav&");
			init->bullet++;
			flash(win);
		}
	}
	if (init->bullet == 12 && event->type == SDL_MOUSEBUTTONDOWN)
		if (event->button.button == SDL_BUTTON_LEFT)
			system("afplay ./media/sound/empty_gun.mp3&");
}
