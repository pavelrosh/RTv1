/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:16:21 by proshchy          #+#    #+#             */
/*   Updated: 2018/06/07 16:45:10 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	light_data(t_sdl *sdl, char **str)
{
	int i;

	i = -1;
	sdl->light[sdl->light_counter].pos.x = (double)(atoi(str[1]));
	sdl->light[sdl->light_counter].pos.y = (double)(atoi(str[2]));
	sdl->light[sdl->light_counter].pos.z = (double)(atoi(str[3]));
	sdl->light[sdl->light_counter].inten = (double)(atoi(str[4])) / 100;
	if (sdl->light[sdl->light_counter].inten < 0)
		ft_error("Wrong intensity parameter");
	sdl->light_counter++;
	while (++i <= 4)
		free(str[i]);
	free(str);
}

int		shadow_init(t_light *light, t_sdl *sdl)
{
	int		i;
	double	max_t;
	double	t;
	t_vec	dir;

	i = -1;
	t = 0;
	max_t = vec_len(vec_sub(light->pos, light->p));
	dir = vec_norm(vec_sub(light->pos, light->p));
	light->p = vec_sum(light->p, vec_scale(dir, EPS));
	while (++i < sdl->obj_num)
	{
		if (sdl->obj[i].name == SPHERE)
			t = sphere_intersect(light->p, dir, &sdl->obj[i]);
		else if (sdl->obj[i].name == PLANE)
			t = plane_intersect(light->p, dir, &sdl->obj[i]);
		else if (sdl->obj[i].name == CONE)
			t = cone_intersect(light->p, dir, &sdl->obj[i]);
		else if (sdl->obj[i].name == CYLINDER)
			t = cylinder_intersect(light->p, dir, &sdl->obj[i]);
		if (t > 0.00001 && t < max_t)
			return (1);
	}
	return (0);
}

void	get_intensity(t_sdl *sdl, t_light *light, t_vec v, double s)
{
	double	n_dot_l;
	double	r_dot_v;
	double	inten;
	t_vec	l;
	t_vec	r;

	light->new_inten = sdl->ambient;
	inten = 0.0;
	l = vec_norm(vec_sub(light->pos, light->p));
	n_dot_l = vec_dot(light->n, l);
	if (shadow_init(light, sdl) == 0)
		inten = light->inten;
	if (n_dot_l > EPS)
		light->new_inten += inten * (n_dot_l / (vec_len(light->n) *
					vec_len(l)));
	if (s > 0)
	{
		r = vec_scale(light->n, 2);
		r = vec_scale(r, vec_dot(light->n, l));
		r = vec_sub(r, l);
		r_dot_v = vec_dot(r, v);
		if (r_dot_v > EPS)
			light->new_inten += inten * pow((r_dot_v / (vec_len(r) *
							vec_len(v))), s);
	}
}

void	light(t_sdl *sdl, t_ray *ray)
{
	int	i;

	i = 0;
	if (sdl->clos_obj > -1)
	{
		while (i < sdl->light_num)
		{
			sdl->light[i].p = vec_sum(ray->orig, vec_scale(ray->dir, OBJ.t));
			if (OBJ.name == SPHERE)
				sdl->light[i].n = sphere_normal(ray, &OBJ);
			else if (OBJ.name == PLANE)
				sdl->light[i].n = OBJ.rot;
			else if (OBJ.name == CYLINDER)
				sdl->light[i].n = cyl_normal_calc(ray, &OBJ);
			else if (OBJ.name == CONE)
				sdl->light[i].n = cone_normal_calc(ray, &OBJ);
			get_intensity(sdl, &sdl->light[i], vec_scale(ray->dir, -1),
					OBJ.specular);
			i++;
		}
	}
}
