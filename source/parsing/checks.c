/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:32:26 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 13:57:40 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	i = ft_atoi(str);
	if (i > 255 || i < 0)
		return (-1);
	return (i);
}

int	nbr_lines(char *map_name)
{
	int		fd;
	int		count;
	char	*str;

	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

int	check_number(char *line)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(line[i]) == 0)
		i++;
	if (ft_isdigit(line[i]) == 1)
		return (1);
	return (0);
}

int	check_first_half(char **file)
{
	int	i;
	int	j;
	int	s;

	j = 0;
	i = 0;
	s = 0;
	while (file[i] && check_number(file[i]) == 0)
	{
		j = 0;
		while (file[i][j] && ft_iswhitespace(file[i][j]) == 0)
			j++;
		if (file[i][j] && ft_iswhitespace(file[i][j]) == 1)
			s++;
		i++;
	}
	return (s);
}

int	correct_order(char *name, int i)
{
	if ((ft_strncmp("NO ", name, 3) == 0) && i == 0)
		return (1);
	if ((ft_strncmp("SO ", name, 3) == 0) && i == 1)
		return (2);
	if ((ft_strncmp("WE ", name, 3) == 0) && i == 2)
		return (3);
	if ((ft_strncmp("EA ", name, 3) == 0) && i == 3)
		return (4);
	if ((ft_strncmp("F ", name, 2) == 0) && i == 4)
		return (5);
	if ((ft_strncmp("C ", name, 2) == 0) && i == 5)
		return (6);
	return (-1);
}
