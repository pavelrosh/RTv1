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
# define FOV 60.0
# define SPHERE 1
// # define ABS(x)		(x) > 0 ? (x) : -(x)
// # define DROUND(d)	ABS(d) < 0.00001 ? 0 : (d)

typedef struct 		s_object
{
	t_vec			pos;
	double			r;
	double 			t;
	int				name;
}					t_object;

typedef	struct 		s_cam
{
	t_vec			pos;
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
}					t_sdl;

void				ft_parse(char *arg, t_sdl *sdl, t_ray *ray);
void				ft_error(char *str);
void				ray_trace_init(t_sdl *sdl, t_ray *ray);

#endif















