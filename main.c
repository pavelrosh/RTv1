/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:49:52 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/11 13:49:53 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    	if ((sdl->wind = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED, 
    		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
    		if ((sdl->rend = SDL_CreateRenderer(sdl->wind, -1,
    			SDL_RENDERER_ACCELERATED)))
    			return ;
    ft_putendl("Error in init_sdl()");
    exit(0);
}


int 	main(int argc, char **argv)
{
	t_sdl sdl;
	SDL_Event event;
	int i;
	int j;

	i = 0;
	init_sdl(&sdl);
	while (i <= HEIGHT)
	{
		j = 0;
		while (j <= WIDTH)
		{
			SDL_SetRenderDrawColor(sdl.rend, 0, 255, 255, 255);
			SDL_RenderDrawPoint(sdl.rend, j, i);
			j++;
		}
		i++;
	}
	SDL_RenderPresent(sdl.rend);
	while (1)
		while(SDL_PollEvent(&event))
			if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type &&
				SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				exit(0);

	return (0);
}

















