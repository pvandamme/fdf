/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 07:58:14 by pvandamm          #+#    #+#             */
/*   Updated: 2018/11/21 07:58:27 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	tmp;

	tmp = 0;
	while (tmp++ <= nb)
		if (tmp * tmp == nb)
			return (tmp);
	return (0);
}
