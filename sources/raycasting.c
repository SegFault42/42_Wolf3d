/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:14:23 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/13 18:20:00 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

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

