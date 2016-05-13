/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:14:23 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/13 22:42:19 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

void	calc_dir(t_init *init)
{
	if (init->ray_dir_x < 0)
	{
		init->step_x = -1;
		init->side_dist_x = (init->map_x - init->ray_pos_x) * init->side_dist_x;
	}
	else
	{
		init->step_x = 1;
		init->side_dist_x = (init->map_x + 1.0 - init->ray_pos_x) * init->side_dist_x;
	}
	if (init->ray_dir_y < 0)
	{
		init->step_y = -1;
		init->side_dist_y = (init->ray_pos_y - init->map_y) * init->side_dist_y;
	}
	else
	{
		init->step_y = 1;
		init->side_dist_y = (init->map_y + 1.0 - init->ray_pos_y) * init->side_dist_y;
	}
}

