/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 23:10:34 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"


int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_init	init;

	init_mlx(&mlx);
	while(init.x < mlx.width)
	{
		init.camera_x = 2 * init.x / (double)mlx.width - 1;
		init_map(&init);
		calc_dir(&init);
		while (init.touche == 0)
		{
				dda(&init);
				dist_cam_dir(&init, &mlx);
				while (init.draw_start < init.draw_end)
				{
					draw(&init, &mlx);
					init.draw_start++;
				}
		}
		init.x++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
