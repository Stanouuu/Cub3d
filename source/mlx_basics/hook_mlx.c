/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:58 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/22 22:00:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define MOVESPEED 0.05
#define ROTSPEED 0.05

int	handle_input(int keysym, t_data *data)
{
	float olddirX;
	float oldPlaneX;

	olddirX = 0;
	oldPlaneX = 0;
	if (keysym == XK_w)
	{
		if (!data->bufbuf[(int)(data->player.posX + data->player.dirX * MOVESPEED)][(int)data->player.posY])
			data->player.posX = data->player.posX + data->player.dirX * MOVESPEED;
		if (!data->bufbuf[(int)(data->player.posX)][(int)(data->player.posY + data->player.dirY * MOVESPEED)])
			data->player.posY = data->player.posY + data->player.dirY * MOVESPEED;
	}
	if (keysym == XK_s)
	{
		if (!data->bufbuf[(int)(data->player.posX - data->player.dirX * MOVESPEED)][(int)data->player.posY])
			data->player.posX = data->player.posX - data->player.dirX * MOVESPEED;
		if (!data->bufbuf[(int)(data->player.posX)][(int)(data->player.posY - data->player.dirY * MOVESPEED)])
			data->player.posY = data->player.posY - data->player.dirY * MOVESPEED;
	}
	if (keysym == XK_d)
	{
		olddirX = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(-ROTSPEED) - data->player.dirY * sin(-ROTSPEED);
		data->player.dirY = olddirX * sin(-ROTSPEED) + data->player.dirY * cos(-ROTSPEED);
		oldPlaneX = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-ROTSPEED) - data->player.planeY * sin(-ROTSPEED);
		data->player.planeY = oldPlaneX * sin(-ROTSPEED) + data->player.planeY * cos(-ROTSPEED);
	}
	if (keysym == XK_a)
	{
		olddirX = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(ROTSPEED) - data->player.dirY * sin(ROTSPEED);
		data->player.dirY = olddirX * sin(ROTSPEED) + data->player.dirY * cos(ROTSPEED);
		oldPlaneX = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(ROTSPEED) - data->player.planeY * sin(ROTSPEED);
		data->player.planeY = oldPlaneX * sin(ROTSPEED) + data->player.planeY * cos(ROTSPEED);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	loop_loop(data);
	return (0);
}

void load_image(t_data *data, int *texture, char *path, t_imge *img)
{
	int y;
	int x;

	x = 0;
	y = 0;
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->mlx_img, &img->bpp, &img->size, &img->endian);
	while (y < img->img_h)
	{
		while (x < img->img_w)
		{
			texture[img->img_w * y + x] = img->data[img->img_w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_ptr, img->mlx_img);
}

void load_texture(t_data *data)
{
	t_imge img;

	load_image(data, data->player.texture[0], "../textures/dia.xpm", &img);
	load_image(data, data->player.texture[0], "../textures/dirt.xpm", &img);
}

