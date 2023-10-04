/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:50:29 by stan              #+#    #+#             */
/*   Updated: 2023/10/03 13:55:42 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char *basic_check(char **argv, int argc)
{
	int i;

	if (argc != 2)
		return (NULL);
	// printf("sucess\n");
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(argv[1] + i, ".cub", 5) != 0)
		return (NULL);
	// printf("sucess 2\n");
	return (argv[1]);
}

t_map *parse_central(char **argv, int argc, t_data *data)
{
	char	*map_name;

	map_name = basic_check(argv, argc);
	if (map_name == NULL)
		return (NULL);
	// printf("sucess 3\n");
	data->map = info_extract(map_name);
	// if (data->map == NULL)
	// 	write(1, "sucess 1\n", 9);
	// printf("sucess 4\n");
	// write(1, "sucess 5 \n", 10);
	return (data->map);
}
