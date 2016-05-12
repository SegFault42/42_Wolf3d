/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 20:59:25 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->height = 500;
	mlx->width = 500;
	mlx->mlx_ptr = mlx_init();
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, "Wolf3d");
}

void	init_map(t_init *init)
{
	init->pos_x = 22;
	init->pos_y = 12;
	init->dir_x = -1;
	init->dir_y = 0;
	init->plane_x = 0;
	init->plane_y = 0.6;
	init->time = 0;
	init->old_time = 0;
	init->ray_pos_x = init->pos_x;
	init->ray_pos_y = init->pos_y;
	init->ray_dir_x = init->dir_x + init->plane_x * init->camera_x;
	init->ray_dir_y = init->dir_y + init->plane_y * init->camera_x;
	init->map_x = (int)init->ray_pos_x;
	init->map_y = (int)init->ray_pos_y;
	init->dist2mur_x = sqrt(1 + (init->ray_dir_y * init->ray_dir_y) /
			(init->ray_dir_x * init->ray_dir_x));
	init->dist2mur_y = sqrt(1 + (init->ray_dir_x * init->ray_dir_x) /
			(init->ray_dir_y * init->ray_dir_y));
	init->touche = 0;
}
