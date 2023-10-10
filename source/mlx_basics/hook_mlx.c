/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:58 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/27 17:33:34 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == 65361)
		data->player.a -= 0.01f;
	if (keysym == 65363)
	{
		data->player.a += 0.01f;
	}
	if (keysym == XK_n)
		print_all_player_data(data->player);
	if (keysym == XK_a)
	{
		data->player.y += sinf(data->player.a) * 0.1f;
		data->player.x -= cosf(data->player.a) * 0.1f;
		write(1, "a" ,1);
		if (data->maptmp[(int)data->player.y][(int)data->player.x] == '1')
			data->player.a -= 0.1f;
	}
	if (keysym == XK_d)
	{
		data->player.y -= sinf(data->player.a) * 0.1f;
		data->player.x += cosf(data->player.a) * 0.1f;
		if (data->maptmp[(int)data->player.y][(int)data->player.x] == '1')
		{
			write(1, "f" ,1);
			data->player.y += sinf(data->player.a) * 0.1f;
			data->player.x -= cosf(data->player.a) * 0.1f;
		}
	}
	if (keysym == XK_s)
	{
		data->player.y -= cosf(data->player.a) * 0.1f;
		data->player.x -= sinf(data->player.a) * 0.1f;
		if (data->maptmp[(int)data->player.y][(int)data->player.x] == '1')
		{
			data->player.y += cosf(data->player.a) * 0.1f;
			data->player.x += sinf(data->player.a) * 0.1f;
		}
	}
	if (keysym == XK_w)
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
