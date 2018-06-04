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
}

void	validation(char **str)
{
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
	{
		sdl->light[sdl->light_counter].pos.x = (double)(atoi(str[1]));
		sdl->light[sdl->light_counter].pos.y = (double)(atoi(str[2]));
		sdl->light[sdl->light_counter].pos.z = (double)(atoi(str[3]));
		sdl->light[sdl->light_counter].inten = (double)(atoi(str[4])) / 100;
		sdl->light_counter++;
	}
	else if (ft_strequ(str[0], "ambient:"))
		sdl->ambient = (double)(atoi(str[1])) / 100;
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
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_error("Can't open the file");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		spl_res = ft_strsplit(line, ' ');
		validation(spl_res);
		if (ft_strequ(spl_res[0], "sphere:") || ft_strequ(spl_res[0], "plane:") ||
		 ft_strequ(spl_res[0], "cylinder:") || ft_strequ(spl_res[0], "cone:"))
			sdl->obj_num++;
		else if (ft_strequ(spl_res[0], "light:"))
			sdl->light_num++;
		else if (ft_strequ(spl_res[0], "cam:"))
			cam_is++;
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
	// printf("%d %d\n", sdl->obj_num, sdl->light_num);
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_error("Can't open the file");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		// printf("%s\n", line);
		spl_res = ft_strsplit(line, ' ');
		split_parse(spl_res, sdl);
		ft_strdel(&line);
	}
	ray->orig.x = sdl->cam.pos.x;
	ray->orig.y = sdl->cam.pos.y;
	ray->orig.z = sdl->cam.pos.z;
	// printf("%f %f %f %f %f %f\n", sdl->cam.pos.x, sdl->cam.pos.y, sdl->cam.pos.z,
		// sdl->cam.rot.x, sdl->cam.rot.y, sdl->cam.rot.z);
	// printf("%f %f %f %f %f %f %f %u %u %u %f\n", sdl->obj[0].pos.x, sdl->obj[0].pos.y, 
		// sdl->obj[0].pos.z, sdl->obj[0].r, sdl->obj[0].rot.x, sdl->obj[0].rot.y, sdl->obj[0].rot.z, sdl->obj[0].col.rgb[0], 
		// sdl->obj[0].col.rgb[1], sdl->obj[0].col.rgb[2], sdl->obj[0].specular);
	// printf("%d\n", sdl->obj_num);
	// printf("%f %f %f %f\n", sdl->light.pos.x, sdl->light.pos.y, sdl->light.pos.z, sdl->light.inten);
	close(fd);
}