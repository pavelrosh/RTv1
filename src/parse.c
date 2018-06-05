/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:01:23 by proshchy          #+#    #+#             */
/*   Updated: 2018/05/17 15:01:24 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	val_1(char **str, int k)
{
	int i;

	i = 0;
	while (++i <= k)
		if ((atoi(str[i]) == 0 && str[i][0] != '0') || str[k + 1] != NULL)
			ft_error("Wrong input");
	i = -1;
	while (++i <= k)
		free(str[i]);
	free(str);
}

void	validation(char **str)
{
	int i;

	i = 0;
	if (ft_strequ(str[0], "cam:"))
		val_1(str, 6);
	else if (ft_strequ(str[0], "sphere:"))
		val_1(str, 8);	
	else if (ft_strequ(str[0], "plane:"))
		val_1(str, 10);	
	else if (ft_strequ(str[0], "cylinder:"))
		val_1(str, 11);
	else if (ft_strequ(str[0], "cone:"))
		val_1(str, 11);
	else if (ft_strequ(str[0], "light:"))
		val_1(str, 4);
	else if (ft_strequ(str[0], "ambient:"))
		val_1(str, 1);
}

void	split_parse(char **str, t_sdl *sdl)
{
	int i;

	i = -1;
	if (ft_strequ(str[0], "cam:"))
		cam_data(sdl, str);
	else if (ft_strequ(str[0], "sphere:"))
		sphere_data(sdl, str);
	else if (ft_strequ(str[0], "plane:"))
		plane_data(sdl, str);
	else if (ft_strequ(str[0], "cylinder:"))
		cylinder_data(sdl, str);
	else if (ft_strequ(str[0], "cone:"))
		cone_data(sdl, str);
	else if (ft_strequ(str[0], "light:"))
		light_data(sdl, str);
	else if (ft_strequ(str[0], "ambient:"))
	{
		sdl->ambient = (double)(atoi(str[1])) / 100;
		while (++i <= 1)
			free(str[i]);
		free(str);
	}
}

void	obj_counter(char *arg, t_sdl *sdl)
{
	char	*line;
	int 	fd;
	int 	i;
	int 	cam_is;
	char	**spl_res;

	i = 0;
	cam_is = 0;
	line = NULL;
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_error("Can't open the file");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		spl_res = ft_strsplit(line, ' ');
		if (ft_strequ(spl_res[0], "sphere:") || ft_strequ(spl_res[0], "plane:") ||
		 ft_strequ(spl_res[0], "cylinder:") || ft_strequ(spl_res[0], "cone:"))
			sdl->obj_num++;
		else if (ft_strequ(spl_res[0], "light:"))
			sdl->light_num++;
		else if (ft_strequ(spl_res[0], "cam:"))
			cam_is++;
		validation(spl_res);
		ft_strdel(&line);
	}
	if (cam_is != 1)
		ft_error("Have no camera");
	close(fd);
}

void	ft_parse(char *arg, t_sdl *sdl, t_ray *ray)
{
	char	*line;
	int 	fd;
	int 	i;
	char	**spl_res;

	i = 0;
	line = NULL;
	sdl->obj_num = 0;
	sdl->light_num = 0;
	sdl->obj_counter = 0;
	sdl->light_counter = 0;
	obj_counter(arg, sdl);
	sdl->obj = malloc(sizeof(t_object) * sdl->obj_num + 1);
	sdl->light = malloc(sizeof(t_light) * sdl->light_num + 1);
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_error("Can't open the file");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		spl_res = ft_strsplit(line, ' ');
		split_parse(spl_res, sdl);
		ft_strdel(&line);
	}
	ray->orig.x = sdl->cam.pos.x;
	ray->orig.y = sdl->cam.pos.y;
	ray->orig.z = sdl->cam.pos.z;
}