/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 19:35:04 by rabougue         ###   ########.fr       */
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

typedef struct		s_init
{
	int				x;
	int				map_x;
	int				map_y;
	int				etape_x;
	int				etape_y;
	int				touche;
	int				mur_ver_or_hor;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			dist_mur_x;
	double			dist_mur_y;
	double			dist2mur_x;
	double			dist2mur_y;
	double			longeur_mur;
	int				hauteur_mur;
	int				draw_start;
	int				draw_end;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_init;

/*
** init.c
*/
void				init_map(t_init *init);
int					init_window(char *win_name, int width, int height,
					t_sdl_win *win);

void				close_window(t_sdl_win *win);
#endif
