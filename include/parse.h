/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:02:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/02 16:33:00 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "cube.h"

int		is_rgb(char *str);
int		nbr_lines(char *map_name);
int		check_number(char *line);
int		check_first_half(char **file);
int		correct_order(char *name, int i);
t_map	*info_extract(char *map_name);
t_map 	*parse_central(char **argv, int argc, t_data *data);
int		extract_second_half(char **file, t_map *map);
int		check_map(char **file);
int		size_compar(char *line, int j);
int		map_width(char **file);

#endif
