/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:47 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/21 15:04:58 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <math.h>
# include <X11/Xlib.h>
# include "mlx_int.h"
# include <stdlib.h>
# include "mlx.h"
# include "../source/gnl/get_next_line.h"
# include "libft.h"
# include <errno.h>
# include "mlx_basics.h"
# include "render.h"
# include "parse.h"

void	ft_error(t_map *map, t_data *data, char *str);
void	ft_exit(t_data *data);
void	free_mat(void **tab, int l);
void	player_info_2(char direction, t_player *player);
int		init_tex(t_data *data);
void	ft_exit_map(t_map *map);
void	init_sidedist(t_data *data);
void	position_map(t_data *data);
void	init_ray_calc(t_data *data);
void	update_dir(t_player *data, float x, float y, float a);
void	update_plane(t_player *data, float x, float y);
void	draw_pixel(t_data *data, int d, int x);
int		*load_good_tex(t_data *data);
void	ft_exit_data(t_data *data);

#endif
