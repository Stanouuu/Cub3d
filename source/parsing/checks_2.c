/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:20 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/03 14:11:40 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_map(char **file)
{
	int i;
	int	j;

	i = 0;
	while (file[i] && check_number(file[i]) == 0)
		i++;
	if (!file[i])
		return (-1);
	j = i;
	while (file[i] && check_number(file[i]) == 1)
		i++;
	if (!file[i])
	{
		return (i - j);
	}
	return (-2);
}

int	size_compar(char *line, int j)
{
	int i;

	i = 0;
	while (line[i] == ' ' || (line[i] <= 13 && line[i] >= 9))
		i++;
	while (line[i] && ft_isdigit(line[i]) == 1)
		i++;
	if (i > j)
		return (i);
	return (j);
}

int	map_width(char **file)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (file[i] && check_number(file[i]) == 0)
		i++;
	while (file[i])
		j = size_compar(file[i++], j);
	return (j);
}

int arround(int i, int j, int **map)
{
	int x;
	int y;

	x = -1;
	if (map[i][j] != 0)
		return (1);
	while (x < 2)
	{
		y = -1;
		while (y < 2)
		{
			if (map[i + x][j + y] == 2)
				return (-1);
			y++;
		}
		x++;
	}
	return (1);
}

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

int check_lenght(int i, int j, t_map *map)
{
	while (i != map->map_lenght)
	{
		if (map->map[i][j] == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i != map->map_lenght)
	{
		if (map->map[i][map->map_width - 1] == 0)
			return (-2);
		i++;
	}
	return (1);
}

int map_check(t_map *map)
{
	int	i;
	int j;

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
