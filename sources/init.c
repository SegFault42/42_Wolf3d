/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/09 12:22:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W, H);
	mlx->data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
		&mlx->sizeline, &mlx->endian);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W, H, "Wolf3d");
}

void	init_wolf(t_wolf *wolf)
{
	wolf->pos_x = 22;
	wolf->pos_y = 12;
	wolf->dir_x = -1;
	wolf->dir_y = 0;
	wolf->plane_x = 0;
	wolf->plane_y = 0.66;
	wolf->time = 0;
	wolf->old_time = 0;
}
