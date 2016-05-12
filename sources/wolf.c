/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 21:39:46 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 23:12:09 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int world_map[MAPWIDTH][MAPHEIGHT]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	calc_dir(t_init *init)
{
	if (init->ray_dir_x < 0)
	{
		init->etape_x = -1;
		init->dist_mur_x = (init->map_x - init->ray_pos_x) * init->dist2mur_x;
	}
	else
	{
		init->etape_x = 1;
		init->dist_mur_x = (init->map_x + 1.0 - init->ray_pos_x) * init->dist2mur_x;
	}
	if (init->ray_dir_y < 0)
	{
		init->etape_y = -1;
		init->dist_mur_y = (init->ray_pos_y - init->map_y) * init->dist2mur_y;
	}
	else
	{
		init->etape_y = 1;
		init->dist_mur_y = (init->map_y + 1.0 - init->ray_pos_y) * init->dist2mur_y;
	}
}

void	dda(t_init *init)
{
	while (init->touche == 0)
	{
		if (init->dist_mur_x < init->dist_mur_y)
		{
			init->dist_mur_x += init->dist2mur_x;
			init->map_x += init->etape_x;
			init->mur_ver_or_hor = 0;
		}
		else
		{
			init->dist_mur_y += init->dist2mur_y;
			init->map_y += init->etape_y;
			init->mur_ver_or_hor = 1;
		}
		if (world_map[init->map_x][init->map_y] > 0)
			init->touche = 1;
		}
}

void dist_cam_dir(t_init *init, t_mlx *mlx)
{
	if (init->mur_ver_or_hor == 0)
		init->longeur_mur = (init->map_x - init->ray_pos_x + (1 - init->etape_x)
				/ 2) / init->ray_dir_x;
	else
		init->longeur_mur = (init->map_y - init->ray_pos_y + (1 - init->etape_y)
				/ 2) / init->ray_dir_y;
	init->hauteur_mur = (int)(mlx->height / init->longeur_mur);
	init->draw_start = -init->hauteur_mur / 2 + mlx->height / 2;
	if (init->draw_start < 0)
		init->draw_start = 0;
	init->draw_end = init->hauteur_mur / 2 + mlx->height / 2;
	if (init->draw_end >= mlx->height)
		init->draw_end = mlx->height -1;
}

void	draw(t_init *init, t_mlx *mlx)
{
	if (world_map[init->map_x][init->map_y] == 1)
	{
		mlx->r = 255;
		mlx->g = 0;
		mlx->b = 0;
		ft_pixel_put_to_image_colors(mlx);
	}
	else if (world_map[init->map_x][init->map_y] == 2)
	{
		mlx->r = 0;
		mlx->g = 255;
		mlx->b = 0;
		ft_pixel_put_to_image_colors(mlx);
	}
	else if (world_map[init->map_x][init->map_y] == 3)
	{
		mlx->r = 0;
		mlx->g = 0;
		mlx->b = 255;
		ft_pixel_put_to_image_colors(mlx);
	}
	else if (world_map[init->map_x][init->map_y] == 4)
	{
		mlx->r = 0;
		mlx->g = 0;
		mlx->b = 0;
		ft_pixel_put_to_image_colors(mlx);
	}
	else
	{
		mlx->r = 255;
		mlx->g = 255;
		mlx->b = 0;
		ft_pixel_put_to_image_colors(mlx);
	}
	if (init->touche == 1)
	{
		mlx->r /= 2;
		mlx->g /= 2;
		mlx->b /= 2;
	}
	ft_debug();
}
