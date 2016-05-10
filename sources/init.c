/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/10 18:54:17 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int	init_sdl(t_init_sdl *sdl)
{
	
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->mainWindow = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_OPENGL);
	if (!sdl->mainWindow)
	{
		ft_putendl("Unable to create window");
		return (EXIT_FAILURE);
	}
	sdl->mainContext = SDL_GL_CreateContext(sdl->mainWindow);
	/*SetOpenGLAttributes();*/
	SDL_GL_SetSwapInterval(1);
	/*glewExperimental = GL_TRUE;*/
	/*glewInit();*/
	return (EXIT_SUCCESS);
}

int	SetOpenGLAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	return (EXIT_SUCCESS);
}
