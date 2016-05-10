/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/10 20:31:13 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // a supprimer.
# include <stdlib.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "./SDL2/SDL.h"
# include "./SDL2/SDL_opengl.h"

# define GL3_PROTOTYPES 1
# define TRUE 1
# define FALSE 0


typedef struct		s_sdl
{
	SDL_Window		*mainWindow;
	SDL_GLContext	mainContext;
}					t_sdl;
/*
** init.c
*/
int		init_sdl(t_sdl *sdl);
int		SetOpenGLAttributes();
/*
** draw.c
*/
void	run_wolf(t_sdl *sdl);
void	clean_up(t_sdl *sdl);
void	check_sdl_error(int line);

#endif
