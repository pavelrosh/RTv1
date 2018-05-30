/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:54:04 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/22 14:54:05 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

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

double	sphere_intersect(t_vec o, t_vec dir, t_object *obj)
{
	double a;
	double b;
	double c;
	double d;
	t_vec oc;
	// printf("%f %f %f %f\n", obj->pos.x, obj->pos.y, obj->pos.z, obj->r);
	oc = vec_sub(o, obj->pos);
	a = vec_dot(dir, dir);
	b = 2 * vec_dot(oc, dir);
	c = vec_dot(oc, oc) - (obj->r * obj->r);
	// printf("%f %f %f\n", a, b, c);
	d = b * b - 4 * a * c;
	// d = DROUND(d);
	if (d < 0)
		return (-1);
	// printf("%f %f %f\n", a, b, d);
	return (get_t(a, b, d));
}

void	sphere(t_sdl *sdl, t_ray *ray, int i, t_object *obj)
{
	// double t;

	obj->t = sphere_intersect(ray->orig, ray->dir, obj);
	// printf("%f %f %f\n", sdl->obj[i].pos.x, sdl->obj[i].pos.y, sdl->obj[i].pos.z);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
	// printf("%d %f\n",sdl->clos_obj, sdl->min_t);
}













