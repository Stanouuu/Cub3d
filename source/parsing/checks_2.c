/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:20 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 14:04:20 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_map(char **file)
{
	int	i;
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
		return (i - j);
	return (-2);
}

int	size_compar(char *line, int j)
{
	int	i;

	i = 0;
	while (line[i] || line[i] == ' ' || (line[i] <= 13 && line[i] >= 9)
		|| ft_isdigit(line[i]) == 1)
		i++;
	if (line[i])
		return (-1);
	if (i > j)
		return (i);
	return (j);
}

int	map_width(char **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i] && check_number(file[i]) == 0)
		i++;
	while (file[i])
		j = size_compar(file[i++], j);
	return (j);
}

int	arround(int i, int j, int **map)
{
	int	x;
	int	y;

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
