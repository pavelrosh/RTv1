/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:49:25 by proshchy          #+#    #+#             */
/*   Updated: 2018/06/07 17:55:09 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	get_dir(double x, double y, t_ray *ray, t_sdl *sdl)
{
	ray->dir.x = x * (V_W / (double)DWIDTH);
	ray->dir.y = y * (V_H / (double)DHEIGHT);
	ray->dir.z = 1.0;
	ray->dir = vec_rot(ray->dir, sdl->cam.rot);
}

void	set_color(t_sdl *sdl, int i, int x, int y)
{
	double	p;
	int		k;

	k = 0;
	p = 0;
	while (k < sdl->light_num)
	{
		if (sdl->light[k].new_inten > 1)
			sdl->light[k].new_inten = 1;
		p += sdl->light[k].new_inten;
		if (p > 1)
			p = 1;
		k++;
	}
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
	int	i;

	i = 0;
	sdl->clos_obj = -1;
	sdl->min_t = INFINITY;
	while (i < sdl->obj_num)
	{
		if (sdl->obj[i].name == SPHERE)
			sphere(sdl, ray, i, &sdl->obj[i]);
		else if (sdl->obj[i].name == PLANE)
			plane(sdl, ray, i, &sdl->obj[i]);
		else if (sdl->obj[i].name == CYLINDER)
			cylinder(sdl, ray, i, &sdl->obj[i]);
		else if (sdl->obj[i].name == CONE)
			cone(sdl, ray, i, &sdl->obj[i]);
		i++;
	}
	if (sdl->clos_obj > -1)
		light(sdl, ray);
	set_color(sdl, sdl->clos_obj, x, y);
}

void	ray_trace_init(t_sdl *sdl, t_ray *ray)
{
	int		x;
	int		y;
	double	n_x;
	double	n_y;

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
			intersection_check(ray, sdl, x, y);
			y++;
		}
		x++;
	}
}
