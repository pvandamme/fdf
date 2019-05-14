/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 05:47:05 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/13 06:28:02 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	zoom(int key, t_data *data)
{
	if (key == 78 || key == 27)
		data->zoom /= 1.05;
	else
		data->zoom *= 1.05;
}

void	move(int key, t_data *data)
{
	if (key == 123)
		data->start_x -= 5;
	if (key == 124)
		data->start_x += 5;
	if (key == 125)
		data->start_y += 5;
	if (key == 126)
		data->start_y -= 5;
}

void	high(int key, t_data *data)
{
	if (key == 33)
		data->high /= 1.05;
	else
		data->high *= 1.05;
}

void	proj(int key, t_data *data)
{
	if (data->projection == 1)
		data->projection = 0;
	else
		data->projection = 1;
}

void	reset(int key, t_data *data)
{
	data->zoom = 30;
	data->high = 0.03;
	data->start_x = 300;
	data->start_y = 300;
}
