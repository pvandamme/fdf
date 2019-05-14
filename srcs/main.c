/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 03:11:49 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/16 04:53:46 by rmerien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "mlx.h"
#include "../includes/fdf.h"

static int	dispatch_input(int key, void *id)
{
	if (key == 53)
	{
		mlx_destroy_window(((t_id *)id)->mlx_p, (((t_id *)id)->win_p));
		free(((t_id *)id)->map);
		free(((t_id *)id)->tab);
		free(id);
		exit(0);
	}
	if (key == 78 || key == 27 || key == 69 || key == 24)
		zoom(key, &((t_id *)id)->data);
	if (key > 122 && key < 127)
		move(key, &((t_id *)id)->data);
	if (key == 33 || key == 30)
		high(key, &((t_id *)id)->data);
	color(key, &((t_id *)id)->data);
	if (key == 35)
		proj(key, &((t_id *)id)->data);
	if (key == 15)
		reset(key, &((t_id *)id)->data);
	print(*((t_id *)id)->map, (t_id *)id, ((t_id *)id)->data.projection);
	return (0);
}

static t_id	*init_id(void)
{
	t_id	*id;

	if (!(id = malloc(sizeof(t_id))))
		return (0);
	id->data.zoom = 30;
	id->data.high = 0.03;
	id->data.color = 255;
	id->data.projection = 1;
	id->data.start_x = 300;
	id->data.start_y = 300;
	return (id);
}

static int	ft_puterror(char *str, int fd)
{
	if (fd)
		close(fd);
	ft_putstr_fd(str, 2);
	return (-1);
}

int			main(int ac, char **av)
{
	int			fd;
	int			tmp;
	t_id		*id;

	if (ac == 2)
	{
		if (!(id = init_id()))
			return (-1);
		if ((fd = open(av[1], O_RDONLY)) < 1)
			return (ft_puterror("Map error\n", 0));
		if ((tmp = open(av[1], O_RDONLY)) < 1)
			return (ft_puterror("Map error\n", 0));
		if (!(id->map = init_map(id->data, fd, tmp, av)))
			return (ft_puterror("Map error\n", fd));
		id->mlx_p = mlx_init();
		id->win_p = mlx_new_window(id->mlx_p, 1300, 1000, av[1]);
		put_dsp(id);
		print(*id->map, id, id->data.projection);
		mlx_hook(id->win_p, 2, 0, dispatch_input, id);
		mlx_loop(id->mlx_p);
	}
	else
		ft_putstr_fd("Map error\n", 2);
	return (0);
}
