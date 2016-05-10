/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/10 12:47:51 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1920, 1080);
	mlx->data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
		&mlx->sizeline, &mlx->endian);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "Wolf3d");
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

int		key_hook(int keycode)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

void	ft_pixel_put_to_image_colors(t_mlx *mlx)
{
	if (mlx->endian == 0)
	{
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 2] = mlx->r;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 1] = mlx->g;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 0] = mlx->b;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 3] = 0x00;
	}
	else
	{
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 2] = mlx->b;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 1] = mlx->g;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 0] = mlx->r;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 3] = 0x00;
	}
}
