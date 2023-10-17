/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_crtl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:27:48 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/17 17:32:07 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


int load_north(t_data *data)
{
	data->tex->wall_no.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->north, &data->tex->wall_no.tex_width, &data->tex->wall_no.tex_height);
	if (!data->tex->wall_no.mlx_img)
		return (-2);
	data->tex->wall_no.addr = mlx_get_data_addr(data->tex->wall_no.mlx_img, &data->tex->wall_no.bpp , &data->tex->wall_no.line_len, &data->tex->wall_no.endian);
	return (0);
}

int load_south(t_data *data)
{
	data->tex->wall_so.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->south, &data->tex->wall_so.tex_width, &data->tex->wall_so.tex_height);
	if (!data->tex->wall_so.mlx_img)
		return (-2);
	data->tex->wall_so.addr = mlx_get_data_addr(data->tex->wall_so.mlx_img, &data->tex->wall_so.bpp , &data->tex->wall_so.line_len, &data->tex->wall_so.endian);
	return (0);
}

int load_west(t_data *data)
{
	data->tex->wall_we.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->west, &data->tex->wall_we.tex_width, &data->tex->wall_we.tex_height);
	if (!data->tex->wall_we.mlx_img)
		return (-2);
	data->tex->wall_we.addr = mlx_get_data_addr(data->tex->wall_we.mlx_img, &data->tex->wall_we.bpp , &data->tex->wall_we.line_len, &data->tex->wall_we.endian);
	return (0);
}

int load_east(t_data *data)
{
	data->tex->wall_ea.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->east, &data->tex->wall_ea.tex_width, &data->tex->wall_ea.tex_height);
	if (!data->tex->wall_ea.mlx_img)
		return (-2);
	data->tex->wall_ea.addr = mlx_get_data_addr(data->tex->wall_ea.mlx_img, &data->tex->wall_ea.bpp , &data->tex->wall_ea.line_len, &data->tex->wall_ea.endian);
	return (0);
}

int init_tex(t_data *data)
{
	data->tex = malloc(sizeof(t_tex));
	if (!data->tex)
		return (-1);
	if (load_north(data) < 0)
		return (-1);
	if (load_south(data) < 0)
		return (-2);
	if (load_west(data))
		return (-3);
	if (load_east(data))
		return (-4);
	return (0);
}

int *load_good_tex(t_data *data)
{
	if (data->ray.side == 1 && data->ray.rayDirY < 0)
		return (int *)data->tex->wall_we.addr;
	else if (data->ray.side == 1 && data->ray.rayDirY > 0)
		return (int *)data->tex->wall_ea.addr;
	else if (data->ray.side == 0 && data->ray.rayDirX < 0)
		return (int *)data->tex->wall_no.addr;
	else
		return (int *)data->tex->wall_so.addr;
}


void init_ray(t_data *data, int x)
{
		data->ray.camerax = (x / (float)WIDTH) * 2 - 1.f;
		data->ray.rayDirX = data->player.dirX + data->player.planeX * data->ray.camerax;
		data->ray.rayDirY = data->player.dirY + data->player.planeY * data->ray.camerax;
		data->ray.mapx = (int)data->player.x;
		data->ray.mapy = (int)data->player.y;
		data->ray.deltadistX = fabsf(1.f / data->ray.rayDirX);
		data->ray.deltadistY = fabsf(1.f / data->ray.rayDirY);
		data->ray.hit = 0;	
}

void init_sideDist(t_data *data)
{
	if (data->ray.rayDirX < 0)
	{
		data->ray.stepX = -1;
		data->ray.sideDistX = (data->player.x - data->ray.mapx) * data->ray.deltadistX;
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.sideDistX = (data->ray.mapx + 1.0 - data->player.x) * data->ray.deltadistX;
	}
	if (data->ray.rayDirY < 0)
	{
		data->ray.stepY = -1;
		data->ray.sideDistY = (data->player.y - data->ray.mapy) * data->ray.deltadistY;
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.sideDistY = (data->ray.mapy + 1.0 - data->player.y) * data->ray.deltadistY;
	}
}

void position_map(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sideDistX < data->ray.sideDistY)
		{
			data->ray.sideDistX  = data->ray.sideDistX + data->ray.deltadistX;
			data->ray.mapx = data->ray.mapx + data->ray.stepX;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sideDistY = data->ray.sideDistY + data->ray.deltadistY;
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

void init_ray_calc(t_data *data)
{
	data->player.lineheight = LENGTH / data->ray.perpWallDist;
	data->player.drawstart = -data->player.lineheight / 2 + LENGTH / 2;
	if (data->player.drawstart < 0)
		data->player.drawstart = 0;
	data->player.drawend = data->player.drawstart + data->player.lineheight;
	if (data->player.drawend >= LENGTH)
		data->player.drawend = LENGTH;
	if (data->ray.side == 1)
		data->player.wallx = data->player.x + data->ray.perpWallDist * data->ray.rayDirX;
	else
		data->player.wallx = data->player.y + data->ray.perpWallDist * data->ray.rayDirY;
	data->player.wallx = data->player.wallx - floorf(data->player.wallx);
	if ((data->ray.side == 0 && data->ray.rayDirX >= 0.f) || (data->ray.side == 1 && data->ray.rayDirY < 0.f))
		data->player.wallx = 1.0f - data->player.wallx;
	data->player.texx = (int)(data->player.wallx * (float) 64.0f);
}

void draw_pixel(t_data *data, int d, int x)
{
	int *stock_int = load_good_tex(data);
	int	i = 0;
	if (d < data->player.drawstart)
		img_pix_put(&data->img, x, d, data->map->floor_color);
	else if (d >= data->player.drawend)
		img_pix_put(&data->img, x, d, data->map->ceiling_color);
	else
	{
		float	coef = (float)(d - (LENGTH / 2 - data->player.lineheight / 2)) / (float)(data->player.lineheight);
		int texy = data->tex->wall_no.tex_height * coef;
		i = data->tex->wall_no.tex_width * texy + data->player.texx;
		img_pix_put(&data->img, x , d, stock_int[i]);
	}		
}
void raycaster(t_data *data)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(data, x);
		init_sideDist(data);
		position_map(data);
		init_ray_calc(data);
		int d = 0;
		while (d < LENGTH)
		{
			draw_pixel(data, d, x);
			d++;
		}
		x++;
	}
}

int render_ctrl(t_data *data)
{
	t_imge *img = &(data->img);

	if (data->win_ptr == NULL)
		return (1);
	raycaster(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
	return (1);
}