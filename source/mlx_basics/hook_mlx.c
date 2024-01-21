/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:58 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/21 16:42:03 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	strafe(int keysym, t_data *data)
{
	if (keysym == XK_a)
	{
		data->player.y += cosf(data->player.a) * 0.1f;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y)] == 1)
			data->player.y -= cosf(data->player.a) * 0.1f;
		data->player.x -= sinf(data->player.a) * 0.1f;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y)] == 1)
			data->player.x += sinf(data->player.a) * 0.1f;
	}
	if (keysym == XK_d)
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
	if (keysym == 65361)
	{
		data->player.a += 0.08f;
		olddir = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(0.08)
			- data->player.diry * sin((0.08));
		data->player.diry = olddir * sin(0.08) + data->player.diry * cos(0.08);
		oldplanex = data->player.planex;
		data->player.planex = data->player.planex * cos(0.08)
			- data->player.planey * sin(0.08);
		data->player.planey = oldplanex * sin(0.08)
			+ data->player.planey * cos (0.08);
	}
}

void	rotate_right(int keysym, t_data *data)
{
	float	olddir;
	float	oldplanex;

	olddir = 0;
	if (keysym == 65363)
	{
		data->player.a -= 0.08f;
		olddir = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(-0.08)
			- data->player.diry * sin((-0.08));
		data->player.diry = olddir * sin(-0.08)
			+ data->player.diry * cos(-0.08);
		oldplanex = data->player.planex;
		data->player.planex = data->player.planex * cos(-0.08)
			- data->player.planey * sin(-0.08);
		data->player.planey = oldplanex * sin(-0.08)
			+ data->player.planey * cos (-0.08);
	}
}

void	basic_mvmt(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		if (data->map->map[(int)(data->player.x
				+ data->player.dirx * 0.1)][(int)data->player.y] == 0)
			data->player.x = data->player.x + data->player.dirx * 0.1f;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y
				+ data->player.diry * 0.1)] == 0)
			data->player.y = data->player.y + data->player.diry * 0.1f;
	}
	if (keysym == XK_s)
	{
		if (data->map->map[(int)(data->player.x
				- data->player.dirx * 0.1)][(int)data->player.y] == 0)
			data->player.x = data->player.x - data->player.dirx * 0.1f;
		if (data->map->map[(int)(data->player.x)][(int)(data->player.y
				- data->player.diry * 0.1)] == 0)
			data->player.y = data->player.y - data->player.diry * 0.1f;
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
