/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:21:06 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/30 19:21:07 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

double	cylinder_intersect(t_vec o, t_vec dir, t_object *obj)
{
	double 	a;
	double 	b;
	double 	c;
	double 	d;
	t_vec 	x;

	x = vec_sub(o, obj->pos);
	a = vec_dot(dir, dir) - pow(vec_dot(dir, obj->rot), 2);
	b = 2 * (vec_dot(dir, x) - (vec_dot(dir, obj->rot) * vec_dot(x, obj->rot)));
	c = vec_dot(x, x) - pow(vec_dot(x, obj->rot), 2) - pow(obj->r, 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	return (get_t(a, b, d));
}

void	normal_calc()
{

}

void	cylinder(t_sdl *sdl, t_ray *ray, int i, t_object *obj)
{
	obj->t = cylinder_intersect(ray->orig, ray->dir, obj);
	// printf("%f %f %f\n", sdl->obj[i].pos.x, sdl->obj[i].pos.y, sdl->obj[i].pos.z);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
		normal_calc(ray, obj);
	}
	// printf("%d %f\n",sdl->clos_obj, sdl->min_t);
}
