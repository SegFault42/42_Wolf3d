/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/11 20:16:25 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // a supprimer.
# include <stdlib.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "./SDL2/SDL.h"
//# include "./SDL2/SDL_opengl.h"

# define MAPWIDTH 24
# define MAPHEIGHT 24

typedef struct		s_sdl_win
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	int				loop;
	int				width;
	int				height;
}					t_sdl_win;

typedef struct		s_sdl_event
{
	SDL_Event		event;
}					t_sdl_event;

typedef struct		s_wolf
{
	
}				t_wolf;

int					init_window(char *win_name, int width, int height, t_sdl_win *win);
void				close_window(t_sdl_win *win);

#endif
