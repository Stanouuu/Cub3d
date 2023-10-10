/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:53 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/10 15:23:39 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mycube.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	printf("123\n");
	init_player(&data->player);
	init_texinfo(&data->texinfo);
	data->map = NULL;
	data->texture_pixels = NULL;
	data->textures = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->trigger = 0;
	data->timer = 0;
	data->trig = 0;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	data;
	init_data(&data);
	init_mlx(&data);
	printf("123\n");
	init_textures(&data);
	printf("123\n");
	render_images(&data);
	printf("123\n");
	listen_for_input(&data);
	printf("123\n");
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
