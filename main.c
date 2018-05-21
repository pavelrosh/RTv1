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

void	get_dir(double x, double y, t_ray *ray, t_sdl *sdl)
{
	// t_vec dir;

	// dir = vec_sub(sdl->obj.pos, ray->orig);
	// dir = vec_norm(dir);
	// ray->dir.x = dir.x;
	// ray->dir.y = dir.y;
	// ray->dir.z = dir.z;
	// printf("%f %f\n", x, y);
	ray->dir.x = x * (1 / (double)DWIDTH);
	ray->dir.y = y * (1 / (double)DHEIGHT);
	ray->dir.z = 1;
	// printf("%f %f %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
}

double	get_t(double a, double b, double d)
{
	double t1;
	double t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0) || (t1 >= 0 && t2 < 0))
		return (t1);
	else if ((t2 <= t1 && t2 >= 0) || (t1 < 0 && t2 >= 0))
		return (t2);
	return (-1);
}

double	sphere_intersect(t_ray *ray, t_sdl *sdl)
{
	double a;
	double b;
	double c;
	double d;
	t_vec oc;

	oc = vec_sub(ray->orig, sdl->obj.pos);
	a = vec_dot(ray->dir, ray->dir);
	b = 2 * vec_dot(oc, ray->dir);
	c = vec_dot(oc, oc) - (sdl->obj.r * sdl->obj.r);
	// printf("%f %f %f\n", a, b, c);
	d = b * b - 4 * a * c;
	// d = DROUND(d);
	if (d < 0)
		return (-1);
	// printf("%f %f %f\n", a, b, d);
	return (get_t(a, b, d));
}

int 	main(int argc, char **argv)
{
	t_sdl 		sdl;
	t_ray		ray;
	SDL_Event 	event;
	int 		x;
	int 		y;
	double 		t;
	double		n_x;
	double		n_y;

	init_sdl(&sdl);
	if (argc != 2 || !argv[1])
		ft_error("Wrong arguments");
	ft_parse(argv[1], &sdl);
	//initialize start x position and ray origin pos
	// x = -((double)DWIDTH / 2);
	x = 0;
	ray.orig.x = sdl.cam.pos.x;
	ray.orig.y = sdl.cam.pos.y;
	ray.orig.z = sdl.cam.pos.z;
	t = -1;
	while (x <= DWIDTH)
	{
		// y = -((double)DHEIGHT / 2);
		y = 0;
		n_x = (x + 0.5) / (double)DWIDTH;
		n_x = 2 * n_x - 1;
		while (y <= DHEIGHT)
		{
			n_y = (y + 0.5) / (double)DHEIGHT;
			n_y = 1 - (2 * n_y);
			get_dir(n_x, n_y, &ray, &sdl);
			// get_dir(x, y, &ray);
			// printf("%f %f\n", n_x, n_y);
			t = sphere_intersect(&ray, &sdl);
			if (t > 1)
			{
				SDL_SetRenderDrawColor(sdl.rend, 255, 0, 0, 255);
				SDL_RenderDrawPoint(sdl.rend, x, y);
			}
			else
			{
				SDL_SetRenderDrawColor(sdl.rend, 255, 255, 255, 255);
				SDL_RenderDrawPoint(sdl.rend, x, y);
			}
			y++;
		}
		x++;
	}
	SDL_RenderPresent(sdl.rend);
	while (1)
		while(SDL_PollEvent(&event))
			if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type &&
				SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				exit(0);

	return (0);
}




















