/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:47:13 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 15:49:37 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_mat(void **tab, int l)
{
	int	i;

	i = 0;
	if (l < 0)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	else
	{
		while (l > i)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	tab = NULL;
}

void	ft_exit_map(t_map *map)
{
	if (map->map)
		free_mat((void **)map->map, map->map_lenght);
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->east)
		free(map->east);
	if (map->west)
		free(map->west);
	free(map);
}

void	ft_exit_tex(t_data *data)
{
	if (data->tex->wall_no.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->tex->wall_no.mlx_img);
	if (data->tex->wall_so.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->tex->wall_so.mlx_img);
	if (data->tex->wall_we.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->tex->wall_we.mlx_img);
	if (data->tex->wall_ea.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->tex->wall_ea.mlx_img);
}

void	ft_exit_data(t_data *data)
{
	if (data->map)
		ft_exit_map(data->map);
	if (data->tex)
	{
		ft_exit_tex(data);
		usleep(100);
		free(data->tex);
	}
}

void	ft_exit(t_data *data)
{
	if (data)
		ft_exit_data(data);
	exit_mlx(data);
}
