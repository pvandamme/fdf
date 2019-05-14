/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_droite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 03:38:50 by rmerien           #+#    #+#             */
/*   Updated: 2018/12/16 02:11:54 by rmerien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"

static void		print_0(t_id *id, t_coo xy, int color)
{
	while (xy.incr++ < xy.der_x)
	{
		if (!(xy.x1 < 0 || xy.y1 < 0 || xy.y1 > 999
					|| xy.x1 > 999))
			id->tab[(xy.y1) * 1000 + (xy.x1)] = color;
		xy.x1 += xy.x_incr;
		xy.error_x -= xy.dy;
		if (xy.error_x < 0)
		{
			xy.y1 += xy.y_incr;
			xy.error_x += xy.dx;
		}
	}
}

static void		print_1(t_id *id, t_coo xy, int color)
{
	while (xy.incr++ < xy.der_y)
	{
		if (!(xy.x1 < 0 || xy.y1 < 0 || xy.y1 > 999 || xy.x1 > 999))
			id->tab[(xy.y1) * 1000 + (xy.x1)] = color;
		xy.y1 += xy.y_incr;
		xy.error_y -= xy.dx;
		if (xy.error_y < 0)
		{
			xy.x1 += xy.x_incr;
			xy.error_y += xy.dy;
		}
	}
}

void			pv(t_id *id, t_coo xy, int color)
{
	xy.dy = 2 * ft_abs(xy.y2 - xy.y1);
	xy.dx = 2 * ft_abs(xy.x2 - xy.x1);
	xy.x_incr = (xy.x1 > xy.x2) ? -1 : 1;
	xy.y_incr = (xy.y1 > xy.y2) ? -1 : 1;
	xy.error_x = ft_abs(xy.x2 - xy.x1);
	xy.error_y = ft_abs(xy.y2 - xy.y1);
	xy.der_x = xy.error_x;
	xy.der_y = xy.error_y;
	xy.incr = 0;
	if (xy.der_x > xy.der_y)
		print_0(id, xy, color);
	else
		print_1(id, xy, color);
}
