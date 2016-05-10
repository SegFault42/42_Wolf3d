/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:52:14 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/10 14:50:53 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // a supprimer.
# include <stdlib.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "./SDL2/SDL.h"

//# define W 512
//# define H 384
# define MAPWIDTH 24
# define MAPHEIGHT 24

typedef struct	s_mlx
{
	void		*win_ptr;
	void		*mlx_ptr;
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			x;
	int			y;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	o;
}				t_mlx;

typedef struct	s_wolf
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
}				t_wolf;


/*
**init.c
*/
void	init_mlx(t_mlx *mlx);
void	init_wolf(t_wolf *wolf);
int		key_hook(int keyvcode);
void	ft_pixel_put_to_image_colors(t_mlx *mlx);

#endif
