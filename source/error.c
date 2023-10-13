/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:32:59 by stan              #+#    #+#             */
/*   Updated: 2023/10/13 16:31:34 by sbarrage         ###   ########.fr       */
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
}

void	ft_exit_map(t_map *map)
{
	if (map->map)
		free_mat((void **)map->map,  map->map_lenght);
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
	if (data->tex->wall_no)
	{
		// if (data->tex->wall_no->mlx_img)
		// {
		// 	mlx_destroy_image(data->mlx_ptr, data->tex->wall_no->mlx_img);
		// 	data->tex->wall_no->mlx_img = NULL;
		// }
		free(data->tex->wall_no);
	}
	if (data->tex->wall_so)
	{
		// if (data->tex->wall_so->mlx_img)
		// {
		// 	mlx_destroy_image(data->mlx_ptr, data->tex->wall_so->mlx_img);
		// 	data->tex->wall_so->mlx_img = NULL;
		// }
		free(data->tex->wall_so);
	}
	if (data->tex->wall_we)
	{
		// if (data->tex->wall_we->mlx_img)
		// {
		// 	mlx_destroy_image(data->mlx_ptr, data->tex->wall_we->mlx_img);
		// 	data->tex->wall_we->mlx_img = NULL;
		// }
		free(data->tex->wall_we);
	}
	if (data->tex->wall_ea)
	{
		// if (data->tex->wall_ea->mlx_img)
		// {
		// 	mlx_destroy_image(data->mlx_ptr, data->tex->wall_ea->mlx_img);
		// 	data->tex->wall_ea->mlx_img = NULL;
		// }
		free(data->tex->wall_ea);
	}
	free(data->tex);
}

void	ft_exit_data(t_data *data)
{
	if (data->map)
		ft_exit_map(data->map);
	if (data->tex)
		ft_exit_tex(data);
}

void ft_exit(t_data *data)
{
	exit_mlx(data);
	if (data)
		ft_exit_data(data);
}

void ft_error(t_map *map, t_data *data, char *str)
{
	exit_mlx(data);
	if (map)
		ft_exit_map(map);
	if (data)
		ft_exit_data(data);
	if (errno == ENOMEM || errno == ENOENT || errno == EACCES || errno == EISDIR)
		printf("Cube: %s\n", strerror(errno));
	else if (str)
		printf ("Cube: %s\n", str);
}

