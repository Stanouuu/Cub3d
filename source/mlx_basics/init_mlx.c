/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:29 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/12 13:33:18 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_img(t_data *data)
{
	t_imge	i;

	i.mlx_img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	i.addr = mlx_get_data_addr(i.mlx_img, &i.bpp, &i.line_len, &i.endian);
	data->img = i;
}

// void init_player(t_data *data)
// {
// 	t_player p;

// 	p.fov = 3.14 / 3;
// 	p.ray_angle = (p.a - p.fov / 2.0f) + (p.x / 1000) * p.fov;
// 	p.distance_to_wall = 0;
// 	data->img = i;
// }

int init_mlx(t_data *data)
{
	data->map = NULL;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, LENGTH, "FDF");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (2);
	}
	init_img(data);
	data->maptmp = ft_split("1111111111111111 1000000000000001 1000000000000001 1000000001111111 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1111111111111111 ", ' ');
	data->player.a = 0.0;
	data->player.y = 8.0;
	data->player.x = 8.0;
	return (0);
}

// void initialize(t_data *data)
// {

// }
