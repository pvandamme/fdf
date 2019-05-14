/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:34:07 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/16 02:08:30 by rmerien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_data
{
	float			zoom;
	float			high;
	float			start_x;
	float			start_y;
	int				color;
	int				projection;
}					t_data;

typedef struct		s_map
{
	int				nb;
	int				*max;
	int				max_y;
	t_point			**map;
}					t_map;

typedef struct		s_id
{
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	void			*dsp_p;
	int				bpp;
	int				sizeline;
	int				endian;
	int				fd;
	char			**av;
	int				*dsp;
	int				*tab;
	t_map			*map;
	t_data			data;
}					t_id;

typedef struct		s_coo
{
	int				incr;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				diff_x;
	int				diff_y;
	int				der_y;
	int				der_x;
	int				x_incr;
	int				y_incr;
	int				error_x;
	int				error_y;
	int				flags;
}					t_coo;

int					main(int ac, char **av);
void				bzero_tab(int *tab);
int					print(t_map map, t_id *id, int proj);
int					free_all(char **tab, char *str, int fd);
void				free_tab(void **tab);
t_map				*init_map(t_data data, int fd, int tmp, char **av);
int					put_dsp(t_id *id);
void				proj(int key, t_data *data);
void				pv(t_id *id, t_coo xy, int color);
void				zoom(int key, t_data *data);
void				reset(int key, t_data *data);
void				high(int key, t_data *data);
void				move(int key, t_data *data);
void				color(int key, t_data *data);
int					get_projection(t_data data, t_map *m, int i, int j);

#endif
