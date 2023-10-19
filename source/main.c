/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:53 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/19 14:12:31 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	handle_cross(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

void	player_info_2(char direction, t_player *player)
{
	if (direction == 'S')
	{
		update_dir(player, 1, 0);
		update_plane(player, 0, -0.66);
	}
	else if (direction == 'N')
	{
		update_dir(player, -1, 0);
		update_plane(player, 0, 0.66);
	}
	else if (direction == 'E' || direction == 'W')
	{
		update_plane(player, 0.66, 0);
		if (direction == 'E')
			update_dir(player, 0, 1);
		if (direction == 'W')
			update_dir(player, 0, -1);
	}
	else
		player->y = -2;
}

void	update_dir(t_player *data, float x, float y)
{
	data->dirx = x;
	data->diry = y;
}

void	update_plane(t_player *data, float x, float y)
{
	data->planex = x;
	data->planey = y;
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.map = NULL;
	data.tex = NULL;
	if ((argc && !argv) || init_mlx(&data) > 0
		|| !parse_central(argv, argc, &data))
		return (2);
	if (init_tex(&data) < 0)
	{
		ft_exit(&data);
		return (3);
	}
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_hook(data.win_ptr, ClientMessage, KeyPressMask, &handle_cross, &data);
	mlx_loop_hook(data.mlx_ptr, &render_ctrl, &data);
	mlx_loop(data.mlx_ptr);
	ft_exit(&data);
}
