/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:07:23 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/09 12:48:54 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_width(int i, int j, t_map *map)
{
	while (j != map->map_width)
	{
		if (map->map[i][j] == 0)
			return (-1);
		j++;
	}
	j = 0;
	while (j != map->map_width)
	{
		if (map->map[map->map_lenght - 1][j] == 0)
			return (-2);
		j++;
	}
	return (1);
}

int	check_lenght(int i, int j, t_map *map)
{
	while (i != map->map_lenght - 1)
	{
		if (map->map[i][j] == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i != map->map_lenght - 1)
	{
		if (map->map[i][map->map_width - 1] == 0)
			return (-2);
		i++;
	}
	return (1);
}

int	map_check(t_map *map)
{
	int	i;
	int	j;

	if (check_width(0, 0, map) < 0)
		return (-1);
	if (check_lenght(0, 0, map) < 0)
		return (-2);
	i = 1;
	while (i < map->map_lenght - 1)
	{
		j = 1;
		while (j < map->map_width - 1)
		{
			if (arround(i, j, map->map) == -1)
				return (-5);
			j++;
		}
		i++;
	}
	return (1);
}
