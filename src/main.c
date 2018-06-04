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

void	cam_data(t_sdl *sdl, char **str)
{
	sdl->cam.pos.x = (double)(atoi(str[1]));
	sdl->cam.pos.y = (double)(atoi(str[2]));
	sdl->cam.pos.z = (double)(atoi(str[3]));
	sdl->cam.rot.x = (double)(atoi(str[4]));
	sdl->cam.rot.y = (double)(atoi(str[5]));
	sdl->cam.rot.z = (double)(atoi(str[6]));
}

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
	ft_parse(argv[1], &sdl, &ray);
	if (argc != 2 || !argv[1])
		ft_error("Wrong arguments");
	ray_trace_init(&sdl, &ray);
	SDL_RenderPresent(sdl.rend);
	while (1)
		while(SDL_PollEvent(&event))
			if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type &&
				SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				exit(0);
	free(sdl.obj);
	free(sdl.light);
	return (0);
}









