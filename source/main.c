/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:51:53 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/04 18:25:50 by sbarrage         ###   ########.fr       */
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
	if (argc && init_mlx(&data) > 0)
		return (2);
	// initialize(&data);
	data.map = open(argv[1], O_RDONLY);
	
	mlx_loop_hook(data.mlx_ptr, &render_ctrl, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
	// mlx_hook(data.win_ptr, ClientMessage, KeyPressMask, &handle_cross, &data);
	write(1, "h", 1);
	mlx_loop(data.mlx_ptr);
	exit_mlx(data);
	// mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
}