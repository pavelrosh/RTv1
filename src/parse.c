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

void	sphere_data(t_sdl *sdl, char **str)
{
	sdl->obj[sdl->obj_counter].pos.x = (double)(atoi(str[1]));
	sdl->obj[sdl->obj_counter].pos.y = (double)(atoi(str[2]));
	sdl->obj[sdl->obj_counter].pos.z = (double)(atoi(str[3]));
	sdl->obj[sdl->obj_counter].r = (double)(atoi(str[4]));
	sdl->obj[sdl->obj_counter].col.rgb[0] = (unsigned char)(atoi(str[5]));
	sdl->obj[sdl->obj_counter].col.rgb[1] = (unsigned char)(atoi(str[6]));
	sdl->obj[sdl->obj_counter].col.rgb[2] = (unsigned char)(atoi(str[7]));
	sdl->obj[sdl->obj_counter].specular = (double)(atoi(str[8]));
	sdl->obj[sdl->obj_counter].name = SPHERE;
	sdl->obj_counter++;
}

void	plane_data(t_sdl *sdl, char **str)
{
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
}

void	cylinder_data(t_sdl *sdl, char **str)
{
	sdl->obj[sdl->obj_counter].pos.x = (double)(atoi(str[1]));
	sdl->obj[sdl->obj_counter].pos.y = (double)(atoi(str[2]));
	sdl->obj[sdl->obj_counter].pos.z = (double)(atoi(str[3]));
	sdl->obj[sdl->obj_counter].r = (double)(atoi(str[4]));
	sdl->obj[sdl->obj_counter].rot.x = (double)(atoi(str[5]));
	sdl->obj[sdl->obj_counter].rot.y = (double)(atoi(str[6]));
	sdl->obj[sdl->obj_counter].rot.z = (double)(atoi(str[7]));
	sdl->obj[sdl->obj_counter].col.rgb[0] = (unsigned char)(atoi(str[8]));
	sdl->obj[sdl->obj_counter].col.rgb[1] = (unsigned char)(atoi(str[9]));
	sdl->obj[sdl->obj_counter].col.rgb[2] = (unsigned char)(atoi(str[10]));
	sdl->obj[sdl->obj_counter].specular = (double)(atoi(str[11]));
	sdl->obj[sdl->obj_counter].name = CYLINDER;
	sdl->obj_counter++;
}

void	cone_data(t_sdl *sdl, char **str)
{
	sdl->obj[sdl->obj_counter].pos.x = (double)(atoi(str[1]));
	sdl->obj[sdl->obj_counter].pos.y = (double)(atoi(str[2]));
	sdl->obj[sdl->obj_counter].pos.z = (double)(atoi(str[3]));
	sdl->obj[sdl->obj_counter].r = (double)(atoi(str[4]));
	sdl->obj[sdl->obj_counter].rot.x = (double)(atoi(str[5]));
	sdl->obj[sdl->obj_counter].rot.y = (double)(atoi(str[6]));
	sdl->obj[sdl->obj_counter].rot.z = (double)(atoi(str[7]));
	sdl->obj[sdl->obj_counter].col.rgb[0] = (unsigned char)(atoi(str[8]));
	sdl->obj[sdl->obj_counter].col.rgb[1] = (unsigned char)(atoi(str[9]));
	sdl->obj[sdl->obj_counter].col.rgb[2] = (unsigned char)(atoi(str[10]));
	sdl->obj[sdl->obj_counter].specular = (double)(atoi(str[11]));
	sdl->obj[sdl->obj_counter].name = CONE;
	sdl->obj_counter++;
}

void	split_parse(char **str, t_sdl *sdl)
{
	if (ft_strequ(str[0], "cam:"))
	{
		sdl->cam.pos.x = (double)(atoi(str[1]));
		sdl->cam.pos.y = (double)(atoi(str[2]));
		sdl->cam.pos.z = (double)(atoi(str[3]));
		sdl->cam.rot.x = (double)(atoi(str[4]));
		sdl->cam.rot.y = (double)(atoi(str[5]));
		sdl->cam.rot.z = (double)(atoi(str[6]));
	}
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
	char	**spl_res;

	i = 0;
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
	}
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

























