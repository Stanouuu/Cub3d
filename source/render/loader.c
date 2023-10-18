/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:43:40 by nklingsh          #+#    #+#             */
/*   Updated: 2023/10/18 14:42:59 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	load_north(t_data *data)
{
	data->tex->wall_no.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->north, \
	&data->tex->wall_no.tex_width, &data->tex->wall_no.tex_height);
	if (!data->tex->wall_no.mlx_img)
		return (-2);
	data->tex->wall_no.addr = mlx_get_data_addr(data->tex->wall_no.mlx_img, \
	&data->tex->wall_no.bpp , &data->tex->wall_no.line_len, &data->tex->wall_no.endian);
	return (0);
}

int	load_south(t_data *data)
{
	data->tex->wall_so.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->south, \
	&data->tex->wall_so.tex_width, &data->tex->wall_so.tex_height);
	if (!data->tex->wall_so.mlx_img)
		return (-2);
	data->tex->wall_so.addr = mlx_get_data_addr(data->tex->wall_so.mlx_img, \
	&data->tex->wall_so.bpp , &data->tex->wall_so.line_len, &data->tex->wall_so.endian);
	return (0);
}

int	load_west(t_data *data)
{
	data->tex->wall_we.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->west, \
	&data->tex->wall_we.tex_width, &data->tex->wall_we.tex_height);
	if (!data->tex->wall_we.mlx_img)
		return (-2);
	data->tex->wall_we.addr = mlx_get_data_addr(data->tex->wall_we.mlx_img, \
	&data->tex->wall_we.bpp, &data->tex->wall_we.line_len, &data->tex->wall_we.endian);
	return (0);
}

int	load_east(t_data *data)
{
	data->tex->wall_ea.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->map->east, \
	&data->tex->wall_ea.tex_width, &data->tex->wall_ea.tex_height);
	if (!data->tex->wall_ea.mlx_img)
		return (-2);
	data->tex->wall_ea.addr = mlx_get_data_addr(data->tex->wall_ea.mlx_img, &data->tex->wall_ea.bpp, \
	&data->tex->wall_ea.line_len, &data->tex->wall_ea.endian);
	return (0);
}

int init_tex(t_data *data)
{
	data->tex = malloc(sizeof(t_tex));
	data->tex->wall_no.mlx_img = NULL;
	data->tex->wall_so.mlx_img = NULL;
	data->tex->wall_we.mlx_img = NULL;
	data->tex->wall_ea.mlx_img = NULL;
	if (!data->tex)
		return (-1);
	if (load_north(data) < 0)
		return (-1);
	if (load_south(data) < 0)
		return (-2);
	if (load_west(data) < 0)
		return (-3);
	if (load_east(data) < 0)
		return (-4);
	return (0);
}