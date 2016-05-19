/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:45:06 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/19 12:27:24 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	calc_step(t_wolf *w)
{
	if (w->ray_dir_x < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (w->ray_pos_x - w->map_x) * w->delta_dist_x;
	}
	else
	{
		w->step_x = 1;
		w->side_dist_x = (w->map_x + 1.0 - w->ray_pos_x) * w->delta_dist_x;
	}
	if (w->ray_dir_y < 0)
	{
		w->step_y = -1;
		w->side_dist_y = (w->ray_pos_y - w->map_y) * w->delta_dist_y;
	}
	else
	{
		w->step_y = 1;
		w->side_dist_y = (w->map_y + 1.0 - w->ray_pos_y) * w->delta_dist_y;
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
		wolf->perp_wall_dist = (wolf->map_x - wolf->ray_pos_x +
		(1 - wolf->step_x) / 2) / wolf->ray_dir_x;
	else
		wolf->perp_wall_dist = (wolf->map_y - wolf->ray_pos_y +
			(1 - wolf->step_y) / 2) / wolf->ray_dir_y;
	wolf->line_height = (int)(init->height / wolf->perp_wall_dist);
	wolf->draw_start = -wolf->line_height / 2 + init->height / 2;
	if (wolf->draw_start < 0)
		wolf->draw_start = 0;
	wolf->draw_end = wolf->line_height / 2 + init->height / 2;
	if (wolf->draw_end >= init->height)
		wolf->draw_end = init->height - 1;
}

void	color(t_wolf *wolf)
{
	if (wolf->side == 0 && wolf->ray_dir_x > 0)
		red(wolf);
	else if (wolf->side == 0 && wolf->ray_dir_x < 0)
		green(wolf);
	else if (wolf->side == 1 && wolf->ray_dir_y > 0)
		blue(wolf);
	else
		white(wolf);
}

void	render(t_wolf *wo, t_win *w, t_init *i)
{
	int	reflect;
	int	grey;

	reflect = (wo->draw_end - wo->draw_start) / 2;
	grey = 80;
	SDL_SetRenderDrawColor(w->render, 30, 153, 255, 255);
	SDL_RenderDrawLine(w->render, i->x, 0, i->x, wo->draw_start - 2);
	SDL_SetRenderDrawColor(w->render, 0, 0, 0, 255);
	SDL_RenderDrawLine(w->render, i->x, wo->draw_start - 2, i->x,
			wo->draw_start);
	SDL_SetRenderDrawColor(w->render, wo->red, wo->green, wo->blue, 255);
	SDL_RenderDrawLine(w->render, i->x, wo->draw_start, i->x, wo->draw_end);
	SDL_SetRenderDrawColor(w->render, 0, 0, 0, 255);
	SDL_RenderDrawLine(w->render, i->x, wo->draw_end - 2, i->x, wo->draw_end);
	SDL_SetRenderDrawColor(w->render, (wo->red + grey) / 2, (wo->green + grey) /
			2, (wo->blue + grey) / 2, 255);
	SDL_RenderDrawLine(w->render, i->x, wo->draw_end, i->x, wo->draw_end
			+ reflect);
	SDL_SetRenderDrawColor(w->render, grey, grey, grey, 255);
	SDL_RenderDrawLine(w->render, i->x, wo->draw_end + reflect, i->x,
			i->height);
}
