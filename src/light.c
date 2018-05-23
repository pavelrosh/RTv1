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

void	get_intensity(t_light *light, t_vec *v, double s)
{
	double	n_dot_l;
	double	r_dot_v;
	double 	ambient;
	t_vec	l;
	t_vec	r;

	light->new_inten = 0.0;
	ambient = light->ambient;
	l = vec_sub(light->pos, light->p);
	n_dot_l = vec_dot(light->n, light->n);
	if (n_dot_l > 0.000001)
		light->new_inten += ambient + light->inten * 
	n_dot_l / (vec_len(light->n) * vec_len(l));
	if (s > 0)
	{
		r = vec_scale(light->n, 2);
		r = vec_scale(r, vec_dot(light->n, l));
		r = vec_sub(r, l);
		r_dot_v = vec_dot(r, *v);
		if (r_dot_v > 0.000001)
			light->new_inten += light->inten * 
		pow((r_dot_v / (vec_len(r) * vec_len(*v))), s);
	}
}










