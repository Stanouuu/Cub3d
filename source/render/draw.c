/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:45 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/06 15:19:02 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	img_pix_put(t_imge *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	draw_map(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			data->img.data[y * WIDTH + x] = data->maptmp[y][x];
			x++;
		}
		y++;	
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0 , 0);
}

void	calc(t_data *data)
{
	int x;
	int i;
	int y;

	i = 0;
	y = 0;
	x = 0;
	if (data->player.re_buf == 1)
	{
		while (i < HEIGHT)
		{
			while (y < WIDTH)
			{
				data->bufbuf[i][y] = 0;
				y++;
			}
			i++;
		}
	}
	while (x < WIDTH)
	{
		float cameraX = 2 * x / (float)WIDTH - 1;
		float rayDirX = data->player.dirX + data->player.planeX * cameraX;
		float rayDirY = data->player.dirY + data->player.planeY * cameraX;

		int mapX = (int)data->player.posX;
		int mapY = (int)data->player.posY;

		float sideDistX;
		float sideDistY;

		float deltaDistX = fabs(1 / rayDirX);
		float deltaDistY = fabs(1 / rayDirY);
		float perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->player.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->player.posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->player.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->player.posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX = sideDistX + deltaDistX;
				mapX = mapX + stepX;
				side = 0;
			}
			else
			{
				sideDistY = sideDistY + deltaDistY;
				mapY = mapY + stepY;
				side = 1;
			}
			if (data->maptmp[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - data->player.posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - data->player.posY + (1 - stepY) / 2) / rayDirY;
		
		int lineHeight = (int)(HEIGHT / perpWallDist);

		int drawstart = -lineHeight / 2 + HEIGHT / 2;
		if (drawstart < 0)
			drawstart = 0;
		int drawend = lineHeight / 2 + HEIGHT / 2;
		if (drawend >= HEIGHT)
			drawend = HEIGHT - 1;
		
		int texNum = data->maptmp[mapX][mapY];

		float wallX;
		if (side == 0)
			wallX = data->player.posY + perpWallDist * rayDirX;
		else
			wallX = data->player.posX + perpWallDist * rayDirY;
		wallX = wallX - floor(wallX);

		int texX = (int)(wallX * (float)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;
		
		float step = 1.0 * texHeight / lineHeight;

		float texPos = (drawstart - HEIGHT / 2 + lineHeight / 2) * step;

		y = drawstart;
		while (y < drawend)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos = texPos + step;
			int color = data->player.texture[texNum][texHeight * texY + texX];

			if (side == 1)
				color = (color >> 1) & 8355711;
			data->bufbuf[y][x] = color;
			data->player.re_buf = 1;
		}
		x++;
	}
}

int loop_loop(t_data *data)
{
	calc(data);
	draw_map(data);
	return (0); 
}