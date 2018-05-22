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
	ray->dir.x = x * (1 / (double)DWIDTH);
	ray->dir.y = y * (1 / (double)DHEIGHT);
	ray->dir.z = 1.0;
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

double	sphere_intersect(t_ray *ray, t_object *obj)
{
	double a;
	double b;
	double c;
	double d;
	t_vec oc;

	// printf("%f %f %f %f\n", obj->pos.x, obj->pos.y, obj->pos.z, obj->r);
	oc = vec_sub(ray->orig, obj->pos);
	a = vec_dot(ray->dir, ray->dir);
	b = 2 * vec_dot(oc, ray->dir);
	c = vec_dot(oc, oc) - (obj->r * obj->r);
	// printf("%f %f %f\n", a, b, c);
	d = b * b - 4 * a * c;
	// d = DROUND(d);
	if (d < 0)
		return (-1);
	// printf("%f %f %f\n", a, b, d);
	return (get_t(a, b, d));
}

double	intersection_check(t_ray *ray, t_sdl *sdl)
{
	double	t;
	int 	i;

	i = 0;
	t = -1;
	// printf("%f %f %f %f\n", sdl->obj[0].pos.x, sdl->obj[0].pos.y, sdl->obj[0].pos.z, sdl->obj[0].r);
	while (i < sdl->obj_num)
	{
		if (sdl->obj[i].name == SPHERE)
			t = sphere_intersect(ray, &sdl->obj[i]);
		if (t > 1)
			return (t);
		// else if (sdl->obj[i].name == PLANE)
			// t = sphere_intersect(ray, sdl);
		i++;
	}
	// i = 0;
	// while (i < sdl->obj_num && sdl->obj_num > 1)
	// {
	// 	if (sdl->obj[i].t < sdl.obj[i + 1].t)
	// 		t = sdl->obj[i].t;
	// 	i++;
	// }
	return (t);
}
void	ray_trace_init(t_sdl *sdl, t_ray *ray)
{
	int 		x;
	int 		y;
	double 		t;
	double		n_x;
	double		n_y;

	x = 0;
	y = -1;
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
			t = intersection_check(ray, sdl);
			if (t > 1)
			{
				SDL_SetRenderDrawColor(sdl->rend, 255, 0, 0, 255);
				SDL_RenderDrawPoint(sdl->rend, x, y);
			}
			else
			{
				SDL_SetRenderDrawColor(sdl->rend, 255, 255, 255, 255);
				SDL_RenderDrawPoint(sdl->rend, x, y);
			}
			y++;
		}
		x++;
	}
}
