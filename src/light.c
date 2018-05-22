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

void	get_intensity(t_light *light)
{
	double	n_dot_l;
	t_vec	l;

	light->new_inten = 0.0;
	l = vec_sub(light->pos, light->p);
	n_dot_l = vec_dot(light->n, light->n);
	if (n_dot_l > 0)
		light->new_inten += light->inten * n_dot_l / (vec_len(light->n) * vec_len(l));
}
