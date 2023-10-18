/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_crtl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:27:48 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 16:14:38 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	*load_good_tex(t_data *data)
{
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		return ((int *)data->tex->wall_we.addr);
	else if (data->ray.side == 1 && data->ray.raydiry > 0)
		return ((int *)data->tex->wall_ea.addr);
	else if (data->ray.side == 0 && data->ray.raydirx < 0)
		return ((int *)data->tex->wall_no.addr);
	else
		return ((int *)data->tex->wall_so.addr);
}

void	init_ray(t_data *data, int x)
{
	data->ray.camerax = (x / (float)WIDTH) * 2 - 1.f;
	data->ray.raydirx = data->player.dirx + data->player.planex \
	* data->ray.camerax;
	data->ray.raydiry = data->player.diry + data->player.planey \
	* data->ray.camerax;
	data->ray.mapx = (int)data->player.x;
	data->ray.mapy = (int)data->player.y;
	data->ray.deltadistx = fabsf(1.f / data->ray.raydirx);
	data->ray.deltadisty = fabsf(1.f / data->ray.raydiry);
	data->ray.hit = 0;
}

void	raycaster(t_data *data)
{
	int	x;
	int	d;

	x = 0;
	d = 0;
	while (x < WIDTH)
	{
		init_ray(data, x);
		init_sidedist(data);
		position_map(data);
		init_ray_calc(data);
		while (d < LENGTH)
		{
			draw_pixel(data, d, x);
			d++;
		}
		d = 0;
		x++;
	}
}

int	render_ctrl(t_data *data)
{
	t_imge	*img;

	img = &(data->img);
	if (data->win_ptr == NULL)
		return (1);
	raycaster(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
	return (1);
}
