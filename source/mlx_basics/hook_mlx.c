/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:58 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/13 16:01:46 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	handle_input(int keysym, t_data *data)
{
	float olddir = 0;
	float oldplanex;
	printf("%f   x :%f y :%f\n",data->player.a, data->player.x, data->player.y);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == XK_q)
	{
		data->player.a += 0.08f;
		olddir = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(0.08) - data->player.dirY * sin((0.08));
		data->player.dirY = olddir * sin(0.08) + data->player.dirY * cos(0.08);
		oldplanex = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(0.08) - data->player.planeY * sin(0.08);
		data->player.planeY = oldplanex * sin(0.08) + data->player.planeY * cos (0.08);
	}
	if (keysym == XK_e)
	{
		data->player.a -= 0.08f;
		olddir = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(-0.08) - data->player.dirY * sin((-0.08));
		data->player.dirY = olddir * sin(-0.08) + data->player.dirY * cos(-0.08);
		oldplanex = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-0.08) - data->player.planeY * sin(-0.08);
		data->player.planeY = oldplanex * sin(-0.08) + data->player.planeY * cos (-0.08);
	}
	if (keysym == XK_w)
	{
		write(1, "w", 1);
		if (data->map->map[(int)(data->player.x + data->player.dirX * 0.5)][(int)data->player.y] == 0)
			data->player.x = data->player.x + data->player.dirX * 0.1;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y + data->player.dirY * 0.5)] == 0)
			data->player.y = data->player.y + data->player.dirY * 0.1;
		// printf("%d\n",(data->map->map[(int)(data->player.x + data->player.dirX)][(int)data->player.y] ));
	}
	if (keysym == XK_s)
	{
		write(1, "s", 1);
		if (data->map->map[(int)(data->player.x - data->player.dirX)][(int)data->player.y] == 0)
			data->player.x = data->player.x - data->player.dirX * 0.1;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y - data->player.dirY)] == 0)
			data->player.y = data->player.y - data->player.dirY * 0.1;
	}
	if (keysym == XK_d)
	{
		// if (data->map->map[(int)(data->player.x)][(int)(data->player.y + cosf(data->player.a) * 0.1f)] == 0)
		if (data->map->map[(int)(data->player.x - sinf(data->player.a) * 0.1f)][(int)data->player.y] == 0 && data->map->map[(int)(data->player.x)][(int)(data->player.y - cosf(data->player.a) * 0.1f)] == 0)
		{
			data->player.x -= sinf(data->player.a) * 0.1f;
			data->player.y -= cosf(data->player.a) * 0.1f;
		}
		write(1, "d", 1);
		// data->player.y += cosf(data->player.a) * 0.1f;
		// data->player.x += sinf(data->player.a) * 0.1f;
		// if (data->map->map[(int)(data->player.y)][(int)(data->player.x)] == 1)
		// {
		// 	write(1, "hell", 4);
		// 	data->player.y -= cosf(data->player.a) * 0.1f;
		// 	data->player.x -= sinf(data->player.a) * 0.1f;
		// }
	}
	if (keysym == XK_a)
	{
		if (data->map->map[(int)(data->player.x + sinf(data->player.a) * 0.1f)][(int)data->player.y] == 0 && data->map->map[(int)(data->player.x)][(int)(data->player.y + cosf(data->player.a) * 0.1f)] == 0)
		{
			data->player.x += sinf(data->player.a) * 0.1f;
			data->player.y += cosf(data->player.a) * 0.1f;
		}

		// printf()
		// if (data->map->map[(int)(data->player.x)][(int)(data->player.y - cosf(data->player.a) * 0.1f)] == 0)


		write(1, "a", 1);
		// data->player.y -= cosf(data->player.a) * 0.05f;
		// data->player.x -= sinf(data->player.a) * 0.05f;
		// if (data->map->map[(int)(data->player.y)][(int)(data->player.x)] == 1)
		// {
		// 	write(1, "hell", 4);
		// 	data->player.y += cosf(data->player.a) * 0.05f;
		// 	data->player.x += sinf(data->player.a) * 0.05f;
		// }
	}
	return (0);
}
