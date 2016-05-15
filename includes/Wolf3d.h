/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/15 02:09:48 by rabougue         ###   ########.fr       */
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

typedef struct		s_win
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	int				loop;
}					t_win;

typedef struct		s_sdl_event
{
	SDL_Event		event;
}					t_sdl_event;

typedef struct		s_init
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				width;
	int				height;
	int				x;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
	int				nb;
}					t_init;

typedef struct		s_wolf
{
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	alpha;
}					t_wolf;
/*
** window.c
*/
int					init_window(char *win_name, int width, int height,
					t_win *win);
void				close_window(t_win *win);
void				sdl_clear(t_win *win);
/*
** init.c
*/
void				init_pos(t_init *init);
void				init_env(t_wolf *wolf, t_init *init);
/*
** wolf.c
*/
void				calc_step(t_wolf *wolf);
void				dda(t_wolf *wolf);
void				calc_ray(t_wolf *wolf, t_init *init);
void				color(t_wolf *wolf);
void				render(t_wolf *wolf, t_win *win, t_init *init);
/*
** color.c
*/
void				red(t_wolf *wolf);
void				green(t_wolf *wolf);
void				blue(t_wolf *wolf);
void				white(t_wolf *wolf);
void				defaut(t_wolf *wolf);
/*
** keyboard.c
*/
void				keyboard(SDL_Event *event, t_win *win, t_init *init, t_wolf *wolf);
void				mouse(SDL_Event *event, t_win *win, t_init *init, t_wolf *wolf);
void				move_w_s(SDL_Event *event, t_win *win, t_init *init, t_wolf *wolf);
void				move_a_d(SDL_Event *event, t_win *win, t_init *init, t_wolf *wolf);


int					world_map(int x, int y);
void				draw_sky(t_init *init, t_win *win, int start, int end);
void				walk(t_init *init);

#endif
