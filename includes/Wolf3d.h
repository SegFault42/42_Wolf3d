/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/08 17:23:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include "./keyboard.h"

# define RED		0xFF0000
# define W			2560
# define H			1440

typedef struct		s_event
{
	int				button_distorsion_julia;
	int				button_cross;
	double			x_reel;
	double			y_reel;
}					t_event;

typedef struct		s_all
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned long	img_color;
	char			*data;
	int				sizeline;
	int				endian;
	int				bpp;
	int				x;
	int				y;
	double			x1;
	double			y1;
	double			zoom;
	double			max;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			tmp;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	o;
	unsigned char	r2;
	unsigned char	g2;
	unsigned char	b2;
	unsigned char	o2;
	int				check_fractal;
	t_event			event;
	void			(*zoom_tab[8])(struct s_all *);
}					t_all;
/*
** call_fractal.c
*/
void				call_fractal_1(char **argv, t_all *all);
void				call_fractal_2(char **argv, t_all *all);
void				call_fractal_3(char **argv, t_all *all);
void				call_fractal_4(char **argv, t_all *all);
/*
** check_fractal.c
*/
int					check_fractal_init(t_all *all);
int					check_fractal(int keycode, t_all *all);
/*
** draw_fractal_1.c
*/
void				draw_mandelbrot(t_all *all);
void				draw_julia(t_all *all);
void				draw_ship(t_all *all);
void				draw_tricorne(t_all *all);
void				draw_bird(t_all *all);
/*
** draw_fractal_1.c
*/
void				draw_space(t_all *all);
void				draw_pylone(t_all *all);
void				draw_celtic(t_all *all);
/*
** error.c
*/
void				check_arguments(void);
/*
** init_event.c
*/
void				init_zoom_tab(t_all *all);
void				init_event(t_all *all);
void				color_fractal(t_all *all);
void				move(t_all *all, double x, double y);
/*
** init_fractal_1.c
*/
void				init_mlx(t_all *all);
void				init_mandelbrot(t_all *all);
void				init_julia(t_all *all);
void				init_ship(t_all *all);
void				init_tricorne(t_all *all);
/*
** init_fractal_2.c
*/
void				init_bird(t_all *all);
void				init_space(t_all *all);
void				init_pylone(t_all *all);
void				init_celtic(t_all *all);
/*
** key_hook.c
*/
void				clear_image(t_all *all);
void				draw_cross(t_all *all, int x, int y, int color);
int					j_slide(int null, double x, int y, t_all *all);
/*
** key_hook_fractal_1.c
*/
int					key_hook_fractal_1(int key, t_all *all, void(*ft)(t_all *));
int					key_hook_julia(int keycode, t_all *all);
int					key_hook_fractal_2(int key, t_all *all, void(*ft)(t_all *));
int					key_hook_fractal_3(int key, t_all *all, void(*ft)(t_all *));
/*
** loop_fractal_1.c
*/
void				loop_mandelbrot(t_all *all);
void				loop_ship(t_all *all);
void				loop_tricorne(t_all *all);
void				loop_bird_of_pray(t_all *all);
void				loop_pylone(t_all *all);
/*
** loop_fractal_1.c
*/
void				loop_celtic(t_all *all);
/*
** mouse_hook.c
*/
int					mouse_hook_zoom(int button, int y, int x, t_all *all);
/*
** print_point.c
*/
void				ft_pixel_put_to_image(t_all *all);
void				ft_pixel_put_to_image_colors(t_all *all);

#endif
