/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/12 21:47:05 by rabougue         ###   ########.fr       */
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
		}
	}
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
