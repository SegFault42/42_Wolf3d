/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/14 14:16:40 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	init_pos(t_init *init)
{
	init->pos_x = 22;
	init->pos_y = 12;
	init->dir_x = -1;
	init->dir_y = 0;
	init->plane_x = 0;
	init->plane_y = 0.66;
	init->width = 1920;
	init->height = 1080;
	init->x = 0;
}

void	init_env(t_wolf *wolf, t_init *init)
{
	wolf->camera_x = 2 * init->x / (double)init->width - 1;
	wolf->ray_pos_x = init->pos_x;
	wolf->ray_pos_y = init->pos_y;
	wolf->ray_dir_x = init->dir_x + init->plane_x * wolf->camera_x;
	wolf->ray_dir_y = init->dir_y + init->plane_y * wolf->camera_x;
	wolf->map_x = (int)wolf->ray_pos_x;
	wolf->map_y = (int)wolf->ray_pos_y;
	wolf->delta_dist_x = sqrt(1 + (wolf->ray_dir_y * wolf->ray_dir_y) /
			(wolf->ray_dir_x * wolf->ray_dir_x));
	wolf->delta_dist_y = sqrt(1 + (wolf->ray_dir_x * wolf->ray_dir_x) /
			(wolf->ray_dir_y * wolf->ray_dir_y));
	wolf->hit = 0;
}
