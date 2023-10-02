/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:29:31 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/02 16:58:34 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fill_map(char **file, t_map *map)
{
	int	i;
	int	h;
	int	j;

	i = 0;
	h = 0;
	while (file[i] && check_number(file[i]) == 0)
		i++;
	while (map->map_lenght > h)
	{
		j = 0;
		while (map->map_width > j)
		{
			if (file[i][j] == 0)
			{
				while (map->map_width > j)
				{
					map->map[h][j] = 2;
					j++;
				}
				j--;
			}
			else if (file[i][j] == '0')
				map->map[h][j] = 0;
			else if (file[i][j] == ' ' || (file[i][j] <= 13 && file[i][j] >= 9))
				map->map[h][j] = 2;
			else if (file[i][j] == '1')
				map->map[h][j] = 1;
			j++;
		}
		i++;
		h++;
	}
}


int	extract_second_half(char **file, t_map *map)
{
	int s;
	
	s = check_map(file);
	if (s < 1)
		return (-1);
	map->map_lenght = s;
	map->map = malloc(sizeof(int *) * s);
	if (!map->map)
		return (-1);
	s = map_width(file);
	map->map_width = s;
	s = 0;
	while (map->map_lenght > s)
	{
		map->map[s] = malloc(sizeof(int ) * map->map_width);
		s++;
	}
	fill_map(file, map);
	return (1);
}
