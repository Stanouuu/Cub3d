/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:29 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/21 15:51:09 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_img(t_data *data)
{
	t_imge	i;

	i.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, LENGTH);
	if (!i.mlx_img)
		return (-1);
	i.addr = mlx_get_data_addr(i.mlx_img, &i.bpp, &i.line_len, &i.endian);
	if (!i.addr)
		return (-2);
	data->img = i;
	return (1);
}

int	init_mlx(t_data *data)
{
	data->map = NULL;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, LENGTH, "CUBE ");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (2);
	}
	if (init_img(data) < 0)
		return (3);
	data->player.y = -1;
	data->player.x = -1;
	data->player.a = 3.14 / 2;
	return (0);
}
