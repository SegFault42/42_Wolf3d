/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:18:20 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/18 01:22:59 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

/*
** srcrect.x = rognage de l'image x
** srcrect.y = rognage de l'image y
** dstrect.x = position x de l'image.
** dstrect.y = position y de l'image.
*/

void	init_title_screen(t_win *win)
{
	win->srcrect.x = 0;
	win->srcrect.y = 0;
	win->srcrect.w = 800;
	win->srcrect.h = 600;
	win->dstrect.x = 0;
	win->dstrect.y = 0;
	win->dstrect.w = 32;
	win->dstrect.h = 32;
}

void	init_pos(t_init *init)
{
	init->pos_x = 19;
	init->pos_y = 12;
	init->dir_x = -1;
	init->dir_y = 0;
	init->plane_x = 0;
	init->plane_y = 0.66;
	init->width = 800;
	init->height = 600;
	init->x = 0;
	init->move_speed = 0.15;
	init->rot_speed = 0.1;
	init->bullet = 0;
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
