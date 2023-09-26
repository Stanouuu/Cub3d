/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:50:29 by stan              #+#    #+#             */
/*   Updated: 2023/09/23 16:29:31 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char *basic_check(char **argv, int argc)
{
	int i;

	if (argc != 2)
		return (NULL);
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(argv[1] + i, ".cub", 5) != 0)
		return (NULL);
	return (argv[1]);
}

int parse_central(char **argv, int argc)
{
	char	*map_name;
	int		fd;
	t_map	map;

	map_name = basic_check(argv, argc);
	if (map_name == NULL)
		return (1);
	info_extract(map_name);

}
