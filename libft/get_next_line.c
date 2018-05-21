/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:34:07 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/16 15:34:09 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_new_size_alloc(char **s)
{
	char *tmp;

	if ((tmp = ft_strnew(ft_strlen(*s) + BUFF_SIZE)) != NULL)
		ft_memmove(tmp, *s, ft_strlen(*s));
	else
		return (NULL);
	free(*s);
	*s = NULL;
	return (tmp);
}

static int		ft_end_line_find(char *s, char c, int n)
{
	int k;

	k = 1;
	while (*s && n > 0)
	{
		if (*s == c)
			return (k);
		k++;
		s++;
		n--;
	}
	return (0);
}

static void		ft_after(char **line, char **str, size_t n)
{
	int		k;
	char	*tmp;

	k = 0;
	ft_bzero(*line, ft_strlen(*line));
	if ((k = ft_end_line_find(*str, '\n', n)) > 0)
	{
		ft_strncat(*line, *str, k);
		line[0][ft_strlen(*line) - 1] = '\0';
		tmp = *str;
		*str = ft_strdup(ft_memchr(*str, '\n', n) + 1);
		free(tmp);
	}
	else
	{
		ft_strncat(*line, *str, n);
		free(*str);
		*str = NULL;
	}
	*line = ft_new_size_alloc(line);
}

static int		ft_read(int fd, char **line, char **str, int i)
{
	int		k;
	char	buf[BUFF_SIZE + 1];

	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if ((k = ft_end_line_find(buf, '\n', BUFF_SIZE)) > 0)
		{
			ft_strncat(*line, buf, k);
			line[0][ft_strlen(*line) - 1] = '\0';
			if (*str == NULL)
				*str = ft_strdup(&buf[k]);
			else
				ft_strcpy(*str, &buf[k]);
			return (1);
		}
		ft_strncat(*line, buf, BUFF_SIZE);
		*line = ft_new_size_alloc(line);
		ft_bzero(buf, BUFF_SIZE);
	}
	if (i <= 0 && ft_strlen(*line) != 0)
		return (1);
	if (i == -1)
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *str[FD_AMOUNT];
	char		buf[BUFF_SIZE + 1];
	int			er;
	int			i;

	i = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || (-1 == read(fd, buf, 0)))
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (str[fd] == NULL)
	{
		if ((er = ft_read(fd, line, &str[fd], i)) == 0)
			return (0);
		if (er == -1)
			return (-1);
		return (1);
	}
	ft_after(line, &str[fd], BUFF_SIZE);
	if (str[fd] == NULL)
	{
		if ((ft_read(fd, line, &str[fd], i)) == 0)
			return (0);
		return (1);
	}
	return (1);
}
