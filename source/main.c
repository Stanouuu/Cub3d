/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:53 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 15:52:19 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	data->dirX = x;
	data->dirY = y;
}

void	update_plane(t_player *data, float x, float y)
{
	data->planeX = x;
	data->planeY = y;
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.map = NULL;
	data.tex = NULL;
	if ((argc && !argv) || init_mlx(&data) > 0 || !parse_central(argv, argc, &data))
		return (2);
	if (init_tex(&data) < 0)
	{
		ft_exit(&data);
		return (3);
	}
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, &render_ctrl, &data);
	mlx_loop(data.mlx_ptr);
	ft_exit(&data);
}
