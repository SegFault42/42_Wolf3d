/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabougue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:40:10 by rabougue          #+#    #+#             */
/*   Updated: 2016/05/10 23:37:21 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

int main(int argc, char **argv)
{
	t_sdl sdl;

	if (!init_sdl(&sdl))
		return (-1);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(sdl.mainWindow);
	run_wolf(&sdl);
	clean_up(&sdl);
	return (0);
}

