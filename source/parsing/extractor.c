/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:18:54 by stan              #+#    #+#             */
/*   Updated: 2023/10/03 13:48:54 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**extract_file(char *map_name)
{
	char	**file;
	int		fd;
	int		i;

	i = nbr_lines(map_name);
	if (i == -1)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file = malloc(sizeof(char *) * (i + 1));
	if (!file)
		return (NULL);
	i = 0;
	file[i] = get_next_line(fd);
	while (file[i])
		file[++i] = get_next_line(fd);
	return (file);
}

char	*find_blank_dir(char **file, char *dir, int s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i] && ft_strncmp(file[i], dir, s) != 0)
	{
		if (ft_isalpha(*(file[i])) == 1)
			j++;
		if (check_number(file[i++]) == 1)
			return (NULL);
	}
	if (correct_order(dir, j) < 0)
		return (NULL);
	if (s == 2)
		return (file[i] + 2);
	if (!file[i])
		return (NULL);
	while (file[i][j] != '.' && file[i][j + 1] != '/')
	{
		if (!file[i][j])
			return (NULL);
		j++;
	}
	return (file[i] + (j - 1));
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
	while (nbrs[i] && *(nbrs[i]))
		i++;
	if (i != 3)
	{
		while (i != 0)
			free(nbrs[--i]);
		return (-1);
	}
	while (i != 0)
	{
		i--;
		rgb[i] = is_rgb(nbrs[i]);
		if (rgb[i] == -1)
			return (-1);
	}
	free_mat((void **)nbrs, -1);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	extract_first_half(char **file, t_map *map)
{
	if (check_first_half(file) != 6)
		return (free(map), -1);
	map->north = find_blank_dir(file, "NO ", 3);
	if (!map->north)
		return (free(map), -2);
	map->south = find_blank_dir(file, "SO ", 3);
	if (!map->south)
		return (free(map), -3);
	map->west = find_blank_dir(file, "WE ", 3);
	if (!map->west)
		return (free(map), -4);
	map->east = find_blank_dir(file, "EA ", 3);
	if (!map->east)
		return (free(map), -5);
	map->floor_color = str_to_hex(find_blank_dir(file, "F ", 2));
	if (map->floor_color == -1)
		return (free(map), -6);
	map->ceiling_color = str_to_hex(find_blank_dir(file, "C ", 2));
	if (map->ceiling_color == -1)
		return (free(map), -7);
	return (0);
}

t_map	*info_extract(char *map_name)
{
	char	**file;
	t_map	*map;

	file = extract_file(map_name);
	if (!file)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (free_mat((void **)file, -1), NULL);
	if (extract_first_half(file, map) < 0)
		return (free_mat((void **)file, -1), NULL);
	// printf("%s\n", map->north);
	if (map)
	{
		printf("north : %s\n", map->north);
		printf("east  : %s\n", map->east);
		printf("west  : %s\n", map->west);
		printf("south : %s\n", map->south);
		printf("fcolor: %d\n", map->floor_color);
		printf("ccolor: %d\n", map->ceiling_color);
	}
	if (extract_second_half(file, map) < 0 || map_check(map) < 0)
		return (free_mat((void **)file, -1), NULL);
	return (free_mat((void **)file, -1), map);
}
