/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:50:29 by stan              #+#    #+#             */
/*   Updated: 2023/10/17 10:46:40 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*basic_check(char **argv, int argc)
{
	int	i;

	if (argc != 2)
		return (NULL);
	i = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(argv[1] + i, ".cub", 5) != 0)
		return (NULL);
	return (argv[1]);
}

t_map	*parse_central(char **argv, int argc, t_data *data)
{
	char	*map_name;

	data->player.a = 0;
	map_name = basic_check(argv, argc);
	if (map_name == NULL)
		return (ft_error(NULL, data, "incorrect Arguments"), NULL);
	data->map = info_extract(map_name, data);
	return (data->map);
}
