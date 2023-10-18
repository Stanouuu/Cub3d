/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:47:57 by nklingsh          #+#    #+#             */
/*   Updated: 2023/10/18 16:09:55 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_sidedist(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->player.x - data->ray.mapx) \
		* data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->player.x) \
		* data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->player.y - data->ray.mapy) \
		* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->player.y) \
		* data->ray.deltadisty;
	}
}

void	position_map(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx = data->ray.sidedistx \
			+ data->ray.deltadistx;
			data->ray.mapx = data->ray.mapx + data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty = data->ray.sidedisty \
			+ data->ray.deltadisty;
			data->ray.mapy = data->ray.mapy + data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map->map[data->ray.mapx][data->ray.mapy] == 1)
			data->ray.hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.sidedistx - data->ray.deltadistx);
	else
		data->ray.perpwalldist = (data->ray.sidedisty - data->ray.deltadisty);
}

void	init_ray_calc(t_data *data)
{
	data->player.lineheight = LENGTH / data->ray.perpwalldist;
	data->player.drawstart = -data->player.lineheight / 2 + LENGTH / 2;
	if (data->player.drawstart < 0)
		data->player.drawstart = 0;
	data->player.drawend = data->player.drawstart + data->player.lineheight;
	if (data->player.drawend >= LENGTH)
		data->player.drawend = LENGTH;
	if (data->ray.side == 1)
	{
		data->player.wallx = data->player.x \
		+ data->ray.perpwalldist * data->ray.raydirx;
	}
	else
	{
		data->player.wallx = data->player.y \
		+ data->ray.perpwalldist * data->ray.raydiry;
	}
	data->player.wallx = data->player.wallx - floorf(data->player.wallx);
	if ((data->ray.side == 0 && data->ray.raydirx >= 0.f) \
	|| (data->ray.side == 1 && data->ray.raydiry < 0.f))
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
