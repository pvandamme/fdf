/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 22:35:24 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/16 04:04:15 by rmerien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "mlx.h"

void	free_split(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		free_all(char **tab, char *str, int fd)
{
	if (tab)
		free_split((void **)tab);
	if (str)
		free(str);
	if (fd)
		close(fd);
	return (0);
}

void	bzero_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 1000000)
	{
		tab[i] = 1251109;
		i++;
	}
}

int		print_strings(t_id *id)
{
	mlx_string_put(id->mlx_p, id->win_p, 1010, 60, 16777215, "Keys :");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 100, 16777215,
			"-Move with arrow");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 130, 16777215,
			"-Change zoom with + and -");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 160, 16777215,
			"-Change high with [ and ]");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 190, 16777215,
			"-Change color with : ");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 220, 16777215,
			" 1, 2 and 3");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 250, 16777215,
			"-Change luminosity with : ");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 280, 16777215,
			" 4 and 5");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 310, 16777215,
			"-Change projection with P");
	mlx_string_put(id->mlx_p, id->win_p, 1010, 340, 16777215,
			"-Reset map with R");
	return (1);
}

int		put_dsp(t_id *id)
{
	int	i;

	i = 0;
	if (!(id->dsp_p = mlx_new_image(id->mlx_p, 300, 1000)))
		return (0);
	id->dsp = (int *)mlx_get_data_addr(id->dsp_p, &id->bpp, &id->sizeline,
			&id->endian);
	while (i < 300000)
	{
		id->dsp[i] = 3553598;
		i++;
	}
	mlx_put_image_to_window(id->mlx_p, id->win_p, id->dsp_p, 1000, 0);
	print_strings(id);
	return (1);
}
