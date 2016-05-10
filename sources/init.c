/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/10 23:45:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putendl("Init failed !");
		return (0);
	}
	sdl->mainWindow = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL);
	if (!sdl->mainWindow)
	{
		ft_putendl("Unable to create window");
		return (0);
	}
	sdl->mainContext = SDL_GL_CreateContext(sdl->mainWindow);
	SetOpenGLAttributes();
	SDL_GL_SetSwapInterval(1);
	return (1);
}

int	SetOpenGLAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	return (1);
}
