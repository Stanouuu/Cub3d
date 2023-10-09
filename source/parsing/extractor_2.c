/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:29:31 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/09 12:39:50 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_info_extract(int x, int y, char direction, t_player *player)
{
	player->x = x;
	player->y = y;
	if (direction == 'N')
		player->a = 0;
	else if (direction == 'S')
		player->a = 180;
	else if (direction == 'E')
		player->a = 90;
	else if (direction == 'W')
		player->a = 270;
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
			player_info_extract(h, j, file[j], &(data->player));
			map->map[h][j++] = 0;
		}
	}
}

void	fill_map_2(t_map *map, char **file, int i, t_data *data)
{
	int	h;

	h = 0;
	while (map->map_lenght > h)
	{
		fill_map_3(file[i], map, h, data);
		i++;
		h++;
	}
}

int	fill_map(char **file, t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (file[i] && check_number(file[i]) == 0)
		i++;
	fill_map_2(map, file, i, data);
	printf("t : %f\n", data->player.a);
	if (data->player.a < 0)
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
		s++;
	}
	if (fill_map(file, map, data) < 0)
		return (-3);
	return (1);
}
