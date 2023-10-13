/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:08:35 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/12 17:27:06 by sbarrage         ###   ########.fr       */
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
