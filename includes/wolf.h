/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/19 18:11:11 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdlib.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "./SDL2/SDL.h"
# include "../includes/SDL2/SDL_image.h"

# define MAPWIDTH 24
# define MAPHEIGHT 24

typedef struct		s_win
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Surface		*title_screen;
	SDL_Surface		*g_screen_surface;
	SDL_Surface		*icon;
	SDL_Rect		srcrect;
	SDL_Rect		dstrect;
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
	int				bullet;
	int				weapon;

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
void				init_title_screen(t_win *win);
void				init_pos(t_init *init);
void				init_env(t_wolf *wolf, t_init *init);
/*
** wolf.c
*/
void				calc_step(t_wolf *w);
void				dda(t_wolf *wolf);
void				calc_ray(t_wolf *wolf, t_init *init);
void				color(t_wolf *wolf);
void				render(t_wolf *wo, t_win *w, t_init *i);
/*
** color.c
*/
void				red(t_wolf *wolf);
void				green(t_wolf *wolf);
void				deagle(t_init *init, t_win *win, SDL_Event *event);
void				blue(t_wolf *wolf);
void				white(t_wolf *wolf);
void				defaut(t_wolf *wolf);
/*
** keyboard.c
*/
void				keyboard(SDL_Event *event, t_win *win, t_init *init,
					t_wolf *wolf);
void				move_w_s(SDL_Event *event, t_init *init, t_wolf *wolf);
void				move_a_d(SDL_Event *event, t_init *init);
void				start(t_win *win, SDL_Event *event);
void				sound_start(SDL_Event *event, int *loop);
/*
** sound.c
*/
void				ambient(void);
void				walk(t_init *init, t_wolf *wolf);
/*
** map.c
*/
int					world_map(int x, int y);
/*
** weapon.c
*/
void				deagle(t_init *init, t_win *win, SDL_Event *event);
void				weapon(t_win *win);
void				flash(t_win *win);
void				sound_deagle(SDL_Event *event, t_init *init, t_win *win);
/*
** main.c
*/
int					set_icon(t_win *win);
int					check_arg(int argc);
int					main(int argc, char **argv);
int					check_arg(int argc);

#endif
