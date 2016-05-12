/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 22:45:15 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // a supprimer.
# include <stdlib.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

# define MAPWIDTH 24
# define MAPHEIGHT 24
#define W 500
#define H 500

typedef struct		s_mlx
{
	int				width;
	int				height;
	int				x;
	int				y;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned long	img_color;
	char			*data;
	int				sizeline;
	int				endian;
	int				bpp;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	o;
}					t_mlx;

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

void	init_mlx(t_mlx *mlx);
void	init_map(t_init *init);
void	calc_dir(t_init *init);
void	dda(t_init *init);
void	dist_cam_dir(t_init *init, t_mlx *mlx);
void	ft_pixel_put_to_image_colors(t_mlx *mlx);
void	draw(t_init *init, t_mlx *mlx);

#endif
