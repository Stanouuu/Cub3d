/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:18:54 by stan              #+#    #+#             */
/*   Updated: 2023/09/25 18:10:50 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int nbr_lines(char *map_name)
{
	int fd;
	int count;

	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

char **extract_file(char *map_name)
{
	char **file;
	int fd;
	int i;

	i = nbr_lines(map_name);
	if (i == -1)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (1);
	file = malloc(sizeof(char *) * (i + 1));
	if (!file)
		return (NULL);
	i = 0;
	file[i] = get_next_line(fd);
	while (file[i])
		file[++i] = get_next_line(fd);
	return (file);
}

int check_number(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || (line[i] <= 13 && line[i] >= 9))
		i++;
	if (ft_isdigit(line[i]) == 1)
		return (1);
	return (0);
}

int	check_first_half(char **file)
{
	int i;
	int	s;

	i = 0;
	s = 0;
	while (file[i] && check_number(file[i]) == 1)
	{
		if (ft_strncmp(file[i], "NO ", 3))
			s++;
		if (ft_strncmp(file[i], "SO ", 3))
			s++;
		if (ft_strncmp(file[i], "WE ", 3))
			s++;
		if (ft_strncmp(file[i], "EA ", 3))
			s++;
		if (ft_strncmp(file[i], "F ", 2))
			s++;
		if (ft_strncmp(file[i], "C ", 2))
			s++;
	}
	return (s);
}

char *find_blank_dir(char **file, char *dir, int s)
{
	int 	i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (file[i] && ft_strncmp(file[i], dir, 3) != 0)
	{
		if (check_number(file[i++]) == 1)
			return (NULL);
	}
	if (s == 1)
		return (file[i] + 2);
	if (!file[i])
		return (NULL);
	while (file[i][j] != "." && file[i][j + 1] != "/")
	{
		if (!file[i][j])
			return (NULL);
		j++;
	}
	return (file[i] + (j - 1));
}

int	rgb_to_hex(char *str)
{

}

t_map *extract_first_half(char **file)
{
	t_map map;

	if (check_first_half(file) != 6)
		return (NULL);
	map.north = find_blank_dir(file, "NO ", 0);
	if (!map.north)
		return (NULL);
	map.south = find_blank_dir(file, "SO ", 0);
	if (!map.south)
		return (NULL);
	map.west = find_blank_dir(file, "WE ", 0);
	if (!map.west)
		return (NULL);
	map.east = find_blank_dir(file, "EA ", 0);
	if (!map.east)
		return (NULL);
	map.east = find_blank_dir(file, "C ", 1);
	if (!map.east)
		return (NULL);
	map.east = find_blank_dir(file, "F ", 1);
	if (!map.east)
		return (NULL);
}

t_map *info_extract(char *map_name)
{
	char 	**file;
	t_map	*map;

	file = extract_file(map_name);
	if (!file)
		return (NULL);
	map = extract_first_half(file);
}
