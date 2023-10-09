/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:53 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/14 15:56:43 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	data;

	int i;
	int y;
	
	i = 0;
	y = 0;

	if ((argc && !argv) || init_mlx(&data) > 0)
		return (2);

	data.mlx_ptr = mlx_init();

	data.player.posX = 22.0;
	data.maptmp = ft_split("1111111111111111 1000000000000001 1000000000000001 1000000001111111 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1000000000000001 1111111111111111 ", ' ');
	data.player.posY = 11.5;
	data.player.dirX = -1.0;
	data.player.dirY = 0.0;
	data.player.planeX = 0.0;
	data.player.planeY = 0.66;
	data.player.re_buf = 0;

	while (i < HEIGHT)
	{
		while (y < WIDTH)
		{
			data.bufbuf[i][y] = 0;
			y++;
		}
		i++;
	}

	if (!(data.player.texture = (int **)malloc(sizeof(int) * (texHeight * texWidth))))
		return (-1);
	i = 0;
	y = 0;
	while (i < 2)
	{
		while ( y < texHeight * texWidth)
		{
			data.player.texture[i][y] = 0;
			y++;
		} 
		i++;
	}
	load_texture(&data);

	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "FUCK U STAN I WAS EATING");

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.data = (int *)mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.size, &data.img.endian);

	mlx_loop_hook(data.mlx_ptr, &loop_loop, &data);
	mlx_hook(data.win_ptr, 2, 0, &handle_input, &data);

	mlx_loop(data.mlx_ptr);
}


