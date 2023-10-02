/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:45:20 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/02 14:45:35 by sbarrage         ###   ########.fr       */
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