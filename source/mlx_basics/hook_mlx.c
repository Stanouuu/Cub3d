/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:58 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/04 18:20:53 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		// data->mlx_ptr = NULL;
		data->win_ptr = NULL;
	}
	// rotate_input(keysym, data);
	// simple_input(keysym, data);
	// data->refresh = 1;
	return (0);
}