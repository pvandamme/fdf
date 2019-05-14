/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 03:13:55 by rmerien           #+#    #+#             */
/*   Updated: 2018/12/16 03:37:36 by rmerien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	add_proj(t_data data, t_map *map, int proj)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->max_y)
	{
		j = 0;
		while (j < map->max[i])
		{
			get_projection(data, map, i, j);
			j++;
		}
		i++;
	}
}

t_map	cpy_map(t_map map)
{
	int		i;
	int		j;
	t_map	cpy;

	i = -1;
	cpy.max_y = map.max_y;
	cpy.max = (int *)malloc(sizeof(int) * map.max_y);
	while (++i < map.max_y)
		cpy.max[i] = map.max[i];
	i = -1;
	cpy.map = (t_point **)malloc(sizeof(t_point *) * map.max_y);
	while (++i < map.max_y)
	{
		j = -1;
		cpy.map[i] = (t_point *)malloc(sizeof(t_point) * map.max[i]);
		while (++j < map.max[i])
		{
			cpy.map[i][j].z = map.map[i][j].z;
			cpy.map[i][j].x = map.map[i][j].x;
			cpy.map[i][j].y = map.map[i][j].y;
		}
	}
	return (cpy);
}

void	call_print(t_map cpy, t_id *id, t_coo xy, int i)
{
	int		j;

	j = -1;
	while (++j < cpy.max[i])
	{
		xy.x1 = cpy.map[i][j].x;
		xy.y1 = cpy.map[i][j].y;
		if (j < cpy.max[i] - 1)
		{
			xy.x2 = cpy.map[i][j + 1].x;
			xy.y2 = cpy.map[i][j + 1].y;
			pv(id, xy, id->data.color);
		}
		if (i < cpy.max_y - 1 && j < cpy.max[i + 1])
		{
			xy.x2 = cpy.map[i + 1][j].x;
			xy.y2 = cpy.map[i + 1][j].y;
			pv(id, xy, id->data.color);
		}
	}
}

int		print(t_map map, t_id *id, int proj)
{
	int		i;
	t_map	cpy;
	t_coo	xy;

	proj = 1;
	cpy = cpy_map(map);
	add_proj(id->data, &cpy, proj);
	if (!(id->img_p = mlx_new_image(id->mlx_p, 1000, 1000)))
		return (0);
	id->tab = (int *)mlx_get_data_addr(id->img_p, &id->bpp, &id->sizeline,
			&id->endian);
	bzero_tab(id->tab);
	i = -1;
	while (++i < cpy.max_y)
		call_print(cpy, id, xy, i);
	mlx_put_image_to_window(id->mlx_p, id->win_p, id->img_p, 0, 0);
	i = -1;
	while (++i < cpy.max_y)
		free(cpy.map[i]);
	free(cpy.max);
	free(cpy.map);
	return (1);
}
