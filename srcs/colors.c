/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 05:20:08 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/16 05:20:30 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(int key, t_data *data)
{
	if (key == 18)
		data->color = 65280;
	if (key == 19)
		data->color = 16711680;
	if (key == 20)
		data->color = 255;
	if (key == 23)
	{
		if (data->color % 65536 == 0)
			data->color += 131072;
		else if (data->color % 256 == 0)
			data->color += 512;
		else
			data->color += 2;
	}
	if (key == 21)
	{
		if (data->color % 65536 == 0)
			data->color -= 131072;
		else if (data->color % 256 == 0)
			data->color -= 512;
		else
			data->color -= 2;
	}
}
