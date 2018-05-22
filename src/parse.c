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

void	split_parse(char **str, t_sdl *sdl)
{
	if (ft_strequ(str[0], "cam:"))
	{
		sdl->cam.pos.x = (double)(atoi(str[1]));
		sdl->cam.pos.y = (double)(atoi(str[2]));
		sdl->cam.pos.z = (double)(atoi(str[3]));
	}
	else if (ft_strequ(str[0], "sphere:"))
	{
		sdl->obj[sdl->obj_num].pos.x = (double)(atoi(str[1]));
		sdl->obj[sdl->obj_num].pos.y = (double)(atoi(str[2]));
		sdl->obj[sdl->obj_num].pos.z = (double)(atoi(str[3]));
		sdl->obj[sdl->obj_num].r = (double)(atoi(str[4]));
		sdl->obj[sdl->obj_num].col.rgb[0] = (unsigned char)(atoi(str[5]));
		sdl->obj[sdl->obj_num].col.rgb[1] = (unsigned char)(atoi(str[6]));
		sdl->obj[sdl->obj_num].col.rgb[2] = (unsigned char)(atoi(str[7]));
		sdl->obj[sdl->obj_num].name = SPHERE;
		sdl->obj_num++;
	}
	else if (ft_strequ(str[0], "light:"))
	{
		sdl->light.pos.x = (double)(atoi(str[1]));
		sdl->light.pos.y = (double)(atoi(str[2]));
		sdl->light.pos.z = (double)(atoi(str[3]));
		sdl->light.inten = (double)(atoi(str[4])) / 100;
	}
}

void	ft_parse(char *arg, t_sdl *sdl, t_ray *ray)
{
	char	*line;
	int 	fd;
	int 	i;
	char	**spl_res;

	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_error("Can't open the file");
	i = 0;
	line = NULL;
	sdl->obj_num = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		spl_res = ft_strsplit(line, ' ');
		split_parse(spl_res, sdl);
		// printf("%s %s %s %s\n", spl_res[0], spl_res[1], spl_res[2], spl_res[3]);
		ft_strdel(&line);
	}
	ray->orig.x = sdl->cam.pos.x;
	ray->orig.y = sdl->cam.pos.y;
	ray->orig.z = sdl->cam.pos.z;
	// printf("%f %f %f\n", sdl->cam.pos.x, sdl->cam.pos.y, sdl->cam.pos.z);
	// printf("%f %f %f %f %u %u %u\n", sdl->obj[0].pos.x, sdl->obj[0].pos.y, 
		// sdl->obj[0].pos.z, sdl->obj[0].r, sdl->obj[0].col.rgb[0], sdl->obj[0].col.rgb[1], sdl->obj[0].col.rgb[2]);
	// printf("%d\n", sdl->obj_num);
	// printf("%f %f %f %f\n", sdl->light.pos.x, sdl->light.pos.y, sdl->light.pos.z, sdl->light.inten);
	close(fd);
}