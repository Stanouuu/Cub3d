/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:18:54 by stan              #+#    #+#             */
/*   Updated: 2023/10/21 14:02:16 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"	

char	*reformat(char *str)
{
	char	*res;
	int		j;

	j = 0;
	while (!(str[j] == ' ' || (str[j] <= 13 && str[j] >= 9)))
		j++;
	res = malloc(sizeof(char) * (j + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, j + 1);
	return (res);
}

/* 	// if (correct_order(dir, j) < 0)
	// 	return (NULL); */

char	*find_blank_dir(char **file, char *dir, int s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i] && ft_strncmp(file[i], dir, s) != 0)
	{
		if (ft_isalpha(*(file[i])) == 1)
			j++;
		if (check_number(file[i++]) == 1)
			return (NULL);
	}
	if (s == 2)
		return (file[i] + 2);
	if (!file[i] || !file[i][j])
		return (NULL);
	while (file[i][j] != '.' && file[i][j + 1] != '/')
	{
		if (!(file[i][j + 1]))
			return (NULL);
		j++;
	}
	return (reformat((file[i]) + j));
}

int	str_to_hex(char *str)
{
	char	**nbrs;
	int		rgb[3];
	int		i;

	i = 0;
	if (!str)
		return (-1);
	nbrs = ft_split(str, ',');
	if (!nbrs)
		return (-1);
	while (nbrs[i])
		i++;
	if (i != 3)
		return (free_mat((void **)nbrs, -1), -1);
	while (i != 0)
	{
		i--;
		rgb[i] = is_rgb(nbrs[i]);
		if (rgb[i] == -1)
			return (free_mat((void **)nbrs, -1), -1);
	}
	free_mat((void **)nbrs, -1);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	extract_first_half(char **file, t_map *map)
{
	if (check_first_half(file) != 6)
		return (-1);
	map->north = find_blank_dir(file, "NO ", 3);
	if (!map->north)
		return (-2);
	map->south = find_blank_dir(file, "SO ", 3);
	if (!map->south)
		return (-3);
	map->west = find_blank_dir(file, "WE ", 3);
	if (!map->west)
		return (-4);
	map->east = find_blank_dir(file, "EA ", 3);
	if (!map->east)
		return (-5);
	map->floor_color = str_to_hex(find_blank_dir(file, "F ", 2));
	if (map->floor_color == -1)
		return (-6);
	map->ceiling_color = str_to_hex(find_blank_dir(file, "C ", 2));
	if (map->ceiling_color == -1)
		return (-7);
	return (0);
}

t_map	*info_extract(char *map_name, t_data *data)
{
	char	**file;
	t_map	*map;

	file = extract_file(map_name);
	if (!file)
		return (ft_error(NULL, data, "error extracting file"), NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_error(NULL, data, NULL), free_mat((void **)file, -1), NULL);
	map->east = NULL;
	map->west = NULL;
	map->south = NULL;
	map->north = NULL;
	map->map = NULL;
	if (extract_first_half(file, map) < 0)
		return (ft_error(map, data, "incorrect information"),
			free_mat((void **)file, -1), NULL);
	if (extract_second_half(file, map, data) < 0 || map_check(map) < 0)
	{
		ft_error(map, data, "incorrect map");
		return (free_mat((void **)file, -1), NULL);
	}
	free_mat((void **)file, -1);
	return (map);
}
