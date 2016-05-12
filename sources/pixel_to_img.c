/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 21:46:44 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 21:49:02 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	ft_pixel_put_to_image_colors(t_mlx *mlx)
{
	if (mlx->endian == 0)
	{
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 2] = mlx->r;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 1] = mlx->g;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 0] = mlx->b;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 3] = mlx->o;
	}
	else
	{
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 2] = mlx->b;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 1] = mlx->g;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 0] = mlx->r;
		mlx->data[mlx->y * mlx->sizeline + mlx->x * mlx->bpp / 8 + 3] = mlx->o;
	}
}
