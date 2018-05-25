/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:16:21 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/22 17:16:22 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

double	get_ts(double a, double b, double d)
{
	double t1;
	double t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if (t1 >= t2)
		return (t1);
	else
		return (t2);
	return (-1);
}

double	sphere_s_intersect(t_vec o, t_vec dir, t_object *obj)
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
	return (get_ts(a, b, d));
}

int 	shadow_init(t_light *light, t_sdl *sdl)
{
	int 	i;
	double	max_t; //distance between light and hit point
	double 	t;
	t_vec	dir;

	i = 0;
	t = 0;
	// printf("%f %f %f\n", light->pos.x, light->pos.y, light->pos.z);
	// printf("%f %f %f\n", light->p.x, light->p.y, light->p.z);
	max_t = vec_len(vec_sub(light->pos, light->p));
	// printf("distance :%f\n", max_t);
	dir = vec_norm(vec_sub(light->pos, light->p));
	// printf("%f %f %f\n", dir.x, dir.y, dir.z);
	// printf("%f %f %f\n", light->p.x, light->p.y, light->p.z);
	// light->p = vec_scale(light->p, 1.01); // scale
	light->p = vec_sum(light->p, vec_scale(dir, 2.0)); //2.0 is a value defined by selection
	// printf("%f %f %f\n", light->p.x, light->p.y, light->p.z);
	while (i < sdl->obj_num)
	{
		if (sdl->obj[i].name == SPHERE)
		{
			t = sphere_intersect(light->p, dir, &sdl->obj[i]);
			// printf("%f\n", t);
			if (t > 0.00001 && t < max_t)
				return (1);
		}
		i++;
	}
	return (0);
}

void	get_intensity(t_sdl *sdl, t_light *light, t_vec v, double s)
{
	double	n_dot_l;
	double	r_dot_v;
	double 	ambient;
	double 	inten;
	t_vec	l;
	t_vec	r;

	light->new_inten = 0.0;
	inten = 0.0;
	l = vec_sub(light->pos, light->p);
	n_dot_l = vec_dot(light->n, light->n);
	if (shadow_init(light, sdl) == 0)
	{
		inten = light->inten;
		ambient = light->ambient;
	}
	else
		ambient = light->ambient;
	if (n_dot_l > 0.000001)
		light->new_inten += ambient + inten * 
	n_dot_l / (vec_len(light->n) * vec_len(l));
	if (s > 0.000001)
	{
		r = vec_scale(light->n, 2);
		r = vec_scale(r, vec_dot(light->n, l));
		r = vec_sub(r, l);
		r_dot_v = vec_dot(r, v);
		if (r_dot_v > 0.000001)
			light->new_inten += inten * 
		pow((r_dot_v / (vec_len(r) * vec_len(v))), s);
	}
}







