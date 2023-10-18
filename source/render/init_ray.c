/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:47:57 by nklingsh          #+#    #+#             */
/*   Updated: 2023/10/17 18:03:38 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_sidedist(t_data *data)
{
	if (data->ray.rayDirX < 0)
	{
		data->ray.stepX = -1;
		data->ray.sideDistX = (data->player.x - data->ray.mapx) \
		* data->ray.deltadistX;
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.sideDistX = (data->ray.mapx + 1.0 - data->player.x) \
		* data->ray.deltadistX;
	}
	if (data->ray.rayDirY < 0)
	{
		data->ray.stepY = -1;
		data->ray.sideDistY = (data->player.y - data->ray.mapy) \
		* data->ray.deltadistY;
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.sideDistY = (data->ray.mapy + 1.0 - data->player.y) \
		* data->ray.deltadistY;
	}
}

void	position_map(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sideDistX < data->ray.sideDistY)
		{
			data->ray.sideDistX = data->ray.sideDistX \
			+ data->ray.deltadistX;
			data->ray.mapx = data->ray.mapx + data->ray.stepX;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sideDistY = data->ray.sideDistY \
			+ data->ray.deltadistY;
			data->ray.mapy = data->ray.mapy + data->ray.stepY;
			data->ray.side = 1;
		}
		if (data->map->map[data->ray.mapx][data->ray.mapy] == 1)
			data->ray.hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perpWallDist = (data->ray.sideDistX - data->ray.deltadistX);
	else
		data->ray.perpWallDist = (data->ray.sideDistY - data->ray.deltadistY);
}

void	init_ray_calc(t_data *data)
{
	data->player.lineheight = LENGTH / data->ray.perpWallDist;
	data->player.drawstart = -data->player.lineheight / 2 + LENGTH / 2;
	if (data->player.drawstart < 0)
		data->player.drawstart = 0;
	data->player.drawend = data->player.drawstart + data->player.lineheight;
	if (data->player.drawend >= LENGTH)
		data->player.drawend = LENGTH;
	if (data->ray.side == 1)
	{
		data->player.wallx = data->player.x \
		+ data->ray.perpWallDist * data->ray.rayDirX;
	}
	else
	{
		data->player.wallx = data->player.y \
		+ data->ray.perpWallDist * data->ray.rayDirY;
	}
	data->player.wallx = data->player.wallx - floorf(data->player.wallx);
	if ((data->ray.side == 0 && data->ray.rayDirX >= 0.f) \
	|| (data->ray.side == 1 && data->ray.rayDirY < 0.f))
		data->player.wallx = 1.0f - data->player.wallx;
	data->player.texx = (int)(data->player.wallx * (float) 64.0f);
}

void	draw_pixel(t_data *data, int d, int x)
{
	int		i;
	float	coef;
	int		texy;

	if (d < data->player.drawstart)
		img_pix_put(&data->img, x, d, data->map->floor_color);
	else if (d >= data->player.drawend)
		img_pix_put(&data->img, x, d, data->map->ceiling_color);
	else
	{
		coef = (float)(d - (LENGTH / 2 - data->player.lineheight / 2)) \
		/ (float)(data->player.lineheight);
		texy = data->tex->wall_no.tex_height * coef;
		i = data->tex->wall_no.tex_width * texy + data->player.texx;
		img_pix_put(&data->img, x, d, load_good_tex(data)[i]);
	}		
}
