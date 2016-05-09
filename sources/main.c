/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 17:28:11 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/10 00:25:04 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/Wolf3d.h"

int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_wolf	wolf;

	init_mlx(&mlx);
	init_wolf(&wolf);
	int worldMap[MAPWIDTH][MAPHEIGHT]=
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
	int w = 512;
	int h = 384;
	double pos_x = 22;
	double pos_y = 12;
	double dir_x = -1;
	double dir_y = 0;
	double plane_x = 0;
	double plane_y = 0.66;
	double time = 0;
	double old_time = 0;
	for(int x = 0; x < w; x++)
		{
			double camera_x = 2 * x / (double)w - 1;
			double ray_pos_x = wolf.pos_x;
			double ray_pos_y = wolf.pos_y;
			double ray_dir_x = wolf.dir_x + wolf.plane_x * camera_x;
			double ray_dir_y = wolf.dir_y + wolf.plane_y * camera_x;
			int map_x = (int)ray_pos_x;
			int map_y = (int)ray_pos_y;
			double side_dist_x;
			double side_dist_y;
			double delta_dist_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
			double delta_dist_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
			double perp_wall_dist;
			int step_x;
			int step_y;
			int hit = 0;
			int side;
			if (ray_dir_x < 0)
			{
				step_x = -1;
				side_dist_x = (ray_pos_x - map_x) * delta_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (map_x + 1.0 - ray_pos_x) * delta_dist_x;
			}
			if (ray_dir_y < 0)
			{
				step_y = -1;
				side_dist_y = (ray_pos_y - map_y) * delta_dist_y;
			}
			else
			{
				step_y = 1;
				side_dist_y = (map_y + 1.0 - ray_pos_y) * delta_dist_y;
			}
			while (hit == 0)
			{
				if (side_dist_x < side_dist_y)
				{
					side_dist_x += delta_dist_x;
					map_x += step_x;
					side = 0;
				}
				else
				{
					side_dist_y += delta_dist_y;
					map_y += step_y;
					side = 1;
				}
				if (worldMap[map_x][map_y] > 0) hit = 1;
			}
			if (side == 0)
				perp_wall_dist = fabs(map_x - ray_pos_x + (1 - step_x) / 2) / ray_dir_x;
			else
				perp_wall_dist = fabs(map_y - ray_pos_y + (1 - step_y) / 2) / ray_dir_y;
			int line_height = (int)fabs(h / perp_wall_dist);
			int draw_start = -line_height / 2 + h / 2;
			if (draw_start < 0)
				draw_start = 0;
			int draw_end = line_height / 2 + h / 2;
			if (draw_end >= h)
				draw_end = h -1;
			int color;
			switch (worldMap[map_x][map_y])
			{
				case 1:
					color = 0xFF0000;
					break;
				case 2:
					color = 0x00FF00;
					break;
				case 3:
					color = 0x0000FF;
					break;
				case 4:
					color = 0xFFFFFF;
				default:
					color = 0xFFFF00;
					break;
			}
			if (side == 1)
				color = color / 2;
			for (int line_x = 0; line_x < h; line_x++)
			{
				/*printf("draw_start = %d, draw_end = %d\n", draw_start, draw_end);*/
				mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, draw_start, draw_end, color);
			}
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, draw_start, draw_end, color);
		}
	(void)argc;
	(void)argv;
	/*mlx_hook(mlx.mlx_ptr, 2, 3, key_hook, (void *)NULL);*/
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
