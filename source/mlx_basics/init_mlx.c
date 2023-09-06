/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:29 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/06 15:33:20 by sbarrage         ###   ########.fr       */
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

int init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (2);
	}
	init_img(data);
	return (0);
}

// void initialize(t_data *data)
// {
	
// }