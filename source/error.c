/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:32:59 by stan              #+#    #+#             */
/*   Updated: 2023/10/18 15:49:18 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_error(t_map *map, t_data *data, char *str)
{
	exit_mlx(data);
	if (map)
		ft_exit_map(map);
	if (data)
		ft_exit_data(data);
	if (errno == ENOMEM || errno == ENOENT
		|| errno == EACCES || errno == EISDIR)
	{
		write(2, "Error\n", 7);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
	else if (str)
	{
		write(2, "Error\n", 7);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
}
