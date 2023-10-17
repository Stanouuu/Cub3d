/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_crtl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:27:48 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/16 18:50:04 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
//add floor ceiling


void load_north(t_data *data)
{
	data->tex->wall_no = malloc(sizeof(t_imge));
	data->tex->wall_no->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->north, &data->tex->wall_no->tex_width, &data->tex->wall_no->tex_height);
	// exit(0);
	data->tex->wall_no->addr = mlx_get_data_addr(data->tex->wall_no->mlx_img, &data->tex->wall_no->bpp , &data->tex->wall_no->line_len, &data->tex->wall_no->endian);
}

void load_south(t_data *data)
{
	data->tex->wall_so = malloc(sizeof(t_imge));
	data->tex->wall_so->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->south, &data->tex->wall_so->tex_width, &data->tex->wall_so->tex_height);
	data->tex->wall_so->addr = mlx_get_data_addr(data->tex->wall_so->mlx_img, &data->tex->wall_so->bpp , &data->tex->wall_so->line_len, &data->tex->wall_so->endian);
}

void load_west(t_data *data)
{
	data->tex->wall_we = malloc(sizeof(t_imge));

	data->tex->wall_we->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->west, &data->tex->wall_we->tex_width, &data->tex->wall_we->tex_height);
	data->tex->wall_we->addr = mlx_get_data_addr(data->tex->wall_we->mlx_img, &data->tex->wall_we->bpp , &data->tex->wall_we->line_len, &data->tex->wall_we->endian);
}

void load_east(t_data *data)
{
	data->tex->wall_ea = malloc(sizeof(t_imge));
	data->tex->wall_ea->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->east, &data->tex->wall_ea->tex_width, &data->tex->wall_ea->tex_height);
	data->tex->wall_ea->addr = mlx_get_data_addr(data->tex->wall_ea->mlx_img, &data->tex->wall_ea->bpp , &data->tex->wall_ea->line_len, &data->tex->wall_ea->endian);
}

void init_tex(t_data *data)
{
	data->tex = malloc(sizeof(t_tex));
	load_north(data);
	load_south(data);
	load_west(data);
	load_east(data);
}

int *load_good_tex(t_data *data)
{
	if (data->ray.side == 1 && data->ray.rayDirY <= 0)
		return (int *)data->tex->wall_so->addr;
	if (data->ray.side == 1 && data->ray.rayDirY > 0)
		return (int *)data->tex->wall_no->addr;
	if (data->ray.side == 0 && data->ray.rayDirX <= 0)
		return (int *)data->tex->wall_ea->addr;
	else
		return (int *)data->tex->wall_we->addr;
}


void raycaster(t_data *data)
{

	for (int x = 0; x < WIDTH; x++)
	{
		data->ray.camerax = x / (float)WIDTH * 2 - 1;
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
			if (data->map->map[data->ray.mapx][data->ray.mapy] == 1)
				data->ray.hit = 1;
		}
		if (data->ray.side == 0)
			data->ray.perpWallDist = (data->ray.sideDistX - data->ray.deltadistX);	
		else
			data->ray.perpWallDist = (data->ray.sideDistY - data->ray.deltadistY);

		int lineHeight = LENGTH / data->ray.perpWallDist;

		int drawstart = -lineHeight / 2 + LENGTH / 2;
		if (drawstart < 0)
			drawstart = 0;
		int drawend = lineHeight / 2 + LENGTH / 2;
		if (drawend >= LENGTH)
			drawend = LENGTH - 1;

		float wallX;
		// printf("%d side, ray dir x : %f, ray dir y  : %f\n", data->ray.side, data->ray.rayDirX, data->ray.rayDirY);
		if (data->ray.side == 1)
			wallX = data->player.x + data->ray.perpWallDist * data->ray.rayDirX;
		else
			wallX = data->player.y + data->ray.perpWallDist * data->ray.rayDirY;
		wallX -= (int)wallX;
		wallX = 1.0f - wallX;
		if ((data->ray.side == 1 && ((data->ray.rayDirY) > 0)) || (data->ray.side == 0 && (data->ray.rayDirX <= 0)))
			wallX = 1.0f - wallX;
		int texX = (int)(wallX * (float) 64.0);
	
		float step = 1.0 * data->tex->wall_no->tex_height / data->tex->wall_no->tex_width;
		float texPos = (drawstart - LENGTH / 2 + lineHeight / 2) * step;
		int d = 0;
		while (d < LENGTH)
		{
			int *stock_int = load_good_tex(data);
			int texy = ((float)(d - drawstart) / (float)(drawend - drawstart)) * data->tex->wall_no->tex_height;
			texPos = texPos + step;
			if (d < drawstart)
				img_pix_put(&data->img, x, d, data->map->floor_color);
			else if (d > drawend)
				img_pix_put(&data->img, x, d, data->map->ceiling_color);
			else //(data->ray.side == 0)
				img_pix_put(&data->img, x , d, stock_int[data->tex->wall_no->tex_width * texy + texX]);
			d++;
		}

	}
	

}

void ray_caster_try_2(t_data *data)
{
	float ffov = 3.14159f / 4.0f;
	float fDepth = 16.0f;
	// float fSpeed = 5.0f;	

	for (int x = 0; x < WIDTH; x++)
	{
			float fRayAngle = (data->player.a - ffov / 2.0f) + ((float)x / (float)WIDTH) * ffov;

			// Find distance to wall
			float fStepSize = 0.01f;	  // Increment size for ray casting, decrease to increase	
			float fDistanceToWall = 0.0f; //                                      resolution

			int bHitWall = 0;		// Set when ray hits wall block
			// int bBoundary = 0;		// Set when ray hits boundary between two wall blocks

			float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
			float fEyeY = cosf(fRayAngle);

			// float fSampleX = 0.0f;

			// int bLit = 0;

			// Incrementally cast ray from player, along ray angle, testing for 
			// intersection with a block
			while (!bHitWall && fDistanceToWall < fDepth)
			{
				fDistanceToWall += fStepSize;
				int nTestX = (int)(data->player.x + fEyeX * fDistanceToWall);
				int nTestY = (int)(data->player.y + fEyeY * fDistanceToWall);

				// Test if ray is out of bounds
				if (nTestX < 0 || nTestX >= data->map->map_width || nTestY < 0 || nTestY >= data->map->map_lenght)
				{
					bHitWall = 1;			// Just set distance to maximum depth
					fDistanceToWall = fDepth;
				}
			// 	else
			// 	{
			// 		// Ray is inbounds so test to see if the ray cell is a wall block
			// 		if (data->map->map[nTestX * data->map->map_width + nTestY] == 1)
			// 		{
			// 			// Ray has hit wall
			// 			bHitWall = 1;

			// 			// Determine where ray has hit wall. Break Block boundary
			// 			// int 4 line segments
			// 			float fBlockMidX = (float)nTestX + 0.5f;
			// 			float fBlockMidY = (float)nTestY + 0.5f;

			// 			float fTestPointX = data->player.x + fEyeX * fDistanceToWall;
			// 			float fTestPointY = data->player.y + fEyeY * fDistanceToWall;

			// 			float fTestAngle = atan2f((fTestPointY - fBlockMidY), (fTestPointX - fBlockMidX));

			// 			if (fTestAngle >= -3.14159f * 0.25f && fTestAngle < 3.14159f * 0.25f)
			// 				fSampleX = fTestPointY - (float)nTestY;
			// 			if (fTestAngle >= 3.14159f * 0.25f && fTestAngle < 3.14159f * 0.75f)
			// 				fSampleX = fTestPointX - (float)nTestX;
			// 			if (fTestAngle < -3.14159f * 0.25f && fTestAngle >= -3.14159f * 0.75f)
			// 				fSampleX = fTestPointX - (float)nTestX;
			// 			if (fTestAngle >= 3.14159f * 0.75f || fTestAngle < -3.14159f * 0.75f)
			// 				fSampleX = fTestPointY - (float)nTestY;
			// 		}
			// 	}
			}

			// Calculate distance to ceiling and floor
			int nCeiling = (float)(LENGTH / 2.0) - LENGTH / ((float)fDistanceToWall);
			// int nFloor = LENGTH - nCeiling;

			// Update Depth Buffer

			for (int y = 0; y < LENGTH; y++)
			{
				// Each Row
				if (y <= nCeiling)
					img_pix_put(&data->img, x, y, data->map->floor_color);
				// else if (y > nCeiling && y <= nFloor)
				// {
				// 	// Draw Wall
				// 	if (fDistanceToWall < fDepth)
				// 	{
				// 		float fSampleY = ((float)y - (float)nCeiling) / ((float)nFloor - (float)nCeiling);
				// 		// Draw(x, y, spriteWall->SampleGlyph(fSampleX, fSampleY), spriteWall->SampleColour(fSampleX, fSampleY));
				// 	}
				// 	else
				// 		Draw(x, y, PIXEL_SOLID, 0);
				// }
				else // Floor
				{
					img_pix_put(&data->img, x, y, data->map->ceiling_color);
				}
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