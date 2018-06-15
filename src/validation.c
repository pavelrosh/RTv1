/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:18:34 by proshchy          #+#    #+#             */
/*   Updated: 2018/06/08 16:11:06 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	val_1(char **str, int k)
{
	int i;

	i = 0;
	while (++i <= k)
		if (!str[i] || (atoi(str[i]) == 0 && str[i][0] != '0') ||
				str[k + 1] != NULL || !val_2(str[i]))
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

int		line_valid(char *line)
{
	if (ft_strncmp("cam: ", line, 5) == 0)
		return (1);
	if (ft_strncmp("light: ", line, 7) == 0)
		return (1);
	if (ft_strncmp("sphere: ", line, 8) == 0)
		return (1);
	if (ft_strncmp("cone: ", line, 6) == 0)
		return (1);
	if (ft_strncmp("cylinder: ", line, 10) == 0)
		return (1);
	if (ft_strncmp("plane: ", line, 7) == 0)
		return (1);
	if (ft_strncmp("ambient: ", line, 9) == 0)
		return (1);
	return (0);
}

void	obj_counter(t_sdl *sdl, char **spl_res)
{
	if (ft_strequ(SPL, "sphere:") || ft_strequ(SPL, "plane:") ||
		ft_strequ(SPL, "cylinder:") || ft_strequ(SPL, "cone:"))
		sdl->obj_num++;
	else if (ft_strequ(SPL, "light:"))
		sdl->light_num++;
	else if (ft_strequ(SPL, "cam:"))
		sdl->cam_is++;
}

void	validation_init(char *arg, t_sdl *sdl, int fd, int i)
{
	char	*line;
	char	**spl_res;

	line = NULL;
	sdl->cam_is = 0;
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_error("Can't open the file");
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (line_valid(line) == 0)
			ft_error("Wrong input");
		spl_res = ft_strsplit(line, ' ');
		ft_strdel(&line);
		obj_counter(sdl, spl_res);
		validation(spl_res);
	}
	ft_strdel(&line);
	if (sdl->cam_is != 1)
		ft_error("Have no camera");
	if (sdl->light_num == 0)
		ft_error("Have no light");
	if (sdl->obj_num < 1)
		ft_error("Have no objects");
	close(fd);
}
