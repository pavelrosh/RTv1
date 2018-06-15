/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:32:09 by proshchy          #+#    #+#             */
/*   Updated: 2018/06/15 14:10:11 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>

# include "libft.h"
# include "vec_op.h"

# include <SDL2/SDL.h>

# define DWIDTH 800
# define DHEIGHT 800
# define V_W 40
# define V_H 40
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define CONE 4
# define EPS 0.000001
# define OBJ sdl->obj[sdl->clos_obj]
# define SPL spl_res[0]
# define OBJP sdl->obj[sdl->obj_counter]

typedef	struct		s_light
{
	t_vec			pos;
	t_vec			p;
	t_vec			n;
	double			inten;
	double			new_inten;
}					t_light;

typedef struct		s_rgb
{
	unsigned char	rgb[3];
}					t_rgb;

typedef struct		s_object
{
	t_vec			pos;
	t_rgb			col;
	t_vec			rot;
	double			r;
	double			t;
	int				name;
	double			specular;
}					t_object;

typedef	struct		s_cam
{
	t_vec			pos;
	t_vec			rot;
}					t_cam;

typedef	struct		s_ray
{
	t_vec			orig;
	t_vec			dir;
}					t_ray;

typedef struct		s_sdl
{
	SDL_Window		*wind;
	SDL_Renderer	*rend;
	t_cam			cam;
	t_object		*obj;
	int				obj_num;
	int				light_num;
	int				clos_obj;
	int				obj_counter;
	int				light_counter;
	int				cam_is;
	double			min_t;
	double			ambient;
	t_light			*light;
}					t_sdl;

void				validation_init(char *arg, t_sdl *sdl, int fd, int i);
void				ft_parse(char *arg, t_sdl *sdl);
void				ft_error(char *str);
void				ray_trace_init(t_sdl *sdl, t_ray *ray);
void				get_intensity(t_sdl *sdl, t_light *light,
		t_vec v, double s);
void				sphere(t_sdl *sdl, t_ray *ray, int i, t_object *obj);
void				sphere_data(t_sdl *sdl, char **str);
double				sphere_intersect(t_vec o, t_vec dir, t_object *obj);
t_vec				sphere_normal(t_ray *ray, t_object *obj);
void				plane(t_sdl *sdl, t_ray *ray, int i, t_object *obj);
void				plane_data(t_sdl *sdl, char **str);
double				plane_intersect(t_vec o, t_vec dir, t_object *obj);
t_vec				plane_normal(t_ray *ray, t_object *obj);
void				cylinder(t_sdl *sdl, t_ray *ray, int i, t_object *obj);
void				cylinder_data(t_sdl *sdl, char **str);
double				cylinder_intersect(t_vec o, t_vec dir, t_object *obj);
t_vec				cyl_normal_calc(t_ray *ray, t_object *obj);
double				get_t(double a, double b, double d);
void				cone(t_sdl *sdl, t_ray *ray, int i, t_object *obj);
void				cone_data(t_sdl *sdl, char **str);
double				cone_intersect(t_vec o, t_vec dir, t_object *obj);
t_vec				cone_normal_calc(t_ray *ray, t_object *obj);
void				light(t_sdl *sdl, t_ray *ray);
void				cam_data(t_sdl *sdl, char **str);
void				light_data(t_sdl *sdl, char **str);
int					val_2(char *str);
#endif
