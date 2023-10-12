/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:58 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/12 16:33:31 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	handle_input(int keysym, t_data *data)
{
	float olddir = 0;
	float oldplanex;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == 65363)
		data->player.a -= 0.1f;
	if (keysym == 65361)
	{
		data->player.a += 0.1f;
	}
	if (keysym == XK_w)
	{
		if (data->map->map[(int)(data->player.x + data->player.dirX)][(int)data->player.y] == 0)
			data->player.x = data->player.x + data->player.dirX * 0.01;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y + data->player.dirY)] == 0)
			data->player.y = data->player.y + data->player.dirY * 0.01;
		printf("%d\n",(data->map->map[(int)(data->player.x + data->player.dirX)][(int)data->player.y] ));
	}
	if (keysym == XK_s)
	{
		write(1, "f", 1);
		if (data->map->map[(int)(data->player.x - data->player.dirX)][(int)data->player.y] == 0)
			data->player.x = data->player.x - data->player.dirX * 0.1;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y - data->player.dirY)] == 0)
			data->player.y = data->player.y - data->player.dirY * 0.1;
	}
	if (keysym == XK_d)
	{
		write(1, "f", 1);
		olddir = data->player.dirX;
		printf("data->plaer dirx %f\n", data->player.dirX);
		data->player.dirX = data->player.dirX * cos(-0.5) - data->player.dirY * sin((-0.5));
		data->player.dirY = olddir * sin(-0.5) + data->player.dirY * cos(-0.5);
		oldplanex = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-0.5) - data->player.planeY * sin(-0.5);
		data->player.planeY = oldplanex * sin(-0.5) + data->player.planeY * cos (-0.5);
	}
	if (keysym == XK_z)
	{
		data->player.y += cosf(data->player.a) * 0.1f;
		data->player.x += sinf(data->player.a) * 0.1f;
		if (data->maptmp[(int)data->player.y][(int)data->player.x] == '1')
		{
			data->player.y -= cosf(data->player.a) * 0.1f;
			data->player.x -= sinf(data->player.a) * 0.1f;
		}
	}
	return (0);
}
