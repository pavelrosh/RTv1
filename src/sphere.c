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

void	sphere_data(t_sdl *sdl, char **str)
{
	sdl->obj[sdl->obj_counter].pos.x = (double)(atoi(str[1]));
	sdl->obj[sdl->obj_counter].pos.y = (double)(atoi(str[2]));
	sdl->obj[sdl->obj_counter].pos.z = (double)(atoi(str[3]));
	sdl->obj[sdl->obj_counter].r = (double)(atoi(str[4])) / 10;
	sdl->obj[sdl->obj_counter].col.rgb[0] = (unsigned char)(atoi(str[5]));
	sdl->obj[sdl->obj_counter].col.rgb[1] = (unsigned char)(atoi(str[6]));
	sdl->obj[sdl->obj_counter].col.rgb[2] = (unsigned char)(atoi(str[7]));
	sdl->obj[sdl->obj_counter].specular = (double)(atoi(str[8]));
	sdl->obj[sdl->obj_counter].name = SPHERE;
	sdl->obj_counter++;
}

t_vec	sphere_normal(t_ray *ray, t_object *obj)
{
	t_vec n;
	n = vec_sum(ray->orig, vec_scale(ray->dir, obj->t));
	n = vec_norm(vec_sub(n, obj->pos));
	if (vec_dot(ray->dir, n) > EPS)
		n = vec_scale(n, -1);
	return (n);
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













