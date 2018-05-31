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

int 	shadow_init(t_light *light, t_sdl *sdl)
{
	int 	i;
	double	max_t; //distance between light and hit point
	double 	t;
	t_vec	dir;

	i = 0;
	t = 0;
	max_t = vec_len(vec_sub(light->pos, light->p));
	dir = vec_norm(vec_sub(light->pos, light->p));
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
		else if (sdl->obj[i].name == PLANE)
		{
			t = plane_intersect(light->p, dir, &sdl->obj[i]);
			// printf("%f\n", t);
			if (t > 0.00001 && t < max_t)
				return (1);
		}
		else if (sdl->obj[i].name == CONE)
		{
			t = cone_intersect(light->p, dir, &sdl->obj[i]);
			// printf("%f\n", t);
			if (t > 0.00001 && t < max_t)
				return (1);
		}
		else if (sdl->obj[i].name == CYLINDER)
		{
			t = cylinder_intersect(light->p, dir, &sdl->obj[i]);
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
		ambient = sdl->ambient;
	}
	else
		ambient = sdl->ambient;
	if (n_dot_l > 0.000001)
		light->new_inten += ambient + inten * 
	(n_dot_l / (vec_len(light->n) * vec_len(l)));
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

void	light(t_sdl *sdl, t_ray *ray)
{
	int i;

	i = 0;
	if (sdl->clos_obj > -1)
	{
		while (i < sdl->light_num)
		{
			sdl->light[i].p = vec_sum(ray->orig, vec_scale(ray->dir, OBJ.t));
			if (OBJ.name == SPHERE)	
				sdl->light[i].n = vec_norm(vec_sub(sdl->light[i].p, OBJ.pos));
			else if (OBJ.name == PLANE)
				sdl->light[i].n = OBJ.rot;
			else if (OBJ.name == CYLINDER)
				sdl->light[i].n = cyl_normal_calc(ray, &OBJ);
			else if (OBJ.name == CONE)
				sdl->light[i].n = cone_normal_calc(ray, &OBJ);
			get_intensity(sdl, &sdl->light[i], vec_scale(ray->dir, -1), OBJ.specular);
			i++;
		}
		// here should be calculate sum of all light intensity
	}
}







































