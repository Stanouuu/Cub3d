/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:53 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/09 15:35:34 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int j = 0;
	int i = 0;

	// if (!(argc == 2) || argv_check(argv[1]) != 0)
	// {
	// 	write(0, "Error\n", 6);
	// 	return (1);
	// }
	data.map = NULL;
	if ((argc && !argv) || init_mlx(&data) > 0 || !parse_central(argv, argc, &data))
		return (2);
	if (data.map)
	{
		// printf("north : %s\n", data.map->north);
		// printf("east  : %s\n", data.map->east);
		// printf("west  : %s\n", data.map->west);
		// printf("south : %s\n", data.map->south);
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
	printf("sucess 5\n");
	// initialize(&data);
	// data.map = open("map", O_RDONLY);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, &render_ctrl, &data);
	// mlx_hook(data.win_ptr, ClientMessage, KeyPressMask, &handle_cross, &data);
	// write(1, "h", 1);
	mlx_loop(data.mlx_ptr);
	ft_exit(&data);
	// close(data.map);
	// mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
}
