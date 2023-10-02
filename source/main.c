/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:53 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/02 16:31:58 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	data;

	// if (!(argc == 2) || argv_check(argv[1]) != 0)
	// {
	// 	write(0, "Error\n", 6);
	// 	return (1);
	// }
	printf("sucess 5\n");
	if ((argc && !argv) || init_mlx(&data) > 0 || !parse_central(argv, argc, &data))
		return (ft_exit(&data), 2);
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
