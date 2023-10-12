/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_crtl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:27:48 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/12 17:18:53 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
//add floor ceiling


void load_north(t_data *data)
{
	// printf("\n%s\n",data->map->north);
	data->tex->wall_no = malloc(sizeof(t_imge));
	data->tex->wall_no->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->north, &data->tex->wall_no->tex_width, &data->tex->wall_no->tex_height);
	data->tex->wall_no->addr = mlx_get_data_addr(data->tex->wall_no->mlx_img, &data->tex->wall_no->bpp , &data->tex->wall_no->line_len, &data->tex->wall_no->endian);
}

// void load_south(t_data *data)
// {
// 	data->tex->wall_so.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->south, &data->tex->wall_so.tex_width, &data->tex->wall_so.tex_height);
// 	data->tex->wall_so.addr = mlx_get_data_addr(data->tex->wall_so.mlx_img, &data->tex->wall_so.bpp , &data->tex->wall_so.line_len, &data->tex->wall_so.endian);
// }
// void load_west(t_data *data)
// {
// 	data->tex->wall_we.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->west, &data->tex->wall_we.tex_width, &data->tex->wall_we.tex_height);
// 	data->tex->wall_we.addr = mlx_get_data_addr(data->tex->wall_we.mlx_img, &data->tex->wall_we.bpp , &data->tex->wall_we.line_len, &data->tex->wall_we.endian);
// }
// void load_east(t_data *data)
// {
// 	data->tex->wall_ea.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->east, &data->tex->wall_ea.tex_width, &data->tex->wall_ea.tex_height);
// 	data->tex->wall_ea.addr = mlx_get_data_addr(data->tex->wall_ea.mlx_img, &data->tex->wall_ea.bpp , &data->tex->wall_ea.line_len, &data->tex->wall_ea.endian);
// }

void init_tex(t_data *data)
{
	data->tex = malloc(sizeof(t_tex));
	load_north(data);
	// load_south(data);
	// load_west(data);
	// load_east(data);
}


void raycaster(t_data *data)
{

	for (int x = 0; x < WIDTH; x++)
	{
		data->ray.camerax = (2 * x)/(float)WIDTH - 1;
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
			// printf(" mapx %d   map y %d  delta x %f    deltay %f     sideDistX %f    sideDistY %f   side %d hit %d\n",data->ray.mapx , data->ray.mapy ,data->ray.deltadistX, data->ray.deltadistY, data->ray.sideDistX , data->ray.sideDistY, data->ray.side , data->ray.hit);
			// printf("map [x][y] %d\n", data->map->map[data->ray.mapx][data->ray.mapy]);
			if (data->map->map[data->ray.mapx][data->ray.mapy] > 0)
				data->ray.hit = 1;
		}
		if (data->ray.side == 0)
			data->ray.perpWallDist = (data->ray.sideDistX - data->ray.deltadistX);	
		else
			data->ray.perpWallDist = (data->ray.sideDistY - data->ray.deltadistY);

		
		int lineHeight = (int) LENGTH / data->ray.perpWallDist;

		int drawstart = -lineHeight / 2 + LENGTH / 2;
		if (drawstart < 0)
			drawstart = 0;
		int drawend = lineHeight / 2 + LENGTH / 2;
		if (drawend >= LENGTH)
			drawend = LENGTH - 1;

		float wallX;
	
		if (data->ray.side == 0)
			wallX = data->player.y + data->ray.rayDirY;
		else
			wallX = data->player.x + data->ray.rayDirX;
		wallX = wallX - (int)wallX;
		// printf("wall x : %f\n", wallX);
		int texX = (int)(wallX * (float) 64.0);
		if (data->ray.side == 0 && data->ray.rayDirX > 0)
			texX = 64.0 - texX - 1;
		if (data->ray.side == 1 && data->ray.rayDirY < 0)
			texX = 64.0 - texX - 1;	
		
		// float step = 1.0 * data->tex->wall_no->tex_height / data->tex->wall_no->tex_width;
		// float texPos = (drawstart - LENGTH / 2 + lineHeight / 2) * step;

		int d = 0;
		while (d < LENGTH)
		{
			if (d <= drawstart)
				img_pix_put(&data->img, x, d, data->map->floor_color);
			if (d >= drawend)
				img_pix_put(&data->img, x, d, data->map->ceiling_color);
			// int texy = (int)data->tex->wall_no->tex_height / lineHeight;
			// texPos = texPos + step;
			
			// // printf("tex x%d , texy %d\n", texX, texy);
			// if (data->ray.side == 0)
			// 	img_pix_put(&data->img, x , d, (int)data->tex->wall_no->addr[data->tex->wall_no->tex_height * texX + texy]);
			d++;
		}

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