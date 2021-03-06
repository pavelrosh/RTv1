/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:47:41 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/25 19:47:43 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

t_vec	vec_rotx(t_vec d, double a)
{
	t_vec r;

	r.x = d.x;
	r.y = d.y * cos(a) - d.z * sin(a);
	r.z = d.y * sin(a) + d.z * cos(a);
	return (r);
}
