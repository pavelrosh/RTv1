/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:21:06 by proshchy          #+#    #+#             */
/*   Updated: 2018/06/15 14:12:18 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	cylinder_data(t_sdl *sdl, char **str)
{
	int i;

	i = -1;
	OBJP.pos.x = (double)(atoi(str[1]));
	OBJP.pos.y = (double)(atoi(str[2]));
	OBJP.pos.z = (double)(atoi(str[3]));
	OBJP.r = (double)(atoi(str[4])) / 10;
	OBJP.rot.x = (double)(atoi(str[5]));
	OBJP.rot.y = (double)(atoi(str[6]));
	OBJP.rot.z = (double)(atoi(str[7]));
	if (OBJP.r < 0.1 || atoi(str[8]) < 0 || atoi(str[9]) < 0
		|| atoi(str[10]) < 0)
		ft_error("Wrong input for cylinder");
	OBJP.col.rgb[0] = (unsigned char)(atoi(str[8]));
	OBJP.col.rgb[1] = (unsigned char)(atoi(str[9]));
	OBJP.col.rgb[2] = (unsigned char)(atoi(str[10]));
	OBJP.specular = (double)(atoi(str[11]));
	OBJP.name = CYLINDER;
	sdl->obj_counter++;
	while (++i <= 11)
		free(str[i]);
	free(str);
}

double	cylinder_intersect(t_vec o, t_vec dir, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	x;

	x = vec_sub(o, obj->pos);
	a = vec_dot(dir, dir) - pow(vec_dot(dir, obj->rot), 2);
	b = 2 * (vec_dot(dir, x) - (vec_dot(dir, obj->rot) * vec_dot(x, obj->rot)));
	c = vec_dot(x, x) - pow(vec_dot(x, obj->rot), 2) - pow(obj->r, 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	return (get_t(a, b, d));
}

t_vec	cyl_normal_calc(t_ray *ray, t_object *obj)
{
	double	m;
	t_vec	n;
	t_vec	p;

	m = obj->t * vec_dot(ray->dir, obj->rot) +
	vec_dot(vec_sub(ray->orig, obj->pos), obj->rot);
	p = vec_sum(ray->orig, vec_scale(ray->dir, obj->t));
	n = vec_norm(vec_sub(vec_sub(p, obj->pos), vec_scale(obj->rot, m)));
	if (vec_dot(ray->dir, n) > EPS)
		n = vec_scale(n, -1);
	return (n);
}

void	cylinder(t_sdl *sdl, t_ray *ray, int i, t_object *obj)
{
	obj->t = cylinder_intersect(ray->orig, ray->dir, obj);
	obj->rot = vec_norm(obj->rot);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
}
