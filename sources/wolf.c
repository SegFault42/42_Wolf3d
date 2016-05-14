/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:45:06 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/14 12:24:06 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	calc_step(t_wolf *wolf)
{
	if (wolf->ray_dir_x < 0)
	{
		wolf->step_x = -1;
		wolf->side_dist_x = (wolf->ray_pos_x - wolf->map_x) * wolf->delta_dist_x;
	}
	else
	{
		wolf->step_x = 1;
		wolf->side_dist_x = (wolf->map_x + 1.0 - wolf->ray_pos_x) * wolf->delta_dist_x;
	}
	if (wolf->ray_dir_y < 0)
	{
		wolf->step_y = -1;
		wolf->side_dist_y = (wolf->ray_pos_y - wolf->map_y) * wolf->delta_dist_y;
	}
	else
	{
		wolf->step_y = 1;
		wolf->side_dist_y = (wolf->map_y + 1.0 - wolf->ray_pos_y) * wolf->delta_dist_y;
	}
}

void	dda(t_wolf *wolf)
{
	if (wolf->side_dist_x < wolf->side_dist_y)
	{
		wolf->side_dist_x += wolf->delta_dist_x;
		wolf->map_x += wolf->step_x;
		wolf->side = 0;
	}
	else
	{
		wolf->side_dist_y += wolf->delta_dist_y;
		wolf->map_y += wolf->step_y;
		wolf->side = 1;
	}
	if (world_map((wolf->map_x), (wolf->map_y)) > 0)
		wolf->hit = 1;
}

void	calc_ray(t_wolf *wolf, t_init *init)
{
	if (wolf->side == 0)
		wolf->perp_wall_dist  = (wolf->map_x - wolf->ray_pos_x +
		(1 - wolf->step_x) / 2) / wolf->ray_dir_x;
	else
		wolf->perp_wall_dist  = (wolf->map_y - wolf->ray_pos_y +
			(1 - wolf->step_y) / 2) / wolf->ray_dir_y;
	wolf->line_height = (int)(init->height / wolf->perp_wall_dist );
	wolf->draw_start = -wolf->line_height / 2 + init->height / 2;
	if (wolf->draw_start < 0)
		wolf->draw_start = 0;
	wolf->draw_end = wolf->line_height / 2 + init->height / 2;
	if (wolf->draw_end >= init->height)
		wolf->draw_end = init->height -1;
}
