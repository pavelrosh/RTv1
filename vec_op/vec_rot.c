/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 03:13:49 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/26 03:13:51 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_op.h"

t_vec	vec_rot(t_vec d, t_vec r)
{
	t_vec res;

	res = vec_rotx(d, DTR(r.x));
	res = vec_roty(d, DTR(r.y));
	res = vec_rotz(d, DTR(r.z));
	return (res);
}