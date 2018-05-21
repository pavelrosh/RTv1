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

#include "rtv1.h"

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
		sdl->obj.pos.x = (double)(atoi(str[1]));
		sdl->obj.pos.y = (double)(atoi(str[2]));
		sdl->obj.pos.z = (double)(atoi(str[3]));
		sdl->obj.r = (double)(atoi(str[4]));
	}
}

void	ft_parse(char *arg, t_sdl *sdl)
{
	char	*line;
	int 	fd;
	int 	i;
	char	**spl_res;

	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_error("Can't open the file");
	i = 0; 
	line = NULL;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		spl_res = ft_strsplit(line, ' ');
		split_parse(spl_res, sdl);
		// printf("%s %s %s %s\n", spl_res[0], spl_res[1], spl_res[2], spl_res[3]);
		ft_strdel(&line);
	}
	// printf("%f %f %f\n", sdl->cam.pos.x, sdl->cam.pos.y, sdl->cam.pos.z);
	// printf("%f %f %f %f\n", sdl->obj.pos.x, sdl->obj.pos.y, sdl->obj.pos.z, sdl->obj.radius);
	close(fd);
}