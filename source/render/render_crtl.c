/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_crtl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:27:48 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/04 15:58:14 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int render_ctrl(t_data *data)
{
	t_imge *img = &(data->img);
	// int		i;

	// i = 1;
	if (data->win_ptr == NULL)
		return (1);
	// while (i < 400)
		// img_pix_put(img, i++, 300, 0xffffff);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
	return (1);
}
