/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:29:31 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 15:16:02 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	player_info_extract(char direction, t_player *player, int x, int y)
{
	if (direction == 'N' || direction == 'S')
	{
		update_dir(player, 1, 0);
		update_plane(player, 0, -0.66);
	}
	else if (direction == 'N')
	{
		update_dir(player, -1, 0);
		update_plane(player, 0, 0.66);
	}
	else if (direction == 'E')
	{
		update_dir(player, 0, 1);
		update_plane(player, 0.66, 0);
	}
	else if (direction == 'W' || direction == 'E')
	{
		update_dir(player, 0, -1);
		update_plane(player, 0.66, 0);
	}
	else
		player->y = -2;
	if (player->y == -1)
	{
		player->y = y + 0.5;
		player->x = x + 0.5;
	}
	else
		player->y = -2;
}

void	fill_map_3(char *file, t_map *map, int h, t_data *data)
{
	int	j;

	j = 0;
	while (map->map_width > j)
	{
		if (file[j] == 0)
			while (map->map_width > j)
				map->map[h][j++] = 2;
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
	if (data->player.y < 0)
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
	if (s < 0)
		return (-3);
	map->map_width = s;
	s = 0;
	while (map->map_lenght > s)
	{
		map->map[s] = malloc(sizeof(int ) * map->map_width);
		if (!map->map[s])
			return (map->map_lenght = s, -4);
		s++;
	}
	if (fill_map(file, map, data) < 0)
		return (-5);
	return (1);
}
