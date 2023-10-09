/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:32:59 by stan              #+#    #+#             */
/*   Updated: 2023/10/09 11:51:22 by sbarrage         ###   ########.fr       */
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

void	ft_exit_data(t_data *data)
{
	if (data->maptmp)
		free_mat((void **)data->maptmp, -1);
	if (data->map)
		ft_exit_map(data->map);
}

void ft_error(char *str)
{
	printf("%s: %s\n", str, strerror(errno));
}

void ft_exit(t_data *data)
{
	exit_mlx(data);
	if (data)
		ft_exit_data(data);
}
