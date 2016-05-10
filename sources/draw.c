/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:35:53 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/10 23:40:02 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	run_wolf(t_sdl *sdl)
{
	int loop;

	loop = 1;
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
				else if (SDLK_r)
				{
					glClearColor(1.0, 0.0, 0.0, 1.0);
					glClear(GL_COLOR_BUFFER_BIT);
					SDL_GL_SwapWindow(sdl->mainWindow);
				}
				else if (SDLK_g)
				{
					glClearColor(0.0, 1.0, 0.0, 1.0);
					glClear(GL_COLOR_BUFFER_BIT);
					SDL_GL_SwapWindow(sdl->mainWindow);
				}
				else if (SDLK_b)
				{
					glClearColor(0.0, 0.0, 1.0, 1.0);
					glClear(GL_COLOR_BUFFER_BIT);
					SDL_GL_SwapWindow(sdl->mainWindow);
				}
			}
		}
	}
}

void	clean_up(t_sdl *sdl)
{
	SDL_GL_DeleteContext(sdl->mainContext);
	SDL_DestroyWindow(sdl->mainWindow);
	SDL_Quit();
}

void	check_sdl_error(int line)
{
	const char *error = SDL_GetError();
	line = -1;
	if (ft_strcmp(error, "") != 0)
	{
		ft_putstr("SDL Error : ");
		ft_putendl(error);
		SDL_ClearError();
	}
}

/*void	PrintSDL_GL_Attributes()*/
/*{*/
	/*int	value = 0;*/
	/*SDL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &value);*/
	
/*}*/
