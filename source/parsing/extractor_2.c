/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:29:31 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/17 11:22:47 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_info_extract(char direction, t_player *player, int x, int y)
{
	if (direction == 'N')
	{
		player->dirX = 0;
		player->dirY = 1;
	}
	else if (direction == 'S')
	{
		player->dirX = 0;
		player->dirY = -1;
	}
	else if (direction == 'E')
	{
		player->dirX = -1;
		player->dirY = 0;
	}
	else if (direction == 'W')
	{
		player->dirX = 1;
		player->dirY = 0;
	}
	else
		return ;
	player->y = y;
	player->x = x;
}

void	fill_map_3(char *file, t_map *map, int h, t_data *data)
{
	int	j;

	j = 0;
	while (map->map_width > j)
	{
		if (file[j] == 0)
		{
			while (map->map_width > j)
				map->map[h][j++] = 2;
		}
		else if (file[j] == '0')
			map->map[h][j++] = 0;
		else if (file[j] == ' ' || (file[j] <= 13 && file[j] >= 9))
			map->map[h][j++] = 2;
		else if (file[j] == '1')
			map->map[h][j++] = 1;
		else
		{
			player_info_extract(file[j], &(data->player), h, j);
			map->map[h][j++] = 0;
		}
	}
}

int	fill_map_2(t_map *map, char **file, int i, t_data *data)
{
	int	h;

	h = 0;
	while (map->map_lenght > h)
	{
		fill_map_3(file[i], map, h, data);
		i++;
		h++;
	}
	if (data->player.y == -1)
		return (-1);
	return (1);
}

int	fill_map(char **file, t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (file[i] && check_number(file[i]) == 0)
		i++;
	if (fill_map_2(map, file, i, data) < 0)
		return (-1);
	return (1);
}

int	extract_second_half(char **file, t_map *map, t_data *data)
{
	int	s;

	s = check_map(file);
	if (s < 1)
		return (-1);
	map->map_lenght = s;
	map->map = malloc(sizeof(int *) * s);
	if (!map->map)
		return (-2);
	s = map_width(file);
	map->map_width = s;
	s = 0;
	while (map->map_lenght > s)
	{
		map->map[s] = malloc(sizeof(int ) * map->map_width);
		if (!map->map[s])
			return (map->map_lenght = s, -3);
		s++;
	}
	if (fill_map(file, map, data) < 0)
		return (-4);
	return (1);
}
