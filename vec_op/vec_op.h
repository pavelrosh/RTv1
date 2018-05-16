/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:23:42 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/15 17:23:44 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_OP_H
# define VEC_OP_H

# include <math.h>

typedef struct 	s_vec
{
	double x;
	double y;
	double z;
}				t_vec;

t_vec	vec_sum(t_vec v1, t_vec v2);
double	vec_dot(t_vec v1, t_vec v2);
double	vec_len(t_vec v1);
t_vec	vec_scale(t_vec v1, double t);
t_vec	vec_norm(t_vec v1);
t_vec	vec_sub(t_vec v1, t_vec v2);
#endif
