/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/13 22:41:03 by rabougue         ###   ########.fr       */
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
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	double			move_speed;
	double			rot_speed;
	int				line_height;
	int				draw_start;
	int				draw_end;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	alpha;
}					t_init;

/*
** init.c
*/
void				init_map(t_init *init);
void				calc_dir(t_init *init);
void				dda(t_init *init, t_sdl_win *win);
void				init_pos(t_init *init);
int					init_window(char *win_name, int width, int height,
					t_sdl_win *win);

void				close_window(t_sdl_win *win);
#endif
