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