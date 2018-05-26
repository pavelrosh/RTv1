/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:48:01 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/25 19:48:03 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

t_vec	vec_rotz(t_vec d, double a)
{
	t_vec	r;

	r.x = d.x * cos(a) - d.y * sin(a);
	r.y = d.x * sin(a) + d.y * cos(a);
	r.z = d.z;
	return (r);
}
