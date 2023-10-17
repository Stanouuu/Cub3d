/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:58 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/17 11:02:29 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	strafe(int keysym, t_data *data)
{
	if (keysym == XK_d)
	{
		data->player.y += cosf(data->player.a) * 0.1f;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y)] == 1)
			data->player.y -= cosf(data->player.a) * 0.1f;
		data->player.x -= sinf(data->player.a) * 0.1f;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y)] == 1)
			data->player.x += sinf(data->player.a) * 0.1f;
	}
	if (keysym == XK_a)
	{
		data->player.y -= cosf(data->player.a) * 0.1f;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y)] == 1)
			data->player.y += cosf(data->player.a) * 0.1f;
		data->player.x += sinf(data->player.a) * 0.1f;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y)] == 1)
			data->player.x -= sinf(data->player.a) * 0.1f;
	}
}

void	rotate_left(int keysym, t_data *data)
{
	float	olddir;
	float	oldplanex;

	olddir = 0;
	if (keysym == XK_q)
	{
		data->player.a += 0.08f;
		olddir = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(0.08)
			- data->player.dirY * sin((0.08));
		data->player.dirY = olddir * sin(0.08) + data->player.dirY * cos(0.08);
		oldplanex = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(0.08)
			- data->player.planeY * sin(0.08);
		data->player.planeY = oldplanex * sin(0.08)
			+ data->player.planeY * cos (0.08);
	}
}

void	rotate_right(int keysym, t_data *data)
{
	float	olddir;
	float	oldplanex;

	olddir = 0;
	if (keysym == XK_e)
	{
		data->player.a -= 0.08f;
		olddir = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(-0.08)
			- data->player.dirY * sin((-0.08));
		data->player.dirY = olddir * sin(-0.08)
			+ data->player.dirY * cos(-0.08);
		oldplanex = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-0.08)
			- data->player.planeY * sin(-0.08);
		data->player.planeY = oldplanex * sin(-0.08)
			+ data->player.planeY * cos (-0.08);
	}
}

void	basic_mvmt(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		if (data->map->map[(int)(data->player.x
				+ data->player.dirX * 0.5)][(int)data->player.y] == 0)
			data->player.x = data->player.x + data->player.dirX * 0.1;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y
				+ data->player.dirY * 0.5)] == 0)
			data->player.y = data->player.y + data->player.dirY * 0.1;
	}
	if (keysym == XK_s)
	{
		if (data->map->map[(int)(data->player.x
				- data->player.dirX)][(int)data->player.y] == 0)
			data->player.x = data->player.x - data->player.dirX * 0.1;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y
				- data->player.dirY)] == 0)
			data->player.y = data->player.y - data->player.dirY * 0.1;
	}
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	basic_mvmt(keysym, data);
	strafe(keysym, data);
	rotate_right(keysym, data);
	rotate_left(keysym, data);
	return (0);
}
