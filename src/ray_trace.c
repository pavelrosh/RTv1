/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:49:25 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/21 18:49:26 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	get_dir(double x, double y, t_ray *ray, t_sdl *sdl)
{
	// printf("%f %f\n", x, y);
	ray->dir.x = x * (V_W / (double)DWIDTH);
	ray->dir.y = y * (V_H / (double)DHEIGHT);
	ray->dir.z = 1.0;
	ray->dir = vec_rot(ray->dir, sdl->cam.rot);
	// printf("%f %f %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
	// ray->dir = vec_norm(ray->dir);
	// printf("%f %f %f\n", ray->dir.x, ray->dir.y, ray->dir.z);
}

void	set_color(t_sdl *sdl, int i, int x, int y)
{
	double p;

	p = sdl->light.new_inten > 1 ? 1 : sdl->light.new_inten;
	if (i > -1)
	{
		SDL_SetRenderDrawColor(sdl->rend, sdl->obj[i].col.rgb[0] * p, 
			sdl->obj[i].col.rgb[1] * p, sdl->obj[i].col.rgb[2] * p, 255);
		SDL_RenderDrawPoint(sdl->rend, x, y);
	}
	else
	{
		SDL_SetRenderDrawColor(sdl->rend, 0, 0, 0, 255);
		SDL_RenderDrawPoint(sdl->rend, x, y);
	}
}

void	intersection_check(t_ray *ray, t_sdl *sdl, int x, int y)
{
	int 	i;

	i = 0;
	sdl->clos_obj = -1;
	sdl->min_t = INFINITY;
	// printf("%f %f %f %f\n", sdl->obj[0].pos.x, sdl->obj[0].pos.y, sdl->obj[0].pos.z, sdl->obj[0].r);
	while (i < sdl->obj_num)
	{
		if (sdl->obj[i].name == SPHERE)
			sphere(sdl, ray, i, &sdl->obj[i]);
		else if (sdl->obj[i].name == PLANE)
			plane(sdl, ray, i, &sdl->obj[i]);
		else if (sdl->obj[i].name == CYLINDER)
			cylinder(sdl, ray, i, &sdl->obj[i]);
		i++;
	}
	if (sdl->clos_obj > -1)
	{
		sdl->light.p = vec_sum(ray->orig, vec_scale(ray->dir, sdl->obj[sdl->clos_obj].t));
		if (sdl->obj[sdl->clos_obj].name == SPHERE)	
			sdl->light.n = vec_norm(vec_sub(sdl->light.p, sdl->obj[sdl->clos_obj].pos));
		else if (sdl->obj[sdl->clos_obj].name == PLANE)
			sdl->light.n = sdl->obj[sdl->clos_obj].rot;
		else if (sdl->obj[sdl->clos_obj].name == CYLINDER)
			sdl->light.n = sdl->obj[sdl->clos_obj].rot;
		get_intensity(sdl, &sdl->light, vec_scale(ray->dir, -1), sdl->obj[sdl->clos_obj].specular);
	}
	// printf("%f %f %f\n", sdl->light.p.x, sdl->light.p.y, sdl->light.p.z);
	set_color(sdl, sdl->clos_obj, x, y);
}

void	ray_trace_init(t_sdl *sdl, t_ray *ray)
{
	int 		x;
	int 		y;
	double		n_x;
	double		n_y;

	x = 0;
	while (x <= DWIDTH)
	{
		y = 0;
		n_x = (x + 0.5) / (double)DWIDTH;
		n_x = 2 * n_x - 1;
		while (y <= DHEIGHT)
		{
			n_y = (y + 0.5) / (double)DHEIGHT;
			n_y = 1 - (2 * n_y);
			get_dir(n_x, n_y, ray, sdl);
			// printf("%f %f\n", n_x, n_y);
			intersection_check(ray, sdl, x, y);
			y++;
		}
		x++;
	}
}
