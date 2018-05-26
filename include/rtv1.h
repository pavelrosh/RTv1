/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:32:09 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/16 13:32:10 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>

# include "../libft/libft.h"
# include "../vec_op/vec_op.h"

# include <SDL2/SDL.h>

# define DWIDTH 800
# define DHEIGHT 800
# define V_W 40
# define V_H 40
// # define FOV 60.0
# define SPHERE 1
# define PLANE 2
// # define ABS(x)		(x) > 0 ? (x) : -(x)
// # define DROUND(d)	ABS(d) < 0.00001 ? 0 : (d)

typedef	struct 		s_light
{
	t_vec			pos;
	t_vec			p;
	t_vec			n;
	double			inten;
	double			ambient;
	double			new_inten;
}					t_light;

typedef struct 		s_rgb
{
	unsigned char  	rgb[3];
}					t_rgb;

typedef struct 		s_object
{
	t_vec			pos;
	t_rgb			col;
	t_vec			v;
	double			r;
	double 			t;
	int				name;
	double			specular;
}					t_object;

typedef	struct 		s_cam
{
	t_vec			pos;
	t_vec			rot;
}					t_cam;

typedef	struct 		s_ray
{
	t_vec			orig;
	t_vec			dir;
}					t_ray;

typedef struct 		s_sdl
{
	SDL_Window 		*wind;
	SDL_Renderer 	*rend;
	t_cam			cam;
	t_object		*obj;
	int 			obj_num;
	t_light			light;

}					t_sdl;

void				ft_parse(char *arg, t_sdl *sdl, t_ray *ray);
void				ft_error(char *str);
void				ray_trace_init(t_sdl *sdl, t_ray *ray);
double				sphere_intersect(t_vec o, t_vec dir, t_object *obj);
double				get_t(double a, double b, double d);
void				get_intensity(t_sdl *sdl, t_light *light, t_vec v, double s);

#endif
















