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

#include "../include/rtv1.h"

void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    	if ((sdl->wind = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED, 
    		SDL_WINDOWPOS_UNDEFINED, DWIDTH, DHEIGHT, SDL_WINDOW_SHOWN)))
    		if ((sdl->rend = SDL_CreateRenderer(sdl->wind, -1,
    			SDL_RENDERER_ACCELERATED)))
    			return ;
    ft_putendl("Error in init_sdl()");
    exit(0);
}

void	ft_error(char *str)
{
	ft_putendl(str);
	exit (1);
}

int 	main(int argc, char **argv)
{
	t_sdl 		sdl;
	t_ray		ray;
	SDL_Event 	event;

	init_sdl(&sdl);
	sdl.obj = malloc(sizeof(t_object) * 10); //hardcode!
	if (argc != 2 || !argv[1])
		ft_error("Wrong arguments");
	ft_parse(argv[1], &sdl, &ray);
	ray_trace_init(&sdl, &ray);
	SDL_RenderPresent(sdl.rend);
	while (1)
		while(SDL_PollEvent(&event))
			if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type &&
				SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				exit(0);

	return (0);
}




















