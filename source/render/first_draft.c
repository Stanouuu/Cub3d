/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_draft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:57:55 by nklingsh          #+#    #+#             */
/*   Updated: 2023/10/04 17:56:25 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"

void init_data(t_data *data)
{
	data->player2.posX = 22;
	data->player2.posY = 12;
	data->player2.dirX = -1;
	data->player2.dirY = 0;
	data->player2.planeX = 0;
	data->player2.planeY = 0.66;
	data->player2.math.camera = 0;
	data->player2.math.rayDirx = 0;
	data->player2.math.rayDiry = 0;
	data->map.map_width = 1000;
	data->map.map_lenght = 1000;
}
void raycasting(t_data *data)
{
	int x;

	x = 0;
	while (x < data->map.map_width)
	{
		data->player2.math.camera = (2 * x) / (float)data->.mapmap_width - 1;
		data->player2.math.rayDirx = data->player2.dirX + data->player2.planeX * data->player2.math.camera;
		data->player2.math.rayDiry = data->player2.dirY + data->player2.planeY * data->player2.math.camera; 
		dda_algorithm(data);
		
	}
}

void dda_algorithm(t_data *data)
{
	int mapX = (int)data->player2.posX;
	int mapY = (int)data->player2.posY;
	float sideDistX;
	float sideDistY;
	float deltaDistX;
	float deltaDistY;
	float perpWallDist;
	int stepx;
	int stepy;
	
	int hit = 0;
	int side;
	
	deltaDistX = sqrt(1 + (data->player2.math.rayDiry * data->player2.math.rayDiry) / (data->player2.math.rayDirx * data->player2.math.rayDirx));
	deltaDistY = sqrt(1 + (data->player2.math.rayDirx * data->player2.math.rayDirx) / (data->player2.math.rayDiry * data->player2.math.rayDiry));

	if (data->player2.math.rayDirx < 0)
	{
		stepx = -1;
		sideDistX = (data->player2.posX - mapX) * deltaDistX;
	}
	else
	{
		stepx = 1;
		sideDistX = (mapX + 1 - data->player2.posX) * deltaDistX;
	}
	if (data->player2.math.rayDiry < 0)
	{
		stepy = -1;
		sideDistY = ( data->player2.posY - mapY) * deltaDistY;
	}
	else
	{
		stepy = 1;
		sideDistY = (mapY + 1 - data->player2.posY) * deltaDistY;
	}
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX = sideDistX + deltaDistX;
			mapX = mapX + stepx;
			side = 0;
		}
		else
		{
			sideDistY = sideDistY + deltaDistY;
			mapY = mapY + stepy;
			side = 1;
		}
		if (data->maptmp[mapX][mapY] > 0)
			hit = 1;
	}
	if (side == 0)
		perpWallDist = (sideDistX - sideDistY);
	else
		perpWallDist = (sideDistY - sideDistX);
	int h = 250;
	int line_height = (int) (h / perpWallDist);
	
	int drawstart =- line_height / 2 + h / 2;
	if (drawstart < 0)
		drawstart = 0;
	int drawend =- line_height / 2 + h / 2;
	if (drawend >= h)
		drawend = h - 1;
	
}



