/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:02:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/09 12:08:59 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "cube.h"

/* Extract/Parse */

t_map	*info_extract(char *map_name, t_data *data);
t_map 	*parse_central(char **argv, int argc, t_data *data);
int		extract_second_half(char **file, t_map *map, t_data *data);
char	**extract_file(char *map_name);
int		size_compar(char *line, int j);

/* Czechs */

int		correct_order(char *name, int i);
int		is_rgb(char *str);
int		nbr_lines(char *map_name);
int		check_number(char *line);
int		check_first_half(char **file);
int		map_check(t_map *map);
int		check_map(char **file);
int		map_width(char **file);
int		arround(int i, int j, int **map);

#endif
