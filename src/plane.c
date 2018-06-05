/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:19:22 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/23 17:19:24 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	plane_data(t_sdl *sdl, char **str)
{
	int i;

	i = -1;
	sdl->obj[sdl->obj_counter].pos.x = (double)(atoi(str[1]));
	sdl->obj[sdl->obj_counter].pos.y = (double)(atoi(str[2]));
	sdl->obj[sdl->obj_counter].pos.z = (double)(atoi(str[3]));
	sdl->obj[sdl->obj_counter].rot.x = (double)(atoi(str[4]));
	sdl->obj[sdl->obj_counter].rot.y = (double)(atoi(str[5]));
	sdl->obj[sdl->obj_counter].rot.z = (double)(atoi(str[6]));
	sdl->obj[sdl->obj_counter].col.rgb[0] = (unsigned char)(atoi(str[7]));
	sdl->obj[sdl->obj_counter].col.rgb[1] = (unsigned char)(atoi(str[8]));
	sdl->obj[sdl->obj_counter].col.rgb[2] = (unsigned char)(atoi(str[9]));
	sdl->obj[sdl->obj_counter].specular = (double)(atoi(str[10]));
	sdl->obj[sdl->obj_counter].name = PLANE;
	sdl->obj_counter++;
	while (++i <= 10)
		free(str[i]);
	free(str);
}
//normalize
//t = -X | V / D | V
t_vec	plane_normal(t_ray *ray, t_object *obj)
{
	if (vec_dot(ray->dir, obj->rot) < 0)
		return (obj->rot);
	return(vec_scale(obj->rot, -1));
}

double	plane_intersect(t_vec o, t_vec dir, t_object *obj)
{
	double 	t;
	double 	a;
	double 	b;
	t_vec	x;

	x = vec_sub(o, obj->pos);
	// printf("%f %f %f\n", x.x, x.y, x.z);
	a = vec_dot(x, obj->rot);
	b = vec_dot(dir, obj->rot);
	// printf("%f %f\n", a, b);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (-1);
	t = -a / b;
	// printf("%f\n", t);
	if (t > EPS)
		return (t);
	return (-1);
}

void	plane(t_sdl *sdl, t_ray *ray, int i, t_object *obj)
{
	obj->rot = vec_norm(obj->rot);
	obj->t = plane_intersect(ray->orig, ray->dir, obj);
	// printf("%f\n", obj->t);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		// printf("%s\n", "close obj == plane");
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
}
