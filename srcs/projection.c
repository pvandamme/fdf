/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:08:05 by rmerien           #+#    #+#             */
/*   Updated: 2018/12/16 03:51:50 by rmerien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void		iso(t_data data, int *x, int *y, int z)
{
	int		save_x;
	int		save_y;

	save_x = *x;
	save_y = *y;
	*x = (save_x - save_y) * cos(0.523599) * data.zoom + data.start_x;
	*y = (save_x + save_y) * sin(0.523599) * data.zoom + data.start_y - z;
}

static void		para(t_data data, int *x, int *y, int z)
{
	*x = (*x - z * cos(0.7854)) * data.zoom + data.start_x;
	*y = (*y - z * sin(0.7854)) * data.zoom + data.start_y;
}

int				get_projection(t_data data, t_map *m, int i, int j)
{
	int		z;

	z = m->map[i][j].z * data.zoom * data.high;
	if (data.projection == 1)
		iso(data, &m->map[i][j].x, &m->map[i][j].y, z);
	if (data.projection == 0)
		para(data, &m->map[i][j].x, &m->map[i][j].y, z);
	else
		return (0);
	return (1);
}
