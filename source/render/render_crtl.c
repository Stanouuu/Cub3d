/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_crtl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:27:48 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 15:51:55 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	*load_good_tex(t_data *data)
{
	if (data->ray.side == 1 && data->ray.rayDirY < 0)
		return ((int *)data->tex->wall_we.addr);
	else if (data->ray.side == 1 && data->ray.rayDirY > 0)
		return ((int *)data->tex->wall_ea.addr);
	else if (data->ray.side == 0 && data->ray.rayDirX < 0)
		return ((int *)data->tex->wall_no.addr);
	else
		return ((int *)data->tex->wall_so.addr);
}

void	init_ray(t_data *data, int x)
{
	data->ray.camerax = (x / (float)WIDTH) * 2 - 1.f;
	data->ray.rayDirX = data->player.dirX + data->player.planeX \
	* data->ray.camerax;
	data->ray.rayDirY = data->player.dirY + data->player.planeY \
	* data->ray.camerax;
	data->ray.mapx = (int)data->player.x;
	data->ray.mapy = (int)data->player.y;
	data->ray.deltadistX = fabsf(1.f / data->ray.rayDirX);
	data->ray.deltadistY = fabsf(1.f / data->ray.rayDirY);
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
		printf("%f dirx  %f diry\n", data->player.dirX, data->player.dirY);
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

int	check_open_tex(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}
