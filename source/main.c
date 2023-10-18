/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:53 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 14:59:31 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int j = 0;
	int i = 0;

	data.map = NULL;
	data.tex = NULL;
	if ((argc && !argv) || init_mlx(&data) > 0 || !parse_central(argv, argc, &data))
		return (2);
	if (data.map)
	{
		printf("north : %s\n", data.map->north);
		printf("east  : %s\n", data.map->east);
		printf("west  : %s\n", data.map->west);
		printf("south : %s\n", data.map->south);
		printf("fcolor: %d\n", data.map->floor_color);
		printf("ccolor: %d\n", data.map->ceiling_color);
		while (data.map->map_lenght != i)
		{
			j = 0;
			while (data.map->map_width != j)
			{
				printf("%d", data.map->map[i][j]);
				j++;
			}	
			printf("\n");
			i++;
		}
	}
	if (init_tex(&data) < 0)
	{
		ft_exit(&data);
		return (3);
	}
	data.player.planeX = 0.0;
	data.player.planeY = 0.66;
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, &render_ctrl, &data);
	mlx_loop(data.mlx_ptr);
	ft_exit(&data);
}
