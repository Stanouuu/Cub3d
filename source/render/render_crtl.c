/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_crtl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:27:48 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/09 11:02:52 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
//add floor ceiling

void load_tex(t_data *data)
{
	int y;

	y = 0;
	while (y < 64 * 64)
	{
		data->tex.wall_no.tex[y] = 0;
		data->tex.wall_so.tex[y] = 0;
		data->tex.wall_ea.tex[y] = 0;
		data->tex.wall_we.tex[y] = 0;
		y++;
	}
}

void init_tex(t_data *data)
{
	data->tex.wall_ea.tex = (int *)malloc(sizeof(int) * (64 * 64));
	data->tex.wall_so.tex = (int *)malloc(sizeof(int) * (64 * 64));
	data->tex.wall_we.tex = (int *)malloc(sizeof(int) * (64 * 64));
	data->tex.wall_no.tex = (int *)malloc(sizeof(int) * (64 * 64));
	load_tex(data);
}


void raycaster(t_data *data)
{
	data->player.dirX = -1.0;
	data->player.dirY = 0.0;

	data->player.planeX = 0.0;
	data->player.planeY = 0.66;
	init_tex(data);

	for (int x = 0; x < data->map->map_width; x++)
	{
		data->ray.camerax = (2 * x)/(float)data->map->map_width - 1;
		data->ray.rayDirX = data->player.dirX + data->player.planeX * data->ray.camerax;
		data->ray.rayDirY = data->player.dirY + data->player.planeY * data->ray.camerax;
		data->ray.mapx = (int)data->player.x;
		data->ray.mapy = (int)data->player.y;
		
		data->ray.deltadistX = sqrt(1 + (data->ray.rayDirY * data->ray.rayDirY) / (data->ray.rayDirX * data->ray.rayDirX));
		data->ray.deltadistY = sqrt(1 + (data->ray.rayDirX * data->ray.rayDirX) / (data->ray.rayDirY * data->ray.rayDirY));
		
		data->ray.hit = 0;
		
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
			printf(" mapx %d   map y %d  delta x %f    deltay %f     sideDistX %f    sideDistY %f   side %d hit %d\n",data->ray.mapx , data->ray.mapy ,data->ray.deltadistX, data->ray.deltadistY, data->ray.sideDistX , data->ray.sideDistY, data->ray.side , data->ray.hit);
			printf("map [x][y] %d\n", data->map->map[data->ray.mapx][data->ray.mapy]);
			if (data->map->map[data->ray.mapx][data->ray.mapy] > 0)
				data->ray.hit = 1;
		}
		if (data->ray.side == 0)
			data->ray.perpWallDist = (data->ray.sideDistX - data->ray.deltadistX);
		else
			data->ray.perpWallDist = (data->ray.sideDistY - data->ray.deltadistY);

		int lineHeight = (int) data->map->map_lenght / data->ray.perpWallDist;

		int drawstart = -lineHeight / 2 + data->map->map_lenght / 2;
		if (drawstart < 0)
			drawstart = 0;
		int drawend = lineHeight / 2 + data->map->map_lenght / 2;
		if (drawend >= data->map->map_lenght)
			drawend = data->map->map_lenght - 1;

		float wallX;

		if (data->ray.side == 0)
			wallX = data->player.y + data->ray.rayDirY;
		else
			wallX = data->player.x + data->ray.rayDirX;
		wallX = wallX - floor(wallX);
		printf("wall x : %f\n", wallX);
		int texX = (int)(wallX * (float) 64.0);
		if (data->ray.side == 0 && data->ray.rayDirX > 0)
			texX = 64.0 - texX - 1;
		if (data->ray.side == 1 && data->ray.rayDirY < 0)
			texX = 64.0 - texX - 1;

		float step = 1.0 * 64.0 / lineHeight;
		float texpos = (drawstart - data->map->map_lenght / 2 + lineHeight / 2) * step;
		for (int y = drawstart; y < drawend; y++)
		{
			int texY = (int)texpos & (64 - 1);
			texpos = texpos + step;
			color = 

		}

	}
	

}

int render_ctrl(t_data *data)
{
	// t_imge *img = &(data->img);

	if (data->win_ptr == NULL)
		return (1);
	raycaster(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
	return (1);
}