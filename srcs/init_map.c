/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 03:38:38 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/12 03:38:48 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../includes/fdf.h"

static int	fill_y(int fd, t_map **map)
{
	int		ret;
	char	*line;

	(*map)->max_y = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret == -1)
		{
			free(line);
			return (0);
		}
		(*map)->max_y++;
		free(line);
	}
	close(fd);
	return (1);
}

static int	count_nb(char **av, char **split, t_map **map, int count)
{
	int		i;
	int		tmp;
	char	*line;

	(*map)->nb = 0;
	if ((tmp = open(av[1], O_RDONLY)) < 1)
		return (0);
	if (!((*map)->max = (int *)malloc(sizeof(int) * (*map)->max_y)))
		return (free_all(NULL, NULL, tmp));
	while ((i = get_next_line(tmp, &line)) > 0)
	{
		if (i == -1)
			return (free_all(NULL, line, tmp));
		if (!(split = ft_strsplit(line, ' ')))
			return (free_all(NULL, line, tmp));
		i = -1;
		while (split[++i])
			(*map)->nb++;
		(*map)->max[count++] = i;
		free_all(split, line, 0);
	}
	if ((*map)->nb < 2)
		return (0);
	return (1);
}

static int	fill_map(t_map **map, int fd, int i, char **split)
{
	int		j;
	int		k;

	j = 0;
	while (split[j])
	{
		k = 0;
		while (split[j][k])
		{
			if ((!(ft_isdigit((int)split[j][k]))) && split[j][k] != '-')
				return (free_all(split, NULL, fd));
			k++;
		}
		(*map)->map[i][j].z = ft_atoi(split[j]);
		(*map)->map[i][j].x = j;
		(*map)->map[i][j].y = i;
		j++;
	}
	return (1);
}

int			split1(int tmp, t_map **map, char **split, int i)
{
	int		j;
	char	*line;

	while ((j = get_next_line(tmp, &line)) > 0)
	{
		if (j == -1)
		{
			free(line);
			return (0);
		}
		if (ft_strlen(line))
		{
			if (!((*map)->map[i] = (t_point *)malloc(sizeof(t_point) *
							(*map)->max[i])))
				return (free_all(split, line, tmp));
			if (!(split = ft_strsplit(line, ' ')))
				return (free_all(NULL, line, tmp));
			if (!(fill_map(map, tmp, i++, split)))
				return (0);
			free_all(split, line, 0);
		}
		else
			return (free_all(NULL, line, 0));
	}
	return (1);
}

t_map		*init_map(t_data data, int fd, int tmp, char **av)
{
	int		i;
	char	**split;
	t_map	*map;

	i = 0;
	if (!(map = malloc(sizeof(t_map))))
		return (0);
	if (!(fill_y(fd, &map)))
		return (0);
	if (!(count_nb(av, split, &map, 0)))
		return (0);
	if (!((map->map = (t_point **)malloc(sizeof(t_point *) * map->max_y))))
		return (0);
	if (!(split1(tmp, &map, split, 0)))
		return (0);
	return (map);
}
